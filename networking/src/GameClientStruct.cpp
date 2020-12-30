#include "GameClientStruct.h"

GameClientStruct::GameClientStruct(std::unique_ptr<TCPSocketConnectedClient> socket) : ClientStruct(std::move(socket)), m_quizstate(NONE) {}
