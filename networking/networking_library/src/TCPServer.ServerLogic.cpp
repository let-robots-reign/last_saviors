#include "TCPServer.cpp"
#include "ServerLogic.h"
#include "ClientStruct.h"

template class ServerLogic<ClientStruct>;
template class TCPServer<ServerLogic<ClientStruct>, ClientStruct>;

