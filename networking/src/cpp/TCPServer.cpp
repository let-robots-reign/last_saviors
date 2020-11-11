#include "../TCPServer.h"


TCPServer::TCPServer() {

}
TCPServer::~TCPServer() {

}

void TCPServer::Bind(uint16_t port) {

}
void TCPServer::Start() {

}

void TCPServer::Send(const size_t i_client, std::shared_ptr<Packet> packet) {

}
void TCPServer::SendEveryone(std::shared_ptr<Packet> packet) {

}

void TCPServer::ReceiveAndProcess() {

}

void TCPServer::Stop() {

}

void TCPServer::OnConnect(const size_t id) {

}
void TCPServer::OnDisconnect(const size_t id) {

}
void TCPServer::ProcessPacket(const size_t i_client, std::shared_ptr<Packet> packet) {

}
void TCPServer::Tick() {

}


void TCPServer::Receive(const size_t i) {

}
void TCPServer::ReceiveAll() {

}

void TCPServer::Loop() {

}


