#include "../GameClientLogic.h"
#include <iostream>

GameClientLogic::GameClientLogic(TCPClient<GameClientLogic> & client) : Client(client) {}

void GameClientLogic::OnConnect() {
    std::cout << "Client has connected!\n";

}

void GameClientLogic::OnDisconnect() {
    std::cout << "Client has disconnected!\n";

}

void GameClientLogic::OnProcess() {
    std::cout << "Client is processing!\n";

}

void GameClientLogic::ProcessPacket(std::shared_ptr<Packet> packet) {
    std::cout << "Client is processing a packet!\n";

}
