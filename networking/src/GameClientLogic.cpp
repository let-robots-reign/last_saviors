#include "GameClientLogic.h"
#include "BinaryStream.Game.h"
#include "Packets.h"
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
    //get packets
    //call ProcessPacket
}


void GameClientLogic::Send(const Packet & packet) {
    BinaryStream stream;
    stream.Insert(packet);
    Client.Send(stream.data());
}

void GameClientLogic::ProcessPacket(const Packet & packet) {
    std::cout << "Client is processing a packet!\n";
    //process packet
}
