#pragma once
#include "TCPServer.h"

class GameTCPClient {
public:
    GameTCPClient();
    ~GameTCPClient();

    virtual void ReceiveAndProcess();  

private:
    std::shared_ptr<Packet> ReadPacket();                   //from m_buffer
    void ProcessPacket(const Packet);

}
