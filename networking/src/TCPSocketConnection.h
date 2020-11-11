#pragma once
#include "TCPSocketBase.h"

class TCPSocketConnection : public TCPSocketBase {
public:
    void Send(const void *data, size_t data_length);
    template <typename Container>
    void Send(const Container &container);   //requires Container to have: data(), size()


    std::vector<std::byte> Receive();
    std::vector<std::byte> Receive(const size_t size);

    bool HasData();

private:

}


class TCPSocketClient : public TCPSocketConnection {
public:
    bool Connect(const SocketAddress &address);
    void Disconnect();

}


class TCPSocketConnectedClient : public TCPSocketConnection {
public:

private:
    SocketAddress m_socket_address;

    TCPSocketConnectedClient(int socket, const sockaddr_in &client_info);

    void Disconnect();

    friend class TCPSocketServer;

}

class TCPSocketServer : public TCPSocketBase {
public:
    TCPSocketServer();
    ~TCPSocketServer();

    void Bind(uint16_t port);
    bool CanAccept();
    TCPSocketConnectedClient Accept();

private:

}
