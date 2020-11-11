#include "../TCPSocketBase.h"
#include <cstring>

SocketAddress::SocketAddress(const uint32_t address, const uint16_t port) : m_ip(address), m_port(port) {

}
SocketAddress::SocketAddress(const sockaddr &sockaddr_) : m_ip(((sockaddr_in *)&sockaddr_)->sin_addr.s_addr), m_port(((sockaddr_in *)&sockaddr_)->sin_port) {
    std::memcpy( &m_sockaddr, &sockaddr_, sizeof( sockaddr ) );
}

std::string SocketAddress::ToString() const {

}

std::shared_ptr<SocketAddress> SocketAddress::Create(std::string_view address) {
    return std::make_shared<SocketAddress>(SocketAddress(0, 0)); //temp
}



TCPSocketBase::TCPSocketBase() {

}
TCPSocketBase::~TCPSocketBase() {

}

TCPSocketBase::TCPSocketBase(int socket) {

}


