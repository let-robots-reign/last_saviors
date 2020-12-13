#pragma once
#include "ClientLogic.h"
#include "PacketBase.h"


struct GameClientLogic : public ClientLogic {
    friend class TCPClient<GameClientLogic>;
private:
    TCPClient<GameClientLogic> & Client;

private:

    GameClientLogic(TCPClient<GameClientLogic> & client);

    void Send(const std::vector<std::byte> & data);

    void OnConnect();

    void OnDisconnect();

    void OnProcess();


    bool HasPackets();

    void ProcessPacket(const Packet & packet);

};

