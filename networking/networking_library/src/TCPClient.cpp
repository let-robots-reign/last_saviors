#include "TCPClient.h"

template<typename TClientLogic>
TCPClient<TClientLogic>::TCPClient() : m_logic(*this) {}

template<typename TClientLogic>
bool TCPClient<TClientLogic>::Connect(const Address & address) {
    bool result = m_socket.Connect(address);

    m_logic.OnConnect();
    return result;
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
TCPSocketClient & TCPClient<TClientLogic>::GetSocket() {
    return m_socket;
}

template<typename TClientLogic>
void TCPClient<TClientLogic>::Receive() {
    if (m_socket.HasData())
        m_buffer.Push(m_socket.Receive());
}

template<typename TClientLogic>
void TCPClient<TClientLogic>::Process() {
    m_logic.OnProcess();
}
