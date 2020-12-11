#include "TCPServer.cpp"
#include "ServerLogic.h"

template class ServerLogic<ServerClient>;
template class TCPServer<ServerLogic<ServerClient>, ServerClient>;

