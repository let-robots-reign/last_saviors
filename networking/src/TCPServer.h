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

    template <typename Container>
    void Send(const size_t i_client, const Container &container) {

    }
    template <typename Container>
    void SendEveryone(const Container &container) {

    }

    void ReceiveAndProcess();
    
    void Stop();

    virtual void OnConnect(const size_t id);
    virtual void OnDisconnect(const size_t id);
    virtual void OnProcess(const size_t id);
    virtual void Tick();

private:
    TCPSocketServer m_socket;
    std::vector<BinaryStream> m_buffer;

    void Receive(const size_t i);                                               //to m_buffer
    void ReceiveAll();                                                          //to m_buffer

    void Loop();

};

