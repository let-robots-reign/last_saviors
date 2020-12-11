#include "TCPServer.cpp"
#include "ClientStruct.h"
#include "GameServerLogic.cpp"

template class GameServerLogic<ClientStruct>;
template class TCPServer<GameServerLogic<ClientStruct>, ClientStruct>;

