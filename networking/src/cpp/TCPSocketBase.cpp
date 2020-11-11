#include "../TCPSocketBase.h"


SocketAddress::SocketAddress(const uint32_t address_, const uint16_t port_) {

}
SocketAddress::SocketAddress(const sockaddr &sockaddr_) {

}

std::string SocketAddress::ToString() const {

}

std::shared_ptr<SocketAddress> SocketAddress::Create(std::string_view address_) {

}



TCPSocketBase::TCPSocketBase() {

}
TCPSocketBase::~TCPSocketBase() {

}

TCPSocketBase::TCPSocketBase(int socket_) {

}


