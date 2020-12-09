#pragma once
#include "../TCPServer.h"

template<typename ServerVisitor>
TCPServer<ServerVisitor>::TCPServer() : m_visitor(*this), m_running(false) {

}

template<typename ServerVisitor>
TCPServer<ServerVisitor>::~TCPServer() {

}

template<typename ServerVisitor>
void TCPServer<ServerVisitor>::Bind(const uint16_t port) {

}

template<typename ServerVisitor>
void TCPServer<ServerVisitor>::Start() {
    m_running = true;
    Loop();
}

template<typename ServerVisitor>
void TCPServer<ServerVisitor>::ReceiveAndProcess() {

}

template<typename ServerVisitor>
void TCPServer<ServerVisitor>::Stop() {
    m_running = false;
}

template<typename ServerVisitor>
bool TCPServer<ServerVisitor>::Running() {
    return m_running;
}

/*
    visitor section starts
*/

template<typename ServerVisitor>
void TCPServer<ServerVisitor>::OnStart() {
    m_visitor.OnStart();
}

template<typename ServerVisitor>
void TCPServer<ServerVisitor>::OnConnect(const size_t id) {
    m_visitor.OnConnect(id);
}

template<typename ServerVisitor>
void TCPServer<ServerVisitor>::OnDisconnect(const size_t id) {
    m_visitor.OnDisconnect(id);
}

template<typename ServerVisitor>
void TCPServer<ServerVisitor>::OnProcess(const size_t i_client) {
    m_visitor.OnProcess(i_client);
}

template<typename ServerVisitor>
void TCPServer<ServerVisitor>::Tick() {
    m_visitor.Tick();
}

/*
    visitor section ends
*/

template<typename ServerVisitor>
void TCPServer<ServerVisitor>::Receive(const size_t i) {

}

template<typename ServerVisitor>
void TCPServer<ServerVisitor>::ReceiveAll() {

}

template<typename ServerVisitor>
void TCPServer<ServerVisitor>::Loop() {
    while (Running()) {
        ReceiveAndProcess();
        Tick();
        //sleep(...); //to have constant amount of ticks per second
    }
}
