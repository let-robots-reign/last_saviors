#include "GameServerLogic.h"
#include "BinaryStream.h"
#include <iostream>
#include <thread>

template<typename TClient>
GameServerLogic<TClient>::GameServerLogic(TCPServer<GameServerLogic<TClient>, TClient> & server) : Server(server) {}

template<typename TClient>
void GameServerLogic<TClient>::Send(const size_t i, const std::vector<std::byte> & data) {
    BinaryStream stream;
    stream.Insert((uint64_t)data.size());
    stream.Push(data);
    Server.GetClient(i).Send(stream.data());
}

template<typename TClient>
void GameServerLogic<TClient>::OnStart() {
    std::cout << "Server has started!\n";
    
}

template<typename TClient>
void GameServerLogic<TClient>::OnTick() {
    //game logic here
    //sleep(...); //to have constant amount of ticks per second
    std::cout << "Tick() finished\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
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
    std::cout << "Processing a client!\n";
    //get packets
    //call ProcessPacket

    // temp
    std::vector<std::byte> vec(Server.GetClient(i).m_buffer.data());
    if (vec.size() != 0) {
        BinaryStream stream;
        stream.Push(vec);
        ProcessPacket(i, Packet{stream});
    }
}

template<typename TClient>
void GameServerLogic<TClient>::ProcessPacket(const size_t i, const Packet & packet) {
    // process packet
    const PacketType::PacketType type = packet.Type();

    // temp
    if (type == PacketType::ChatMessage) {
        ChatMessagePacket chatmessage(packet);
        std::cout << chatmessage.name << ": " << chatmessage.message << std::endl;
    }
    else {
        std::cout << "Something else" << std::endl;
    }
}
