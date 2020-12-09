#pragma once
#include "TCPServer.h"
#include "Packet.h"


struct GameServerVisitor {
private:
    TCPServer<GameServerVisitor> & Server;

private:

    GameServerVisitor(TCPServer<GameServerVisitor> & server);

    void OnStart();

    void Tick();

    void OnConnect(const size_t id);

    void OnDisconnect(const size_t id);

    void OnProcess(const size_t i_client);


    void ProcessPacket(const size_t i_client, std::shared_ptr<Packet> packet);


    friend class TCPServer<GameServerVisitor>;

};
