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
        std::cout << "Received QuizResponsePacket" << std::endl;
        const QuizResponsePacket responsepacket(packet);
        std::cout << responsepacket.quiz.question << std::endl;
        std::cout << responsepacket.quiz.optionA << std::endl;
        std::cout << responsepacket.quiz.optionB << std::endl;
        std::cout << responsepacket.quiz.optionC << std::endl;
        std::cout << responsepacket.quiz.optionD << std::endl;
        ///TODO: some Application stuff xd
    }
    else if (type == PacketType::QuizResultPacket) {
        std::cout << "Received QuizResultPacket" << std::endl;
        const QuizResultPacket resultpacket(packet);
        std::cout << "Answer was (1 - correct, 0 - incorrect): " << resultpacket.result << std::endl;
        ///TODO: some Application stuff xd
    }
    else {
        std::cout << "Unknown packet type: " << type() << std::endl;
    }

}
