#include "TCPServer.cpp"
#include "GameClientStruct.h"
#include "GameServerLogic.cpp"

template class GameServerLogic<GameClientStruct>;
template class TCPServer<GameServerLogic<GameClientStruct>, GameClientStruct>;

// unfortunately, I have to #include .cpp files...
