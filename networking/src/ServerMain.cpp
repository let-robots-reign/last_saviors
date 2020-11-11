#include "GameTCPServer.h"

int main() {
    const uint16_t PORT = 1337;
    GameTCPServer Server;
    Server.Bind(PORT);
    Server.Start();
    return 0;
}
