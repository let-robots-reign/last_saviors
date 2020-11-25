#pragma once
#include "TCPClient.h"
#include "Packet.h"

class GameTCPClient : public TCPClient {
public:
    GameTCPClient();
    ~GameTCPClient();

    void ReceiveAndProcess() override;  
    void Send(std::shared_ptr<Packet> packet);

private:
    std::shared_ptr<Packet> ReadPacket();                   //from m_buffer
    void ProcessPacket(std::shared_ptr<Packet>);

};
