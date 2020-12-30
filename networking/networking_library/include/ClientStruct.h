#pragma once
#include "TCPSocketConnection.h"
#include "BinaryStream.h"


struct ClientStruct {
public:
    ClientStruct(std::unique_ptr<TCPSocketConnectedClient> socket);

    void Send(const std::vector<std::byte> & data);

    void Receive();

    bool Connected() const;
    
public:
    std::unique_ptr<TCPSocketConnectedClient> m_socket;
    BinaryStream m_buffer;

};
