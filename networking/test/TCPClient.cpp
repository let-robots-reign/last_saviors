#include "gtest/gtest.h"
#include "TCPClient.h"
#include "NetworkErrors.h"


TEST(TCPClient, send_throw) {
    TCPClient client;
    EXPECT_FALSE(client.Connect("wrong address"));
    EXPECT_FALSE(client.Connected());
    bool thrown = false;
    try {
        const std::string data("sample text");
        client.Send(data);
    }
    catch (const SocketError & error) {
        thrown = true;
    }
    EXPECT_TRUE(thrown);
}

