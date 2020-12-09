#include "TCPServer.h"
#include "GameServerVisitor.h"
#include <cstdio>

int main() {
    printf("Hello, World!\n");
    const uint16_t PORT = 1337;
    TCPServer<GameServerVisitor> Server;
    Server.Bind(PORT);
    Server.Start();
    return 0;
}

