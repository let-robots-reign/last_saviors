#pragma once
#include "TCPSocketBase.h"
#include <vector>


struct TCPSocketConnection : public TCPSocketBase {
public:
    TCPSocketConnection();

    void Send(const std::vector<std::byte> & data);

    void Send(const void *data, const size_t data_length);

    std::vector<std::byte> Receive();
    std::vector<std::byte> Receive(const size_t size);
    ssize_t Receive(void *buffer, const size_t buffer_length);

    void Disconnect();

    bool Connected() const;

protected:
    TCPSocketConnection(int && socket, bool connected);

protected:
    bool m_connected;

};


struct TCPSocketClient : public TCPSocketConnection {
public:
    void Connect(const Address &address);
	
};


struct TCPSocketConnectedClient : public TCPSocketConnection {
    TCPSocketConnectedClient(TCPSocketConnectedClient && client);
    const Address address;
    const bool alive;   // dirty hack

private:
    TCPSocketConnectedClient(int && socket, const sockaddr_in & client_info, bool alive = true);
    friend struct TCPSocketServer;
};


struct TCPSocketServer : public TCPSocketBase {
    TCPSocketServer();
    void Listen(uint16_t port);
    TCPSocketConnectedClient Accept();

};
