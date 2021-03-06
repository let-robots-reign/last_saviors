#pragma once
#include "TCPSocketConnection.h"
#include "PacketBase.h"


template<typename TServerLogic, typename TClient>
class TCPServer {
public:
    TCPServer();
    ~TCPServer() = default;

    void Listen(const uint16_t port);
    void Start();    

public:                                         //for ServerLogic

    void Stop();
    bool Running();

    void Send(const size_t i, const Packet & packet);
    void SendEveryone(const Packet & packet);
    void Send(const size_t i, const std::vector<std::byte> & data);
    void SendEveryone(const std::vector<std::byte> & data);

    void Kick(const size_t i);

    TClient & GetClient(const size_t i);
    size_t ClientsSize() const;


private:
    void Loop();								//mb delegate it to TServerLogic

    void ReceiveAll();                          //to m_buffer
    void Receive(const size_t i);               //to m_buffer

    void ProcessAll();                          //from m_buffer
    void Process(const size_t i);               //from m_buffer

    void AcceptClients();

    void KickDisconnected();


private:
    TServerLogic m_logic;

    TCPSocketServer m_socket;
    std::vector<TClient> m_clients;
    
    bool m_running;

};
