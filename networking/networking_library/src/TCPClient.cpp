#include "TCPClient.h"
#include "NetworkErrors.h"

template<typename TClientLogic>
TCPClient<TClientLogic>::TCPClient() : m_logic(*this) {}

template<typename TClientLogic>
bool TCPClient<TClientLogic>::Connect(const Address & address) {
    try {
        m_socket.Connect(address);
    }
    catch (const SocketError & error) {
        return false;
    }

    m_logic.OnConnect();
    return true;
}

template<typename TClientLogic>
void TCPClient<TClientLogic>::Send(const Packet & packet) {
    m_logic.Send(packet);
}

template<typename TClientLogic>
void TCPClient<TClientLogic>::Send(const std::vector<std::byte> & data) {
    m_socket.Send(data);
}

template<typename TClientLogic>
void TCPClient<TClientLogic>::ReceiveAndProcess() {
    Receive();
    Process();
}

template<typename TClientLogic>
void TCPClient<TClientLogic>::Disconnect() {
    m_socket.Disconnect();

    m_logic.OnDisconnect();
}

template<typename TClientLogic>
bool TCPClient<TClientLogic>::Connected() {
    return m_socket.Connected();
}

template<typename TClientLogic>
BinaryStream & TCPClient<TClientLogic>::GetBuffer() {
    return m_buffer;
}

template<typename TClientLogic>
void TCPClient<TClientLogic>::Receive() {
    m_buffer.Push(m_socket.Receive());
}

template<typename TClientLogic>
void TCPClient<TClientLogic>::Process() {
    m_logic.OnProcess();
}
