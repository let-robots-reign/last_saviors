#include "GameClientLogic.h"
#include "BinaryStream.Game.h"
#include "Packets.h"
#include <iostream>

// warning: example logic

GameClientLogic::GameClientLogic(TCPClient<GameClientLogic> & client) : Client(client) {}


void GameClientLogic::OnConnect() {
    std::cout << "Client has connected!\n";

}

void GameClientLogic::OnDisconnect() {
    std::cout << "Client has disconnected!\n";

}

void GameClientLogic::OnProcess() {
    //std::cout << "Client is processing!\n";
    
    Packet packet;
    size_t read = Client.GetBuffer().Extract(packet);
    while (read != 0) {
        ProcessPacket(packet);
        read = Client.GetBuffer().Extract(packet);
    }
}


void GameClientLogic::Send(const Packet & packet) {
    BinaryStream stream;
    stream.Insert(packet);
    Client.Send(stream.data());
}

void GameClientLogic::ProcessPacket(const Packet & packet) {
    //std::cout << "Client is processing a packet!\n";
    
    const PacketType::PacketType type = packet.Type();

    // temp
    if (type == PacketType::ChatMessage) {
        ChatMessagePacket chatmessage(packet);
        std::cout << chatmessage.name << ": " << chatmessage.message << std::endl;
    }
    else {
        std::cout << "Unknown packet type: " << type() << std::endl;
    }

}
