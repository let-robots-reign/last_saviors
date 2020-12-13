#include "TCPSocketBase.h"
#include <cstring>
#include <string>
#include <sstream>
#include "NetworkErrors.h"


IPAddress::IPAddress(const uint32_t ipv4) : ipv4(ipv4) {}

std::shared_ptr<IPAddress> IPAddress::Create(const std::string & ipv4) {
    in_addr addr;
    inet_aton(ipv4.c_str(), &addr);
    return std::make_shared<IPAddress>(addr.s_addr);
}

std::string IPAddress::ToString() const {
    in_addr addr;
    addr.s_addr = ipv4;
    char *ip_addr = inet_ntoa(addr);
    std::string result(ip_addr);
    free(ip_addr);
    return result;
}



Address::Address(const IPAddress ip, const uint16_t port) : Address(ip.ipv4, port) {}

Address::Address(const uint32_t ipv4, const uint16_t port) : ip(ipv4), port(port) {}

Address::Address(const sockaddr_in & addr) : port(addr.sin_port), ip(addr.sin_addr.s_addr) {}

std::shared_ptr<Address> Address::Create(std::string_view address) {
    uint32_t ip;
    uint16_t port;
    const size_t pos = address.find(":");
    const std::string s_ip(address.substr(0, pos));
    const std::string s_port(address.substr(pos + 1));

    std::istringstream iss;
    iss.str(s_ip); iss >> ip;
    iss.clear();
    iss.str(s_port); iss >> port;

    return std::make_shared<Address>(ip, port);
}

std::string Address::ToString() const {
    return ip.ToString() + ":" + std::to_string(port);
}

sockaddr_in Address::as_sockaddr_in() const {
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(ip.ipv4);
    addr.sin_port = htons(port);
    return addr;
}



TCPSocketBase::TCPSocketBase() : m_socket(-1) {
    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socket == -1) {
        //error
    }
    FD_ZERO(&m_set);
}

TCPSocketBase::~TCPSocketBase() {
    if (m_socket != -1) {
        close(m_socket);
    }
}

TCPSocketBase::TCPSocketBase(int && socket) : m_socket(socket) {
    FD_ZERO(&m_set);
}

bool TCPSocketBase::HasData() {
    static constexpr timeval tv = {0, 0};
	FD_SET(m_socket, &m_set);
    int ret = select(0, &m_set, 0, 0, const_cast<timeval *>(&tv));
    if (ret == -1) {
        throw SocketError(errno, "Socket select() failed");
    }
    else {
        return ret;
    }
}
