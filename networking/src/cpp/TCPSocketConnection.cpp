#include "../TCPSocketConnection.h"


void TCPSocketConnection::Send(const void *data, size_t data_length) {

}
template <typename Container>
void TCPSocketConnection::Send(const Container &container) {

}


std::vector<std::byte> TCPSocketConnection::Receive() {

}
std::vector<std::byte> TCPSocketConnection::Receive(const size_t size) {

}

bool TCPSocketConnection::HasData() {

}




bool TCPSocketClient::Connect(const SocketAddress &address) {

}
void TCPSocketClient::Disconnect() {

}
bool TCPSocketClient::Connected() {

}




TCPSocketConnectedClient::TCPSocketConnectedClient(int socket, const sockaddr_in &client_info) {

}

void TCPSocketConnectedClient::Disconnect() {

}


TCPSocketServer::TCPSocketServer() {

}
TCPSocketServer::~TCPSocketServer() {

}

void TCPSocketServer::Bind(uint16_t port) {

}
bool TCPSocketServer::CanAccept() {

}
TCPSocketConnectedClient TCPSocketServer::Accept() {

}


