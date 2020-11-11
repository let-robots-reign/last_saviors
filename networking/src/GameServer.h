#pragma once
#include "TCPServer.h"

class GameTCPServer {
public:
    GameTCPServer();
    ~GameTCPServer();

protected:
    virtual void OnConnect(const size_t id);
    virtual void OnDisconnect(const size_t id);
    virtual void ProcessPacket(const size_t i_client, const Packet &packet);
    virtual void Tick();

}
