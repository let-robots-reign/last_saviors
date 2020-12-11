#include "TCPServer.h"
#include "ClientStruct.h"
#include "GameServerLogic.h"
#include <cstdio>

// example program

int main() {
    printf("Hello, World!\n");
    const uint16_t port = 1337;
    TCPServer<GameServerLogic<ClientStruct>, ClientStruct> Server;
    Server.Bind(port);
    Server.Start();
    return 0;
}
