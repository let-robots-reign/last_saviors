#include "TCPClient.h"
#include "GameClientLogic.h"
#include <cstdio>
#include <string>
// example program

int main() {
    printf("Hello, World!\n");
    TCPClient<GameClientLogic> Client;

    Client.Connect(Address(*IPAddress::Create(std::string("127.0.0.1")), 1337));

    Client.Disconnect();
    
    return 0;
}
