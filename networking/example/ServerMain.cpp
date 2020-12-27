#include "TCPServer.h"
#include "GameServerLogic.h"
#include "GameClientStruct.h"
#include <cstdio>

// example program

int main() {
    printf("Hello, World!\n");
    const uint16_t port = 1337;
    TCPServer<GameServerLogic<GameClientStruct>, GameClientStruct> Server;
    Server.Listen(port);
    Server.Start();
    return 0;
}
