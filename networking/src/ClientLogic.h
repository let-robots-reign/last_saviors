#pragma once
#include "TCPClient.h"

struct ClientLogic {
    friend class TCPClient<ClientLogic>;
private:
    //TCPClient<ClientLogic> & Client;

public:
    ClientLogic() = default;

private:
    
    ClientLogic(TCPClient<ClientLogic> & client) /*: Client(client)*/ {}

    void Send(const std::vector<std::byte> & data) {}

    void OnConnect() {}

    void OnDisconnect() {}

    void OnProcess() {}

};
