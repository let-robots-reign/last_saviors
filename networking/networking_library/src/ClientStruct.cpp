#pragma once
#include "ClientStruct.h"

void ClientStruct::Send(const std::vector<std::byte> & data) {
    m_socket.Send(data);
}

void ClientStruct::Receive() {
    if (m_socket.HasData()) m_buffer.Push(m_socket.Receive());
}
