#include "TCPClient.h"
#include "GameClientLogic.h"
#include "Packets.h"
#include <cstdio>
#include <string>
#include <thread>

// example program

int main() {
    // client example

    printf("Hello, World!\n");
    TCPClient<GameClientLogic> Client;

    if ( !Client.Connect(Address(*IPAddress::Create(std::string("127.0.0.1")), 1337)) ) return 0;

    Client.Send(ChatMessagePacket("grillow1337", "First Message").ToPacket());
    Client.Send(ChatMessagePacket("grillow1337", "Second Message").ToPacket());

    Client.Send(QuizRequestPacket().ToPacket());
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    Client.ReceiveAndProcess();
    Client.Send(QuizAnswerPacket(1).ToPacket());
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    Client.ReceiveAndProcess();

    Client.Disconnect();
    
    return 0;
}
