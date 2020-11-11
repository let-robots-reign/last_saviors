#pragma once
#include "TCPSocketConnection.h"
#include <string_view>
#include "BinaryStream.h"
#include "Packet.h"


class TCPClient {
public:
    TCPClient();
    ~TCPClient();
    bool Connect(std::string_view address);
    bool Connect(const uint32_t ip, const uint16_t port);

    void Send(std::shared_ptr<Packet>);

    virtual void ReceiveAndProcess();

    void Disconnect();
    
    bool Connected();
    
protected:
	void Receive();                                         //to m_buffer
	bool HasPackets();										//m_buffer has packets?

private:
    TCPSocketClient m_socket;
    BinaryStream m_buffer;

}

