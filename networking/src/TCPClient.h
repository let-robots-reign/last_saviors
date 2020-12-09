#pragma once
#include "TCPSocketConnection.h"
#include "BinaryStream.h"
#include <string_view>

template<typename ClientLogic>
class TCPClient {
public:
    TCPClient();
    ~TCPClient();
    bool Connect(std::string_view address);
    bool Connect(const uint32_t ip, const uint16_t port);

    template<typename Container>
    void Send(const Container &container) {
        m_socket.Send(container);
    }

    void ReceiveAndProcess();

    void Disconnect();
    
    bool Connected();
    
private:
	void Receive();                                         //to m_buffer
	bool HasPackets();										//m_buffer has packets?
    void Process();                                         //from m_buffer

    void OnConnect();
    void OnDisconnect();
    void OnProcess();


private:
    ClientLogic m_logic;

    TCPSocketClient m_socket;
    BinaryStream m_buffer;

};
