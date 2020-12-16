#include "TCPSocketBase.h"
#include <cstring>
#include <string>
#include <sstream>
#include "NetworkErrors.h"


IPAddress::IPAddress(const in_addr addr) : addr(addr) {}

std::shared_ptr<IPAddress> IPAddress::Create(const std::string & ipv4) {
    in_addr address;
    inet_aton(ipv4.c_str(), &address);
    return std::make_shared<IPAddress>(address);
}

std::string IPAddress::ToString() const {
    return std::string(inet_ntoa(addr));
}



Address::Address(const IPAddress ip, const uint16_t port) : Address(ip.addr, port) {}

Address::Address(const in_addr ipv4, const uint16_t port) : ip(ipv4), port(port) {}

Address::Address(const sockaddr_in & addr) : ip(addr.sin_addr), port(addr.sin_port) {}


std::string Address::ToString() const {
    return ip.ToString() + ":" + std::to_string(port);
}

sockaddr_in Address::as_sockaddr_in() const {
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    //addr.sin_addr.s_addr = htonl(ip.addr.s_addr); //doesn't work for some reason
    addr.sin_addr.s_addr = ip.addr.s_addr;
    addr.sin_port = htons(port);
    return addr;
}



TCPSocketBase::TCPSocketBase(bool nonblocking) : m_socket(socket(AF_INET, nonblocking ? (SOCK_STREAM | SOCK_NONBLOCK) : SOCK_STREAM, 0)) {
    if (m_socket == -1) {
        //error
        /// TODO: handle
    }
}

TCPSocketBase::~TCPSocketBase() {
    if (m_socket != -1) {
        close(m_socket);  // temp
    }
}

TCPSocketBase::TCPSocketBase(int && socket) : m_socket(socket) {
    socket = -1;
}
