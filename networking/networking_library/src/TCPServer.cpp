#pragma once
#include "TCPServer.h"
#include "NetworkErrors.h"


template<typename TServerLogic, typename TClient>
TCPServer<TServerLogic, TClient>::TCPServer() : m_logic(*this), m_running(false) {}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::Send(const size_t i, const Packet & packet) {
    m_logic.Send(i, packet);
}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::SendEveryone(const Packet & packet) {
    for (size_t i = 0; i < m_clients.size(); ++i)
        Send(i, packet);
}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::Send(const size_t i, const std::vector<std::byte> & data) {
    m_clients.at(i).Send(data);
}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::SendEveryone(const std::vector<std::byte> & data) {
    for (size_t i = 0; i < m_clients.size(); ++i)
        Send(i, data);
}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::Kick(const size_t i) {
    m_logic.OnDisconnect(i);
    m_clients.erase(m_clients.begin() + i);
}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::Listen(const uint16_t port) {
    m_socket.Listen(port);
}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::Start() {
    m_running = true;
    m_logic.OnStart();
    Loop();
}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::Loop() {
    while (Running()) {
        AcceptClients();
        ReceiveAll();
        ProcessAll();
        KickDisconnected();
        m_logic.OnTick();
    }
}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::AcceptClients() {
    std::unique_ptr<TCPSocketConnectedClient> connected = std::make_unique<TCPSocketConnectedClient>(m_socket.Accept());
    bool alive = connected->alive;
    while (alive) {
        m_clients.push_back(TClient(std::move(connected)));
        m_logic.OnConnect(m_clients.size() - 1);
        connected = std::make_unique<TCPSocketConnectedClient>(m_socket.Accept());
        alive = connected->alive;
    }
}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::Stop() {
    m_running = false;
}

template<typename TServerLogic, typename TClient>
bool TCPServer<TServerLogic, TClient>::Running() {
    return m_running;
}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::ReceiveAll() {
    for (size_t i = 0; i < m_clients.size(); ++i)
        Receive(i);
}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::Receive(const size_t i) {
    m_clients.at(i).Receive();
}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::ProcessAll() {
    for (size_t i = 0; i < m_clients.size(); ++i)
        Process(i);
}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::Process(const size_t i) {
    m_logic.OnProcess(i);
}

template<typename TServerLogic, typename TClient>
TClient & TCPServer<TServerLogic, TClient>::GetClient(const size_t i) {
    return m_clients.at(i);
}

template<typename TServerLogic, typename TClient>
size_t TCPServer<TServerLogic, TClient>::ClientsSize() const {
    return m_clients.size();
}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::KickDisconnected() {
    for (size_t i = 0; i < m_clients.size(); ++i)
        if (!m_clients.at(i).Connected())
            Kick(i--);
}
