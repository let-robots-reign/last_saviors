#include "../GameServerVisitor.h"

GameServerVisitor::GameServerVisitor(TCPServer<GameServerVisitor> & server) : Server(server) {}

void GameServerVisitor::OnStart() {

}

void GameServerVisitor::Tick() {

}

void GameServerVisitor::OnConnect(const size_t id) {

}

void GameServerVisitor::OnDisconnect(const size_t id) {

}

void GameServerVisitor::OnProcess(const size_t i_client) {

}


void GameServerVisitor::ProcessPacket(const size_t i_client, std::shared_ptr<Packet> packet) {

}
