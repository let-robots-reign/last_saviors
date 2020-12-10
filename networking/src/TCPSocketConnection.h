#pragma once
#include "TCPSocketBase.h"
#include <vector>

class TCPSocketConnection : public TCPSocketBase {
public:
    TCPSocketConnection();

    void Send(const void *data, size_t data_length);

    template <typename Container>
    void Send(const Container &container) {
        Send(container.data(), container.size());
    }   //requires Container to have: data(), size()


    void Receive(void * buffer, size_t buffer_length, int & received);
    std::vector<std::byte> Receive();
    std::vector<std::byte> Receive(const size_t size);

    void Disconnect();

    bool Connected() const;

protected:
    TCPSocketConnection(int && socket, bool connected);

protected:
    bool m_connected;

};


class TCPSocketClient : public TCPSocketConnection {
public:
    bool Connect(const SocketAddress &address);
	
};


class TCPSocketConnectedClient : public TCPSocketConnection {
public:

private:
    SocketAddress m_socket_address;

    TCPSocketConnectedClient(int && socket, const sockaddr_in & client_info);

    friend class TCPSocketServer;

};


class TCPSocketServer : public TCPSocketBase {
public:
    TCPSocketServer() = default;
    ~TCPSocketServer() = default;

    void Bind(uint16_t port);
    bool CanAccept();
    TCPSocketConnectedClient Accept();

private:

};
