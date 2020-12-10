#include "TCPServer.cpp"
#include "GameServerLogic.cpp"
#include "../ServerLogic.h"

template class GameServerLogic<ServerClient>;
template class TCPServer<GameServerLogic<ServerClient>, ServerClient>;

template class TCPServer<ServerLogic<ServerClient>, ServerClient>;
