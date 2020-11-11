#include "../TCPClient.h"


TCPClient::TCPClient() {

}
TCPClient::~TCPClient() {

}
bool TCPClient::Connect(std::string_view address) {

}
bool TCPClient::Connect(const uint32_t ip, const uint16_t port) {

}

void TCPClient::Send(std::shared_ptr<Packet>) {

}

void TCPClient::ReceiveAndProcess() {

}

void TCPClient::Disconnect() {

}

bool TCPClient::Connected() {

}

void TCPClient::Receive() {

}
bool TCPClient::HasPackets() {

}



