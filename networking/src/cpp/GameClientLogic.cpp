#include "../GameClientLogic.h"
#include <iostream>
#include "../BinaryStream.h"

GameClientLogic::GameClientLogic(TCPClient<GameClientLogic> & client) : Client(client) {}

void GameClientLogic::Send(const std::vector<std::byte> & data) {
    uint64_t size = data.size();
    BinaryStream stream;
    stream.Write(size);
    Client.Send(stream.data());
    Client.Send(data);
}

void GameClientLogic::OnConnect() {
    std::cout << "Client has connected!\n";

}

void GameClientLogic::OnDisconnect() {
    std::cout << "Client has disconnected!\n";

}

void GameClientLogic::OnProcess() {
    std::cout << "Client is processing!\n";
    //get packets
    //call ProcessPacket
}

void GameClientLogic::ProcessPacket(std::shared_ptr<Packet> packet) {
    std::cout << "Client is processing a packet!\n";
    //process packet
}
