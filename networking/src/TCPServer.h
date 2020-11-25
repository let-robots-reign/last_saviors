#pragma once
#include "TCPSocketConnection.h"
#include "Packet.h"
#include "BinaryStream.h"

struct Client {
public:
    TCPSocketConnectedClient m_socket;
    BinaryStream m_buffer;
};

class TCPServer {
public:
    TCPServer();
    virtual ~TCPServer();

    void Bind(uint16_t port);
    void Start();    

protected:
    std::vector<Client> m_clients;
    

    template <typename Container>
    void Send(const size_t id, const Container &container) {

    }
    template <typename Container>
    void SendEveryone(const Container &container) {

    }

    void ReceiveAndProcess();
    
    void Stop();
    bool Running();

    virtual void OnStart();
    virtual void OnConnect(const size_t id);
    virtual void OnDisconnect(const size_t id);
    virtual void OnProcess(const size_t id);
    virtual void Tick();

private:
    TCPSocketServer m_socket;
    bool m_running;

    void Receive(const size_t i);                                               //to m_buffer
    void ReceiveAll();                                                          //to m_buffer

    void Loop();

};

