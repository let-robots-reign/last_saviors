#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "TCPSocketConnection.h"

using namespace testing;


// TEST(basic_networking, SocketAddress) {
//     const std::string localhost1337("127.0.0.1:1337");
//     SocketAddress address = *(SocketAddress::Create(localhost1337));
    
//     EXPECT_EQ(localhost1337, address.ToString());
// }

// infinite loop or something...

// TEST(basic_networking, BasicClientServer_ok) {
//     const std::string localhost1337("127.0.0.1:1337");
//     const SocketAddress address = *(SocketAddress::Create(localhost1337));
//     const std::vector<std::byte> data {std::byte{0x1}, std::byte{0x3}, std::byte{0x3}, std::byte{0x7}};

//     TCPSocketServer server;
//     server.Bind(1337);

//     TCPSocketClient client;
//     client.Connect(address);

//     EXPECT_TRUE(server.CanAccept());
//     TCPSocketConnectedClient connected_client = server.Accept();
//     EXPECT_FALSE(server.CanAccept());
//     EXPECT_TRUE(client.Connected());

//     client.Send(data);
//     EXPECT_TRUE(connected_client.HasData());
//     const std::vector<std::byte> received = connected_client.Receive();

//     ASSERT_THAT(received, ElementsAre(std::byte{0x1}, std::byte{0x3}, std::byte{0x3}, std::byte{0x7}));
//     EXPECT_FALSE(connected_client.HasData());

//     client.Disconnect();
//     EXPECT_FALSE(client.Connected());
    
//     EXPECT_EQ(localhost1337, address.ToString());
// }
