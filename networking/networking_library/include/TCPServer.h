#pragma once
#include "TCPSocketConnection.h"


template<typename TServerLogic, typename TClient>
class TCPServer {
public:
    TCPServer();
    ~TCPServer() = default;

    void Bind(const uint16_t port);
    void Start();    

public:                                         //for ServerLogic

    void Stop();
    bool Running();

    void Send(const size_t i, const std::vector<std::byte> & data);
    void SendEveryone(const std::vector<std::byte> & data);

    TClient & GetClient(const size_t i);


private:
    void Loop();								//mb delegate it to TServerLogic
    void ReceiveAndProcess(); 

    void ReceiveAll();                          //to m_buffer
    void Receive(const size_t i);               //to m_buffer

    void ProcessAll();                          //from m_buffer
    void Process(const size_t i);               //from m_buffer

    void AcceptClients();


private:
    TServerLogic m_logic;

    TCPSocketServer m_socket;
    std::vector<TClient> m_clients;
    
    bool m_running;

};
