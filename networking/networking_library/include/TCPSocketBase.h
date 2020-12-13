#pragma once
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
///TODO: move theis ^ to .cpp

#include <memory>
#include <string_view>

// IPv4 for now
struct IPAddress {
    explicit IPAddress(const uint32_t ipv4);

    static std::shared_ptr<IPAddress> Create(const std::string & ipv4);

    std::string ToString() const;

    uint32_t ipv4;
};

struct Address {
public:
    Address(const IPAddress ip, const uint16_t port);
    Address(const uint32_t ipv4, const uint16_t port);
    Address(const sockaddr_in & addr);

    static std::shared_ptr<Address> Create(std::string_view address);

    std::string ToString() const;

    sockaddr_in as_sockaddr_in() const;

    IPAddress ip;
    uint16_t port;

};


struct TCPSocketBase {
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
