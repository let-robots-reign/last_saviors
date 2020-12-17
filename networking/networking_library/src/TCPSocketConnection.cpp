#include "TCPSocketConnection.h"
#include "NetworkErrors.h"
#include <cstring>

///TODO: have a look at error handling once again

TCPSocketConnection::TCPSocketConnection() : m_connected(false) {}

TCPSocketConnection::TCPSocketConnection(int && socket, bool connected) : TCPSocketBase(std::move(socket)), m_connected(connected) {}

void TCPSocketConnection::Send(const std::vector<std::byte> & data) {
    Send(data.data(), data.size());
}

void TCPSocketConnection::Send(const void *data, const size_t data_length) {
    if (!Connected()) return;   /// TODO: new exception?
    if (send(m_socket, static_cast<const char *>(data), data_length, MSG_DONTWAIT) < 0) {
        throw SocketError(errno, "Socket send() failed");
    }
}

std::vector<std::byte> TCPSocketConnection::Receive() {
    if (!Connected()) return {};
    const size_t size = 1024;
    std::vector<std::byte> received;

    std::vector<std::byte> received_i;
    do {
        try {
            received_i = Receive(size);
        }
        catch (const SocketDisconnect & disconnect) {
            // We don't want to lose data if there is any
            m_connected = false;
            received_i.resize(0);
        }
        received.insert(received.end(), received_i.begin(), received_i.end());
    } while (received_i.size() != 0);

    received.resize(received.size());
    return received;
}

std::vector<std::byte> TCPSocketConnection::Receive(const size_t size) {
    if (!Connected()) return {};
    std::vector<std::byte> data(size);
    ssize_t received = Receive(static_cast<void *>(data.data()), size);
    if (received < 0) received = 0;
    data.resize(received);
    return data;
}

ssize_t TCPSocketConnection::Receive(void *buffer, const size_t buffer_length) {
    if (!Connected()) throw SocketDisconnect(0);
    const ssize_t received = recv(m_socket, static_cast<char *>(buffer), buffer_length, MSG_DONTWAIT);
	if (received == 0) {
		throw SocketGracefulDisconnect(*this);
	}
	if (received < 0) {
        if (errno == EWOULDBLOCK || errno == EAGAIN) {
            // no problem here
        }
		else {
            throw SocketError(errno, "Socket recv() failed");
        }
	}
    return received;
}

void TCPSocketConnection::Disconnect() {
    shutdown(m_socket, SHUT_RDWR);
    m_connected = false;
}

bool TCPSocketConnection::Connected() const {
    return m_connected;
}



void TCPSocketClient::Connect(const Address & address) {
    if (m_socket == INVALID_SOCKET) {
        throw SocketError(0, "Socket was not initialized");
    }
    const sockaddr_in addr = address.as_sockaddr_in();
    if (connect(m_socket, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        throw SocketError(errno, "Socket connect() failed");
    }
    m_connected = true;
}



TCPSocketConnectedClient::TCPSocketConnectedClient(TCPSocketConnectedClient && client) :
        TCPSocketConnectedClient(std::move(client.m_socket), client.address.as_sockaddr_in())
    {}

TCPSocketConnectedClient::TCPSocketConnectedClient(int && socket, const sockaddr_in & client_info) :
        TCPSocketConnection(std::move(socket), true),
        address(client_info)
    {}

TCPSocketServer::TCPSocketServer() : TCPSocketBase(true) {}

void TCPSocketServer::Listen(uint16_t port) {
    const size_t backlog = 256;
    sockaddr_in host_info;
    memset(&host_info, 0, sizeof(host_info));
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

std::variant<std::monostate, TCPSocketConnectedClient> TCPSocketServer::Accept() {
	sockaddr_in client_info;
	socklen_t client_addr_size = sizeof(client_info);
    int client_socket = accept(m_socket, (struct sockaddr*)&client_info, &client_addr_size);

    if (client_socket == INVALID_SOCKET) return std::variant<std::monostate, TCPSocketConnectedClient>{};
    return std::variant<std::monostate, TCPSocketConnectedClient>( TCPSocketConnectedClient(std::move(client_socket), client_info) );
}
