#include "TCPSocketConnection.h"
#include "NetworkErrors.h"

TCPSocketConnection::TCPSocketConnection() : m_connected(false) {}

TCPSocketConnection::TCPSocketConnection(int && socket, bool connected) : TCPSocketBase(std::move(socket)), m_connected(connected) {}

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
		if (false) ///TODO
			throw SocketDisconnect(errno);
		else
			throw SocketError(errno, "Socket recv() failed");
	}
}

std::vector<std::byte> TCPSocketConnection::Receive() {
    const size_t size = 1024;
    std::vector<std::byte> ans;
    while (HasData()) {
        std::vector<std::byte> received = Receive(size);
        ans.insert(ans.end(), received.begin(), received.end());
    }
    return ans;
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




bool TCPSocketClient::Connect(const SocketAddress &address) {
    if (m_socket == -1) {
        throw SocketError(0, "Socket was not initialized");
        return false;
    }

    sockaddr_in sockaddr = address.GetSockaddr();
    if (connect(m_socket, (struct sockaddr*)&sockaddr, sizeof(sockaddr)) < 0) {
        throw SocketError(errno, "Socket connect() failed");
        return false;
    }

    m_connected = true;
    return true;
}



TCPSocketConnectedClient::TCPSocketConnectedClient(int && socket, const sockaddr_in & client_info) :
                                                                                                    TCPSocketConnection(std::move(socket), true),
                                                                                                    m_socket_address(client_info) {}


void TCPSocketServer::Bind(uint16_t port) {
    const size_t backlog = 256;
    sockaddr_in host_info;
	host_info.sin_family = AF_INET;
	host_info.sin_addr.s_addr = INADDR_ANY;
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
    int client_socket;
	sockaddr_in client_info;
	socklen_t client_addr_size = sizeof(client_info);
    client_socket = accept(m_socket, (struct sockaddr*)&client_info, &client_addr_size);
	if (client_socket == -1) {
		throw SocketError(errno, "Socket accept() error");
	}
    return TCPSocketConnectedClient(std::move(client_socket), client_info);
}
