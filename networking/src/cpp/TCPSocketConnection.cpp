#include "../TCPSocketConnection.h"

TCPSocketConnection::TCPSocketConnection() : m_connected(false) {}

TCPSocketConnection::TCPSocketConnection(bool connected) : m_connected(connected) {}

void TCPSocketConnection::Send(const void *data, size_t data_length) {
    if (send(m_socket, static_cast<const char *>(data), data_length, MSG_DONTWAIT) < 0) {
        //error
    }
}

std::vector<std::byte> TCPSocketConnection::Receive() {

}

std::vector<std::byte> TCPSocketConnection::Receive(const size_t size) {

}

void TCPSocketConnection::Disconnect() {
    shutdown(m_socket, SHUT_RDWR);
}

bool TCPSocketConnection::Connected() const {
    return m_connected;
}




bool TCPSocketClient::Connect(const SocketAddress &address) {
    if (m_socket == -1) {
        //error
        return false;
    }

    sockaddr_in sockaddr = address.GetSockaddr();
    if (connect(m_socket, (sockaddr*)&sockaddr, sizeof(sockaddr)) < 0) {
        //error
        return false;
    }

    m_connected = true;
    return true;
}



TCPSocketConnectedClient::TCPSocketConnectedClient(int socket, const sockaddr_in &client_info) {

}


TCPSocketServer::TCPSocketServer() {}

TCPSocketServer::~TCPSocketServer() {}

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

}
