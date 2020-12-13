#include "TCPClient.h"
#include "GameClientLogic.h"
#include <cstdio>

// example program

int main() {
    printf("Hello, World!\n");
    TCPClient<GameClientLogic> Client;
    //Client.Connect("127.0.0.1:1337");
    //             127.0.0.1
    Client.Connect(2130706433, 1337);
    Client.Disconnect();
    
    return 0;
}
