#include "../TCPServer.h"


TCPServer::TCPServer() {

}
TCPServer::~TCPServer() {

}

void TCPServer::Bind(uint16_t port) {

}
void TCPServer::Start() {
    Loop();
}

void TCPServer::ReceiveAndProcess() {

}

void TCPServer::Stop() {

}

bool TCPServer::Running() {
    return m_running;
}

void TCPServer::OnStart() {
    
}
void TCPServer::OnConnect(const size_t id) {

}
void TCPServer::OnDisconnect(const size_t id) {

}
void TCPServer::OnProcess(const size_t i_client) {

}
void TCPServer::Tick() {

}


void TCPServer::Receive(const size_t i) {

}
void TCPServer::ReceiveAll() {

}

void TCPServer::Loop() {
    while (Running()) {
        ReceiveAndProcess();
        Tick();
        //sleep(...); //to have constant amount of ticks per second
    }
}

