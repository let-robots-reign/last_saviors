#pragma once
#include "TCPSocketConnection.h"
#include "Packet.h"
#include "BinaryStream.h"

class TCPServer {
public:
    TCPServer();
    virtual ~TCPServer();

    void Bind(uint16_t port);
    void Start();    

protected:
    std::vector<TCPSocketConnectedClient> m_clients;

    void Send(const size_t i_client, const Packet &packet);
    void SendEveryone(const Packet &packet);

    void ReceiveAndProcess();

    virtual void OnConnect(const size_t id);
    virtual void OnDisconnect(const size_t id);
    virtual void ProcessPacket(const size_t i_client, const Packet &packet);
    virtual void Tick();

private:
    TCPSocketServer m_socket;
    std::vector<BinaryStream> m_buffer;

    void Receive(const size_t i);                                               //to m_buffer
    void ReceiveAll();                                                          //to m_buffer

    void Loop();

}
