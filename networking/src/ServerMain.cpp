#include "GameServer.h"

int main() {
    const uint16_t PORT = 1337;
    GameServer Server;
    Server.Bind(PORT);
    Server.Start();
    return 0;
}
