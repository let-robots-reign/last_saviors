#pragma once
#include "TCPSocketConnection.h"
#include "BinaryStream.h"


struct ClientStruct {
public:
    ClientStruct(TCPSocketConnectedClient socket);

    void Send(const std::vector<std::byte> & data);

    void Receive();
    
public:
    TCPSocketConnectedClient m_socket;
    BinaryStream m_buffer;

};
