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

template<typename ServerLogic>
class TCPServer {
public:
    TCPServer();
    ~TCPServer() = default;

    void Bind(const uint16_t port);
    void Start();    

public:                                         //for ServerLogic

    void Send(const size_t i, const std::vector<std::byte> & data);

    template <typename Container>
    void SendEveryone(const Container & container) {
        for (size_t i = 0; i < m_clients.size(); ++i) {
            Send(i, container);
        }
    }

    void ReceiveAndProcess();    

    void Stop();
    bool Running();
    void Loop();

    ServerClient & GetClient(const size_t id);

    // ServerLogic's methods
    void OnStart();
    void OnConnect(const size_t i);
    void OnDisconnect(const size_t i);
    void OnProcess(const size_t i);
    void OnTick();


private:
    void ReceiveAll();                          //to m_buffer
    void Receive(const size_t i);               //to m_buffer

    void ProcessAll();                          //from m_buffer
    void Process(const size_t i);               //from m_buffer

    void AcceptClients();


private:
    ServerLogic m_logic;

    TCPSocketServer m_socket;
    std::vector<ServerClient> m_clients;
    
    bool m_running;

};
