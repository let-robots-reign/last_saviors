#include "TCPServer.h"
#include "GameServerLogic.h"
#include <cstdio>

// example program

int main() {
    printf("Hello, World!\n");
    const uint16_t PORT = 1337;
    TCPServer<GameServerLogic> Server;
    Server.Bind(PORT);
    Server.Start();
    return 0;
}
