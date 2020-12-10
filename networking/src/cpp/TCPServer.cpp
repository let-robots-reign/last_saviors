#pragma once
#include "../TCPServer.h"

template<typename TServerLogic>
TCPServer<TServerLogic>::TCPServer() : m_logic(*this), m_running(false) {}

template<typename TServerLogic>
void TCPServer<TServerLogic>::Send(const size_t i, const std::vector<std::byte> & data) {
    m_logic.Send(i, data);
}

template<typename TServerLogic>
void TCPServer<TServerLogic>::SendEveryone(const std::vector<std::byte> & data) {
    for (size_t i = 0; i < m_clients.size(); ++i) {
        Send(i, data);
    }
}

template<typename TServerLogic>
void TCPServer<TServerLogic>::Bind(const uint16_t port) {
    m_socket.Bind(port);
}

template<typename TServerLogic>
void TCPServer<TServerLogic>::Start() {
    m_running = true;
    Loop();
}

template<typename TServerLogic>
void TCPServer<TServerLogic>::Loop() {
    while (Running()) {
        AcceptClients();
        ReceiveAndProcess();
        OnTick();
    }
}

template<typename TServerLogic>
void TCPServer<TServerLogic>::AcceptClients() {
    while (m_socket.CanAccept()) {
        m_clients.push_back(ServerClient(m_socket.Accept()));
        OnConnect(m_clients.size() - 1);
    }
}

template<typename TServerLogic>
void TCPServer<TServerLogic>::ReceiveAndProcess() {
    ReceiveAll();
    ProcessAll();
}

template<typename TServerLogic>
void TCPServer<TServerLogic>::Stop() {
    m_running = false;
}

template<typename TServerLogic>
bool TCPServer<TServerLogic>::Running() {
    return m_running;
}

template<typename TServerLogic>
void TCPServer<TServerLogic>::OnStart() {
    m_logic.OnStart();
}

template<typename TServerLogic>
void TCPServer<TServerLogic>::OnConnect(const size_t i) {
    m_logic.OnConnect(i);
}

template<typename TServerLogic>
void TCPServer<TServerLogic>::OnDisconnect(const size_t i) {
    m_logic.OnDisconnect(i);
}

template<typename TServerLogic>
void TCPServer<TServerLogic>::OnProcess(const size_t i) {
    m_logic.OnProcess(i);
}

template<typename TServerLogic>
void TCPServer<TServerLogic>::OnTick() {
    m_logic.OnTick();
}

template<typename TServerLogic>
void TCPServer<TServerLogic>::Receive(const size_t i) {
    m_clients.at(i).Receive();
}

template<typename TServerLogic>
void TCPServer<TServerLogic>::ReceiveAll() {
    for (size_t i = 0; i < m_clients.size(); ++i) {
        Receive(i);
    }
}

template<typename TServerLogic>
void TCPServer<TServerLogic>::ProcessAll() {
    for (size_t i = 0; i < m_clients.size(); ++i) {
        Process(i);
    }
}

template<typename TServerLogic>
void TCPServer<TServerLogic>::Process(const size_t i) {
    OnProcess(i);
}

template<typename TServerLogic>
ServerClient & TCPServer<TServerLogic>::GetClient(const size_t i) {
    return m_clients.at(i);
}
