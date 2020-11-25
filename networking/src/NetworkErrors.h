#pragma once
#include <stdexcept>
#include "TCPSocketConnection.h"

class SocketError : public std::runtime_error {
public:
    explicit SocketError(const int errno_, const char *what);
    const int m_errno;

};

class SocketDisconnect : public SocketError {
public:
    explicit SocketDisconnect(const int errno_);
};

class SocketGracefulDisconnect : public SocketDisconnect {
public:
    explicit SocketGracefulDisconnect(const TCPSocketConnection &socket);
    const TCPSocketConnection &m_socket;
};
