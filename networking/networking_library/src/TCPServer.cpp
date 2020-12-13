#pragma once
#include "TCPServer.h"

template<typename TServerLogic, typename TClient>
TCPServer<TServerLogic, TClient>::TCPServer() : m_logic(*this), m_running(false) {}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::Send(const size_t i, const std::vector<std::byte> & data) {
    m_logic.Send(i, data);
}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::SendEveryone(const std::vector<std::byte> & data) {
    for (size_t i = 0; i < m_clients.size(); ++i) {
        Send(i, data);
    }
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
        ReceiveAndProcess();
        m_logic.OnTick();
    }
}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::AcceptClients() {
    TCPSocketConnectedClient connected(std::move(m_socket.Accept()));
    if (connected.alive) {
        m_clients.push_back(TClient(connected));
        m_logic.OnConnect(m_clients.size() - 1);
    }
}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::ReceiveAndProcess() {
    ReceiveAll();
    ProcessAll();
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
void TCPServer<TServerLogic, TClient>::Receive(const size_t i) {
    m_clients.at(i).Receive();
}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::ReceiveAll() {
    for (size_t i = 0; i < m_clients.size(); ++i) {
        Receive(i);
    }
}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::ProcessAll() {
    for (size_t i = 0; i < m_clients.size(); ++i) {
        Process(i);
    }
}

template<typename TServerLogic, typename TClient>
void TCPServer<TServerLogic, TClient>::Process(const size_t i) {
    m_logic.OnProcess(i);
}

template<typename TServerLogic, typename TClient>
TClient & TCPServer<TServerLogic, TClient>::GetClient(const size_t i) {
    return m_clients.at(i);
}
