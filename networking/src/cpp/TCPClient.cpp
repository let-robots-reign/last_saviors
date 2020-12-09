#include "../TCPClient.h"

template<typename ClientLogic>
TCPClient<ClientLogic>::TCPClient() : m_logic(*this) {}

template<typename ClientLogic>
TCPClient<ClientLogic>::~TCPClient() {}

template<typename ClientLogic>
bool TCPClient<ClientLogic>::Connect(std::string_view address) {
    Connect(*SocketAddress::Create(address));
}

template<typename ClientLogic>
bool TCPClient<ClientLogic>::Connect(SocketAddress address) {
    Connect(address);
}

template<typename ClientLogic>
bool TCPClient<ClientLogic>::Connect(const uint32_t ip, const uint16_t port) {
    const SocketAddress address(ip, port);
    m_socket.Connect(address);
    
    OnConnect();
}

template<typename ClientLogic>
void TCPClient<ClientLogic>::ReceiveAndProcess() {
    Receive();
    Process();
}

template<typename ClientLogic>
void TCPClient<ClientLogic>::Disconnect() {
    m_socket.Disconnect();

    OnDisconnect();
}

template<typename ClientLogic>
bool TCPClient<ClientLogic>::Connected() {
    return m_socket.Connected();
}

template<typename ClientLogic>
void TCPClient<ClientLogic>::Receive() {
    if (m_socket.HasData())
        m_buffer.Push(m_socket.Receive());
}

template<typename ClientLogic>
bool TCPClient<ClientLogic>::HasPackets() {
    
}

template<typename ClientLogic>
void TCPClient<ClientLogic>::Process() {
    OnProcess();
}

template<typename ClientLogic>
void TCPClient<ClientLogic>::OnConnect() {
    m_logic.OnConnect();
}

template<typename ClientLogic>
void TCPClient<ClientLogic>::OnDisconnect() {
    m_logic.OnDisconnect();
}

template<typename ClientLogic>
void TCPClient<ClientLogic>::OnProcess() {
    m_logic.OnProcess();
}
