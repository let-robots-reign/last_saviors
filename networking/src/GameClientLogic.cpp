#include "GameClientLogic.h"
#include "BinaryStream.Game.h"
#include "Packets.h"
#include <iostream>
///TODO: #include Alexey's "Applcation.h"

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

    if (type == PacketType::ChatMessage) {
        const ChatMessagePacket chatmessage(packet);
        std::cout << chatmessage.name << ": " << chatmessage.message << std::endl;
    }
    else if (type == PacketType::QuizResponsePacket) {
        const QuizResponsePacket responsepacket(packet);
        ///TODO: some Application stuff xd
    }
    else if (type == PacketType::QuizResultPacket) {
        const QuizResultPacket resultpacket(packet);
        ///TODO: some Application stuff xd
    }
    else {
        std::cout << "Unknown packet type: " << type() << std::endl;
    }

}
