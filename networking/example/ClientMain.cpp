#include "TCPClient.h"
#include "GameClientLogic.h"
#include <cstdio>

// example program

int main() {
    printf("Hello, World!\n");
    TCPClient<GameClientLogic> Client;
    Client.Connect("127.0.0.1:1337");

    return 0;
}
