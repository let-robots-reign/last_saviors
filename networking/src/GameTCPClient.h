#pragma once
#include "TCPClient.h"
#include "Packet.h"

class GameTCPClient : public TCPClient {
public:
    GameTCPClient();
    ~GameTCPClient();

    virtual void ReceiveAndProcess();  
    void Send(std::shared_ptr<Packet> packet);

private:
    std::shared_ptr<Packet> ReadPacket();                   //from m_buffer
    void ProcessPacket(std::shared_ptr<Packet>);

};
