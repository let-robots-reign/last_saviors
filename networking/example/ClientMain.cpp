#include "TCPClient.h"
#include "GameClientLogic.h"
#include "Packets.h"
#include <cstdio>
#include <string>
#include <thread>

// example program

int main() {
    printf("Hello, World!\n");
    TCPClient<GameClientLogic> Client;

    Client.Connect(Address(*IPAddress::Create(std::string("127.0.0.1")), 1337));

    Client.Send(ChatMessagePacket("grillow1337", "First Message").ToPacket());
    Client.Send(ChatMessagePacket("grillow1337", "Second Message").ToPacket());

    std::this_thread::sleep_for(std::chrono::milliseconds(10000));   // sending and receiving has delays

    Client.ReceiveAndProcess();

    Client.Disconnect();
    
    return 0;
}
