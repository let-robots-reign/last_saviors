#pragma once
#include "TCPServer.h"

class GameTCPServer : public TCPServer {
public:
    GameTCPServer();
    ~GameTCPServer();

protected:
    void OnStart() override;
    void OnConnect(const size_t id) override;
    void OnDisconnect(const size_t id) override;
    void OnProcess(const size_t id) override;
    void Tick() override;
    void ProcessPacket(const size_t i_client, std::shared_ptr<Packet> packet);

};
