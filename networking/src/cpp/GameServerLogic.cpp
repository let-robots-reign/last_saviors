#include "../GameServerLogic.h"
#include <iostream>

template<typename TClient>
GameServerLogic<TClient>::GameServerLogic(TCPServer<GameServerLogic<TClient>> & server) : Server(server) {}

template<typename TClient>
void GameServerLogic<TClient>::Send(const size_t i, const std::vector<std::byte> & data) {
    uint64_t size = data.size();
    BinaryStream stream;
    stream.Write(size);
    Server.GetClient(i).Send(stream.data());
    Server.GetClient(i).Send(data);
}

template<typename TClient>
void GameServerLogic<TClient>::OnStart() {
    std::cout << "Server has started!\n";
    
}

template<typename TClient>
void GameServerLogic<TClient>::OnTick() {
    //to stop the example program
    Server.Stop();
    //game logic here
    //sleep(...); //to have constant amount of ticks per second
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
}

template<typename TClient>
void GameServerLogic<TClient>::ProcessPacket(const size_t i, std::shared_ptr<Packet> packet) {
    //process packet
}
