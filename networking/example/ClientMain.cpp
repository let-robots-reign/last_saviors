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

    ChatMessagePacket packet("Client", "Sample Text");
    //Client.Send(packet.ToPacket().data());

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    Client.Disconnect();
    
    return 0;
}
