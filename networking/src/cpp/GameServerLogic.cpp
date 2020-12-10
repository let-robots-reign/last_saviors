#include "../GameServerLogic.h"
#include <iostream>

GameServerLogic::GameServerLogic(TCPServer<GameServerLogic> & server) : Server(server) {}

void GameServerLogic::Send(const size_t i, const std::vector<std::byte> & data) {
    uint64_t size = data.size();
    BinaryStream stream;
    stream.Write(size);
    Server.GetClient(i).Send(stream.data());
    Server.GetClient(i).Send(data);
}

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
    //get packets
    //call ProcessPacket
}


void GameServerLogic::ProcessPacket(const size_t i, std::shared_ptr<Packet> packet) {
    //process packet
}
