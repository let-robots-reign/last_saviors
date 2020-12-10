#pragma once
#include "TCPServer.h"
#include "Packet.h"


struct GameServerLogic {
private:
    TCPServer<GameServerLogic> & Server;

private:

    GameServerLogic(TCPServer<GameServerLogic> & server);

    void Send(const size_t i, const std::vector<std::byte> & data);

    void OnStart();

    void OnTick();

    void OnConnect(const size_t i);

    void OnDisconnect(const size_t i);

    void OnProcess(const size_t i);


    void ProcessPacket(const size_t i, std::shared_ptr<Packet> packet);


    friend class TCPServer<GameServerLogic>;

};