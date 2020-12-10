#include "../NetworkErrors.h"


SocketError::SocketError(const int errno_, const char *what) : m_errno(errno_), std::runtime_error(what) {}

SocketDisconnect::SocketDisconnect(const int errno_) : SocketError(errno_, "Disconnected") {}

SocketGracefulDisconnect::SocketGracefulDisconnect(const TCPSocketConnection &socket) : m_socket(socket), SocketDisconnect(0) {}

