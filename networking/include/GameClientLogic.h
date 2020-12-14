#pragma once
#include "ClientLogic.h"
#include "PacketBase.h"


struct GameClientLogic : public ClientLogic {
    friend class TCPClient<GameClientLogic>;
private:
    TCPClient<GameClientLogic> & Client;

private:

    GameClientLogic(TCPClient<GameClientLogic> & client);

    void OnConnect();

    void OnDisconnect();

    void OnProcess();


    void Send(const Packet & packet);

    void ProcessPacket(const Packet & packet);

};
