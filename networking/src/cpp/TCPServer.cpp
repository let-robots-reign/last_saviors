#pragma once
#include "../TCPServer.h"

template<typename ServerLogic>
TCPServer<ServerLogic>::TCPServer() : m_visitor(*this), m_running(false) {}

template<typename ServerLogic>
void TCPServer<ServerLogic>::Bind(const uint16_t port) {
    m_socket.Bind(port);
}

template<typename ServerLogic>
void TCPServer<ServerLogic>::Start() {
    m_running = true;
    Loop();
}

template<typename ServerLogic>
void TCPServer<ServerLogic>::Loop() {
    while (Running()) {
        AcceptClients();
        ReceiveAndProcess();
        Tick();
    }
}

template<typename ServerLogic>
void TCPServer<ServerLogic>::AcceptClients() {
    while (m_socket.CanAccept()) {
        m_clients.push_back(ServerClient(m_socket.Accept()));
        OnConnect(m_clients.size() - 1);
    }
}

template<typename ServerLogic>
void TCPServer<ServerLogic>::ReceiveAndProcess() {
    ReceiveAll();
    ProcessAll();
}

template<typename ServerLogic>
void TCPServer<ServerLogic>::Stop() {
    m_running = false;
}

template<typename ServerLogic>
bool TCPServer<ServerLogic>::Running() {
    return m_running;
}

template<typename ServerLogic>
void TCPServer<ServerLogic>::OnStart() {
    m_visitor.OnStart();
}

template<typename ServerLogic>
void TCPServer<ServerLogic>::OnConnect(const size_t i) {
    m_visitor.OnConnect(i);
}

template<typename ServerLogic>
void TCPServer<ServerLogic>::OnDisconnect(const size_t i) {
    m_visitor.OnDisconnect(i);
}

template<typename ServerLogic>
void TCPServer<ServerLogic>::OnProcess(const size_t i) {
    m_visitor.OnProcess(i);
}

template<typename ServerLogic>
void TCPServer<ServerLogic>::Tick() {
    m_visitor.Tick();
}

template<typename ServerLogic>
void TCPServer<ServerLogic>::Receive(const size_t i) {
    m_clients.at(i).Receive();
}

template<typename ServerLogic>
void TCPServer<ServerLogic>::ReceiveAll() {
    for (size_t i = 0; i < m_clients.size(); ++i) {
        Receive(i);
    }
}

template<typename ServerLogic>
void TCPServer<ServerLogic>::ProcessAll() {
    for (size_t i = 0; i < m_clients.size(); ++i) {
        Process(i);
    }
}

template<typename ServerLogic>
void TCPServer<ServerLogic>::Process(const size_t i) {
    OnProcess(i);
}

template<typename ServerLogic>
const ServerClient & TCPServer<ServerLogic>::GetClient(const size_t i) const {
    return m_clients.at(i);
}
