#include "TCPClient.h"

template<typename TClientLogic>
TCPClient<TClientLogic>::TCPClient() : m_logic(*this) {}

template<typename TClientLogic>
TCPClient<TClientLogic>::~TCPClient() {}

template<typename TClientLogic>
bool TCPClient<TClientLogic>::Connect(std::string_view address) {
    return Connect(*SocketAddress::Create(address));
}

template<typename TClientLogic>
bool TCPClient<TClientLogic>::Connect(SocketAddress address) {
    return Connect(address);
}

template<typename TClientLogic>
bool TCPClient<TClientLogic>::Connect(const uint32_t ip, const uint16_t port) {
    const SocketAddress address(ip, port);
    m_socket.Connect(address);
    
    m_logic.OnConnect();
    return true;
}

template<typename TClientLogic>
void TCPClient<TClientLogic>::Send(const std::vector<std::byte> & data) {
    m_logic.Send(data);
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
void TCPClient<TClientLogic>::Receive() {
    if (m_socket.HasData())
        m_buffer.Push(m_socket.Receive());
}

template<typename TClientLogic>
void TCPClient<TClientLogic>::Process() {
    m_logic.OnProcess();
}
