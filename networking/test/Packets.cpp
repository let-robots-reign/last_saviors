#include "gtest/gtest.h"
#include "Packets.h"

TEST(Packets, ChatPacket) {
    const std::string name("grillow1337");
    const std::string message("Sample Text");

    ChatMessagePacket packet = ChatMessagePacket::Create(name, message);
    EXPECT_TRUE(packet.m_name == name);
    EXPECT_TRUE(packet.m_message == messsage);

    packet = ChatMessagePacket::FromPacket(packet.ToPacket());
    EXPECT_TRUE(packet.m_name == name);
    EXPECT_TRUE(packet.m_message == messsage);
}

TEST(Packets, DeleteObjectPacket) {
    const uint id = 1337;
    
    DeleteObjectPacket packet = ChatMessagePacket::Create(id);
    EXPECT_TRUE(packet.m_id == id);

    packet = DeleteObjectPacket::FromPacket(packet.ToPacket());
    EXPECT_TRUE(packet.m_id == id);
}

/*
    need to import game objects to overload serialization methods for them
*/
