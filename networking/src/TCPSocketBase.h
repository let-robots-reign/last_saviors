#pragma once
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#include <memory>


struct SocketAddress {
public:
    SocketAddress(const uint32_t address_, const uint16_t port_);
    SocketAddress(const sockaddr &sockaddr_);
    
    std::string ToString() const;

    static std::shared_ptr<SocketAddress> Create(std::string_view address_);

private:
    const uint32_t m_ip;
    const uint16_t m_port;
    sockaddr m_sockaddr;

}


class TCPSocketBase {
public:
    TCPSocketBase();
    ~TCPSocketBase();

protected:
    TCPSocketBase(int socket_);

private:
    int m_socket;

}
