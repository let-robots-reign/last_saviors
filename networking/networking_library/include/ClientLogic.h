#pragma once
#include "TCPClient.h"

struct ClientLogic {
    friend class TCPClient<ClientLogic>;

public:
    ClientLogic() = default;

private:
    
    ClientLogic(TCPClient<ClientLogic> & client) {}

    void Send(const std::vector<std::byte> & data) {}

    void OnConnect() {}

    void OnDisconnect() {}

    void OnProcess() {}

};
