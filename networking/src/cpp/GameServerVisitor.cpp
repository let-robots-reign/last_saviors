#include "../GameServerVisitor.h"
#include <iostream>

GameServerVisitor::GameServerVisitor(TCPServer<GameServerVisitor> & server) : Server(server) {}

void GameServerVisitor::OnStart() {
    std::cout << "Server has started!\n";
}

void GameServerVisitor::Tick() {
    Server.Stop();
}

void GameServerVisitor::OnConnect(const size_t id) {
    std::cout << "A client has just connected!\n";
}

void GameServerVisitor::OnDisconnect(const size_t id) {
    std::cout << "A client has just connected!\n";
}

void GameServerVisitor::OnProcess(const size_t i_client) {
    std::cout << "Processing a client!\n";
}


void GameServerVisitor::ProcessPacket(const size_t i_client, std::shared_ptr<Packet> packet) {

}
