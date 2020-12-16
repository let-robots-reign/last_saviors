#include "GameServerLogic.h"
#include "BinaryStream.Game.h"
#include "Packets.h"
#include <iostream>
#include <thread>

// warning: example logic

template<typename TClient>
GameServerLogic<TClient>::GameServerLogic(TCPServer<GameServerLogic<TClient>, TClient> & server) : Server(server) {}

template<typename TClient>
void GameServerLogic<TClient>::OnStart() {
    std::cout << "Server has started!\n";
    
}

template<typename TClient>
void GameServerLogic<TClient>::OnTick() {
    //game logic here
    //sleep(...); //to have constant amount of ticks per second
    //std::cout << "Tick() finished\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

template<typename TClient>
void GameServerLogic<TClient>::OnConnect(const size_t i) {
    std::cout << "A client has just connected!\n";

}

template<typename TClient>
void GameServerLogic<TClient>::OnDisconnect(const size_t i) {
    std::cout << "A client has just disconnected!\n";

}

template<typename TClient>
void GameServerLogic<TClient>::OnProcess(const size_t i) {
    //std::cout << "Processing a client!\n";

    Packet packet;
    size_t read = Server.GetClient(i).m_buffer.Extract(packet);
    while (read != 0) {
        ProcessPacket(i, packet);
        read = Server.GetClient(i).m_buffer.Extract(packet);
    }
}

template<typename TClient>
void GameServerLogic<TClient>::Send(const size_t i, const Packet & packet) {
    BinaryStream stream;
    stream.Insert(packet);
    Server.Send(i, stream.data());
}

template<typename TClient>
void GameServerLogic<TClient>::ProcessPacket(const size_t i, const Packet & packet) {
    //std::cout << "Processing a packet!\n";

    const PacketType::PacketType type = packet.Type();

    // temp
    if (type == PacketType::ChatMessage) {
        ChatMessagePacket chatmessage(packet);
        std::cout << chatmessage.name << ": " << chatmessage.message << std::endl;
        Server.SendEveryone(packet);
    }
    else {
        std::cout << "Unknown packet type: " << type() << std::endl;
    }
}
