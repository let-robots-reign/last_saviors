#include "ClientStruct.h"

ClientStruct::ClientStruct(std::unique_ptr<TCPSocketConnectedClient> socket) : m_socket(std::move(socket)) {}

void ClientStruct::Send(const std::vector<std::byte> & data) {
    m_socket->Send(data);
}

void ClientStruct::Receive() {
    m_buffer.Push(m_socket->Receive());
}

bool ClientStruct::Connected() const {
    return m_socket->Connected();
}
