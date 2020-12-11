#pragma once
#include "ServerLogic.h"
#include "Packet.h"

template<typename TClient>
struct GameServerLogic : public ServerLogic<TClient> {
    friend class TCPServer<GameServerLogic<TClient>>;
private:
    TCPServer<GameServerLogic<TClient>, TClient> & Server;

private:

    GameServerLogic(TCPServer<GameServerLogic<TClient>> & server);

    void Send(const size_t i, const std::vector<std::byte> & data);

    void OnStart();

    void OnTick();

    void OnConnect(const size_t i);

    void OnDisconnect(const size_t i);

    void OnProcess(const size_t i);


    void ProcessPacket(const size_t i, std::shared_ptr<Packet> packet);

};