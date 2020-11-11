#include "gtest/gtest.h"
#include "TCPSocketConnection.h"

TEST(basic_networking, SocketAddress) {
    const std::string localhost1337("127.0.0.1:1337");
    SocketAddress address1 = *(SocketAddress::Create(localhost1337));
    EXPECT_TRUE(localhost1337 == address1.ToString());
}

TEST(basic_networking, BasicClientServer_ok) {
    const SocketAddress address = *(SocketAddress:Create("127.0.0.1:1337"));
    const std::vector<std::byte> data {0x1, 0x3, 0x3, 0x7};

    TCPSocketServer server;
    server.Bind(1337);

    TCPSocketClient client;
    client.Connect(address);

    EXPECT_TRUE(server.CanAccept());
    TCPSocketConnectedClient connected_client = server.Accept();
    EXPECT_FALSE(server.CanAccept());
    EXPECT_TRUE(client.Connected());

    client.Send(data);
    EXPECT_TRUE(connected_client.HasData());
    const std::vector<std::byte> received = connected_client.Receive();

    ASSERT_THAT(received, ElementsAre(0x1, 0x3, 0x3, 0x7));
    EXPECT_FALSE(connected_client.HasData());

    client.Disconnect();
    EXPECT_FALSE(client.Connected());
    
    EXPECT_TRUE(localhost1337 == address1.ToString());
}
