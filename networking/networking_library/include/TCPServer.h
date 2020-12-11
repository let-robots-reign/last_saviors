#pragma once
#include "TCPSocketConnection.h"
#include "BinaryStream.h"


struct ServerClient {
    ServerClient(TCPSocketConnectedClient socket) : m_socket(socket) {}

    TCPSocketConnectedClient m_socket;
    BinaryStream m_buffer;

    void Send(const std::vector<std::byte> & data) {
        m_socket.Send(data);
    }

    void Receive() {
        if (m_socket.HasData())
            m_buffer.Push(m_socket.Receive());
    }

};


template<typename TServerLogic, typename TClient = ServerClient>
class TCPServer {
public:
    TCPServer();
    ~TCPServer() = default;

    void Bind(const uint16_t port);
    void Start();    

public:                                         //for ServerLogic

    void Send(const size_t i, const std::vector<std::byte> & data);

    void SendEveryone(const std::vector<std::byte> & data);

    void Stop();
    bool Running();

    TClient & GetClient(const size_t id);

    // ServerLogic's methods
    void OnStart();
    void OnConnect(const size_t i);
    void OnDisconnect(const size_t i);
    void OnProcess(const size_t i);
    void OnTick();


private:
    void Loop();
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
