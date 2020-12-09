#pragma once
#include "TCPSocketConnection.h"
#include "BinaryStream.h"
#include <string_view>


class TCPClient {
public:
    TCPClient();
    virtual ~TCPClient();
    bool Connect(std::string_view address);
    bool Connect(const uint32_t ip, const uint16_t port);

    template<typename Container>
    void Send(const Container &container) {
        m_socket.Send(container);
    }

    virtual void ReceiveAndProcess();

    void Disconnect();
    
    bool Connected();
    
protected:
	void Receive();                                         //to m_buffer
	bool HasPackets();										//m_buffer has packets?

private:
    TCPSocketClient m_socket;
    BinaryStream m_buffer;

};
