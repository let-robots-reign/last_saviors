#include "gtest/gtest.h"
#include "Packets.h"

TEST(Packets, ChatMessagePacket) {
    const std::string name("grillow1337");
    const std::string message("Sample Text");

    ChatMessagePacket chatpacket(name, message);
    const Packet packet = chatpacket.ToPacket();

    chatpacket = ChatMessagePacket(packet);

    EXPECT_EQ(packet.Type(), PacketType::ChatMessage);
    EXPECT_EQ(chatpacket.name, name);
    EXPECT_EQ(chatpacket.message, message);
}
