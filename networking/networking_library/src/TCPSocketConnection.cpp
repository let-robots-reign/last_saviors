#include "TCPSocketConnection.h"
#include "NetworkErrors.h"
#include <cstring>


TCPSocketConnection::TCPSocketConnection() : m_connected(false) {}

TCPSocketConnection::TCPSocketConnection(int && socket, bool connected) : TCPSocketBase(std::move(socket)), m_connected(connected) {}

void TCPSocketConnection::Send(const std::vector<std::byte> & data) {
    Send(data.data(), data.size());
}

void TCPSocketConnection::Send(const void *data, size_t data_length) {
    if (send(m_socket, static_cast<const char *>(data), data_length, MSG_DONTWAIT) < 0) {
        throw SocketError(errno, "Socket send() failed");
    }
}

void TCPSocketConnection::Receive(void * buffer, size_t buffer_length, int & received) {
    received = recv(m_socket, (char*)buffer, buffer_length, MSG_DONTWAIT);
	if (received == 0) {
		throw SocketGracefulDisconnect(*this);
	}
	else if (received < 0) {
        if (errno == EWOULDBLOCK) {
            // no problem here
        }
		else {
            throw SocketError(errno, "Socket recv() failed");
        }
	}
}

std::vector<std::byte> TCPSocketConnection::Receive() {
    // const size_t size = 1024;
    // std::vector<std::byte> ans;
    // while (HasData()) {
    //     std::vector<std::byte> received = Receive(size);
    //     ans.insert(ans.end(), received.begin(), received.end());
    // }
    // return ans;
    const size_t size = 1024;
    return Receive(size);
}

std::vector<std::byte> TCPSocketConnection::Receive(const size_t size) {
    std::vector<std::byte> data(size);
    int received = 0;
    Receive((void *)data.data(), size, received);
    data.resize(received);
    return data;
}

void TCPSocketConnection::Disconnect() {
    shutdown(m_socket, SHUT_RDWR);
}

bool TCPSocketConnection::Connected() const {
    return m_connected;
}




bool TCPSocketClient::Connect(const Address & address) {
    if (m_socket == -1) {
        throw SocketError(0, "Socket was not initialized");
        return false;
    }

    sockaddr_in addr = address.as_sockaddr_in();
    if (connect(m_socket, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        throw SocketError(errno, "Socket connect() failed");
        return false;
    }

    m_connected = true;
    return true;
}



TCPSocketConnectedClient::TCPSocketConnectedClient(TCPSocketConnectedClient && client) :
        TCPSocketConnectedClient(std::move(client.m_socket), client.address.as_sockaddr_in(), client.alive)
    {}

TCPSocketConnectedClient::TCPSocketConnectedClient(int && socket, const sockaddr_in & client_info, bool alive) :
        TCPSocketConnection(std::move(socket), true),
        address(client_info),
        alive(alive)
    {}

TCPSocketServer::TCPSocketServer() : TCPSocketBase(true) {}

void TCPSocketServer::Listen(uint16_t port) {
    const size_t backlog = 256;
    sockaddr_in host_info;
    memset(&host_info, '0', sizeof(host_info));
	host_info.sin_family = AF_INET;
	host_info.sin_addr.s_addr = htonl(INADDR_ANY);
	host_info.sin_port = htons(port);
    if (bind(m_socket, (sockaddr*)&host_info, sizeof(host_info))) {
		throw SocketError(errno, "Socket bind() error");
	}
    if (listen(m_socket, backlog)) {
		throw SocketError(errno, "Socket listen() error");
	}
}

bool TCPSocketServer::CanAccept() {
    return HasData();
}

TCPSocketConnectedClient TCPSocketServer::Accept() {
	sockaddr_in client_info;
	socklen_t client_addr_size = sizeof(client_info);
    int client_socket = accept(m_socket, (struct sockaddr*)&client_info, &client_addr_size);
    const bool alive = (client_socket != -1);
    return TCPSocketConnectedClient(std::move(client_socket), client_info, alive);
}
