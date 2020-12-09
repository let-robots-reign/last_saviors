#pragma once
#include "TCPClient.h"
#include "Packet.h"


struct GameClientLogic {
private:
    TCPClient<GameClientLogic> & Client;

private:

    GameClientLogic(TCPClient<GameClientLogic> & client);

    void OnConnect();

    void OnDisconnect();

    void OnProcess();


    void ProcessPacket(const size_t i, std::shared_ptr<Packet> packet);


    friend class TCPClient<GameClientLogic>;

};
