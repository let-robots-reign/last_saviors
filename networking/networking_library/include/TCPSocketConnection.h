#pragma once
#include "TCPSocketBase.h"
#include <vector>

struct TCPSocketConnection : public TCPSocketBase {
public:
    TCPSocketConnection();

    void Send(const std::vector<std::byte> & data);

    void Send(const void *data, size_t data_length);

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


struct TCPSocketClient : public TCPSocketConnection {
public:
    bool Connect(const Address &address);
	
};


struct TCPSocketConnectedClient : public TCPSocketConnection {
public:

private:
    Address m_address;

    TCPSocketConnectedClient(int && socket, const sockaddr_in & client_info);

    friend struct TCPSocketServer;

};


struct TCPSocketServer : public TCPSocketBase {

    void Listen(uint16_t port);
    bool CanAccept();
    TCPSocketConnectedClient Accept();

};
