#pragma once
#include "TCPSocketConnection.h"
#include "BinaryStream.h"

struct Client {
public:
    TCPSocketConnectedClient m_socket;
    BinaryStream m_buffer;
};

template<typename ServerVisitor>
class TCPServer {
public:
    TCPServer();
    virtual ~TCPServer();

    void Bind(const uint16_t port);
    void Start();    

private:    

    template <typename Container>
    void Send(const size_t id, const Container &container) {

    }
    template <typename Container>
    void SendEveryone(const Container &container) {

    }

    void ReceiveAndProcess();
    void ReceiveAll();                          //to m_buffer
    void Receive(const size_t i);               //to m_buffer
    
    void Stop();
    bool Running();
    void Loop();


    void OnStart();
    void OnConnect(const size_t id);
    void OnDisconnect(const size_t id);
    void OnProcess(const size_t id);
    void Tick();

private:
    ServerVisitor m_visitor;
    std::vector<Client> m_clients;

    TCPSocketServer m_socket;
    bool m_running;

};
