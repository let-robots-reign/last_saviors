#include "gtest/gtest.h"
#include "Packets.h"

TEST(Packets, ChatMessagePacket) {
    const std::string name("grillow1337");
    const std::string message("Sample Text");

    ChatMessagePacket chatpacket(name, message);

    chatpacket = ChatMessagePacket(chatpacket.ToPacket());

    EXPECT_EQ(chatpacket.name, name);
    EXPECT_EQ(chatpacket.message, message);
}
