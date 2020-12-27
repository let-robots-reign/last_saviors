#pragma once
#include <netinet/in.h>
#include <string>
#include <memory>

const int INVALID_SOCKET = -1;


// IPv4 for now
struct IPAddress {
    explicit IPAddress(const in_addr addr);
    static std::shared_ptr<IPAddress> Create(const std::string & ipv4);

    std::string ToString() const;

    const in_addr addr;
private:
    friend struct Address;
};

struct Address {
public:
    Address(const IPAddress ip, const uint16_t port);
    Address(const in_addr ip, const uint16_t port);
    Address(const sockaddr_in & addr);

    std::string ToString() const;

    sockaddr_in as_sockaddr_in() const;

    IPAddress ip;
    uint16_t port;

};


struct TCPSocketBase {
public:
    explicit TCPSocketBase(bool nonblocking = false);
    ~TCPSocketBase();

protected:
    TCPSocketBase(int && socket);

protected:
    int m_socket;

};
