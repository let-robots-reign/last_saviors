#include "TCPServer.cpp"
#include "GameServerLogic.cpp"

template class GameServerLogic<ServerClient>;
template class TCPServer<GameServerLogic<ServerClient>, ServerClient>;

