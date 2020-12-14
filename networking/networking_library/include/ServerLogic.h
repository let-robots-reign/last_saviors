#pragma once
#include "TCPServer.h"
#include "PacketBase.h"

template<typename TClient>
struct ServerLogic {
    friend class TCPServer<ServerLogic<TClient>, TClient>;

public:
    ServerLogic() = default;

private:
    
    ServerLogic(TCPServer<ServerLogic<TClient>, TClient> & server) {}

    void Send(const size_t i, const Packet & packet) {}

    void Send(const size_t i, const std::vector<std::byte> & data) {}

    void OnStart() {}

    void OnTick() {}

    void OnConnect(const size_t i) {}

    void OnDisconnect(const size_t i) {}

    void OnProcess(const size_t i) {}

};
