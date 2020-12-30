#pragma once
#include "TCPSocketConnection.h"
#include "BinaryStream.h"
#include "PacketBase.h"


template<typename TClientLogic>
class TCPClient {
public:
    TCPClient();

    bool Connect(const Address & address);

    void Send(const Packet & packet);
    void Send(const std::vector<std::byte> & data);

    void ReceiveAndProcess();

    void Disconnect();
    
    bool Connected();
    
public:                                                     // for ClientLogic
    BinaryStream & GetBuffer();

private:
	void Receive();                                         // to m_buffer
    void Process();                                         // from m_buffer


private:
    TClientLogic m_logic;

    TCPSocketClient m_socket;
    BinaryStream m_buffer;

};
