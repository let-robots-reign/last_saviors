#pragma once
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#include <memory>
#include <string_view>


struct SocketAddress {
public:
    SocketAddress(const uint32_t address, const uint16_t port);
    SocketAddress(const sockaddr_in & address);
    
    std::string ToString() const;

    static std::shared_ptr<SocketAddress> Create(std::string_view address);

    sockaddr_in GetSockaddr() const;

private:
    const uint32_t m_ip;
    const uint16_t m_port;
    sockaddr_in m_sockaddr;

};


class TCPSocketBase {
public:
    TCPSocketBase();
    ~TCPSocketBase();

protected:
    TCPSocketBase(int && socket);

public:
    bool HasData();

protected:
    int m_socket;
    fd_set m_set;

};
