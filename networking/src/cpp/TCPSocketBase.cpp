#include "../TCPSocketBase.h"
#include <cstring>
#include <string>
#include <sstream>

namespace {
    sockaddr_in sockaddr_in_from_uints(const uint32_t address, const uint16_t port) {
        sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = htonl(address);
        addr.sin_port = htons(port);
        return addr;
    }
}

SocketAddress::SocketAddress(const uint32_t address, const uint16_t port) :
                                                                            m_ip(address),
                                                                            m_port(port),
                                                                            m_sockaddr(sockaddr_in_from_uints(address, port))
                                                                        {}

SocketAddress::SocketAddress(const sockaddr_in & address) :
                                                                            m_ip(ntohl(address.sin_addr.s_addr)),
                                                                            m_port(ntohs(address.sin_port)),
                                                                            m_sockaddr(address)
                                                                        {}

std::string SocketAddress::ToString() const {
    char ip[16];
    snprintf(ip, sizeof(ip),"%u.%u.%u.%u",
                (m_ip & 0xff000000) >> 24,
                (m_ip & 0x00ff0000) >> 16,
                (m_ip & 0x0000ff00) >>  8,
                (m_ip & 0x000000ff) >>  0
            );
    return std::string(ip) + ":" + std::to_string(m_port);
}

///TODO: Error handling
std::shared_ptr<SocketAddress> SocketAddress::Create(std::string_view address) {
    uint32_t ip;
    uint16_t port;
    const size_t pos = address.find(":");
    const std::string s_ip(address.substr(0, pos));
    const std::string s_port(address.substr(pos + 1));

    std::istringstream iss;
    iss.str(s_ip); iss >> ip;
    iss.clear();
    iss.str(s_port); iss >> port;

    return std::make_shared<SocketAddress>(SocketAddress(ip, port));
}

sockaddr_in SocketAddress::GetSockaddr() const {
    return m_sockaddr;
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

TCPSocketBase::TCPSocketBase(int socket) : m_socket(socket) {
    FD_ZERO(&m_set);
}

bool TCPSocketBase::HasData() {
    static constexpr timeval tv = {0, 0};
	FD_SET(m_socket, &m_set);
    int ret = select(0, &m_set, 0, 0, const_cast<timeval*>(&tv));
    if (ret == -1) {
        throw SocketError(errno, "Socket select() failed");
    }
    else {
        return ret;
    }
}
