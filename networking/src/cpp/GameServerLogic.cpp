#include "../GameServerLogic.h"
#include <iostream>

GameServerLogic::GameServerLogic(TCPServer<GameServerLogic> & server) : Server(server) {}

void GameServerLogic::OnStart() {
    std::cout << "Server has started!\n";
    
}

void GameServerLogic::OnTick() {
    //to stop the example program
    Server.Stop();
    //game logic here
    //sleep(...); //to have constant amount of ticks per second
}

void GameServerLogic::OnConnect(const size_t i) {
    std::cout << "A client has just connected!\n";

}

void GameServerLogic::OnDisconnect(const size_t i) {
    std::cout << "A client has just disconnected!\n";

}

void GameServerLogic::OnProcess(const size_t i) {
    std::cout << "Processing a client!\n";
    
}


void GameServerLogic::ProcessPacket(const size_t i, std::shared_ptr<Packet> packet) {

}
