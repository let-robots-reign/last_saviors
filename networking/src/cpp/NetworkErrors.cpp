#include "../TCPSocketConnection.h"


SocketError::SocketError(const int errno_, const char *what) {

}

SocketDisconnect::SocketDisconnect(const int errno_) {

}

SocketGracefulDisconnect::SocketGracefulDisconnect(const TCPSocketConnection &socket) {

}

