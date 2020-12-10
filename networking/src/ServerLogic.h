#pragma once
#include "TCPServer.h"

struct ServerLogic {
    friend class TCPServer<ServerLogic>;
private:
    //TCPServer<ServerLogic> & Server;

public:
    ServerLogic() = default;

private:
    
    ServerLogic(TCPServer<ServerLogic> & server) /*: Server(server)*/ {}

    void Send(const size_t i, const std::vector<std::byte> & data) {}

    void OnStart() {}

    void OnTick() {}

    void OnConnect(const size_t i) {}

    void OnDisconnect(const size_t i) {}

    void OnProcess(const size_t i) {}

};
