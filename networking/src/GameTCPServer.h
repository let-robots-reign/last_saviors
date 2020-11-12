#pragma once
#include "TCPServer.h"

class GameTCPServer : public TCPServer {
public:
    GameTCPServer();
    ~GameTCPServer();

protected:
    virtual void OnConnect(const size_t id);
    virtual void OnDisconnect(const size_t id);
    virtual void OnProcess(const size_t id);
    virtual void ProcessPacket(const size_t i_client, std::shared_ptr<Packet> packet);
    virtual void Tick();

};
