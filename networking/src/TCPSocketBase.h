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
    SocketAddress(){};  //temp
    SocketAddress(const uint32_t address, const uint16_t port);
    SocketAddress(const sockaddr &sockaddr_);
    
    std::string ToString() const;

    static std::shared_ptr<SocketAddress> Create(std::string_view address);

private:
    //I just want it to compile
    /*const*/ uint32_t m_ip;
    /*const*/ uint16_t m_port;
    sockaddr m_sockaddr;

};


class TCPSocketBase {
public:
    TCPSocketBase();
    ~TCPSocketBase();

protected:
    TCPSocketBase(int socket);

private:
    int m_socket;

};
