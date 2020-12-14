#include "NetworkErrors.h"


SocketError::SocketError(const int errno_, const char *what) : std::runtime_error(what), m_errno(errno_) {}

SocketDisconnect::SocketDisconnect(const int errno_) : SocketError(errno_, "Disconnected") {}

SocketGracefulDisconnect::SocketGracefulDisconnect(const TCPSocketConnection &socket) : SocketDisconnect(0), m_socket(socket) {}

