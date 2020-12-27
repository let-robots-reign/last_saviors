#include "gtest/gtest.h"
#include "BinaryStream.Game.h"
#include "Packets.h"
#include <string>

TEST(BinaryStream, string) {
    const std::string string0("Sample Text");
    std::string string1("");

    BinaryStream stream;
    stream.Insert(string0);
    stream.Extract(string1);

    EXPECT_EQ(stream.data().size(), 0);
    EXPECT_EQ(string0, string1);
}

TEST(BinaryStream, packet) {
    const std::string name("grillow1337");
    const std::string message("Sample Text");
    ChatMessagePacket chatpacket(name, message);
    Packet packet = chatpacket.ToPacket();

    BinaryStream stream;
    stream.Insert(packet);
    Packet packet_new;
    stream.Extract(packet_new);

    ChatMessagePacket chatpacket_new = ChatMessagePacket(packet_new);

    EXPECT_EQ(stream.data().size(), 0);
    EXPECT_EQ(packet_new.Type(), PacketType::ChatMessage);
    EXPECT_EQ(chatpacket_new.name, name);
    EXPECT_EQ(chatpacket_new.message, message);
}

TEST(BinaryStream, incomplete_packet_one) {
    const uint64_t size = 20;
    const uint32_t data = 1337;
    BinaryStream stream;
    stream << size;
    stream << data;
    Packet packet;

    const size_t stream_size = stream.data().size();
    const size_t read = stream.Extract(packet);

    EXPECT_EQ(stream_size, stream.data().size());
    EXPECT_EQ(read, 0);
}

TEST(BinaryStream, incomplete_packet_two) {
    const uint64_t size = 20;
    BinaryStream stream;
    stream << size;
    Packet packet;

    const size_t stream_size = stream.data().size();
    const size_t read = stream.Extract(packet);

    EXPECT_EQ(stream_size, stream.data().size());
    EXPECT_EQ(read, 0);
}

TEST(BinaryStream, incomplete_packet_three) {
    const uint16_t some_data = 20;
    BinaryStream stream;
    stream << some_data;
    Packet packet;

    const size_t stream_size = stream.data().size();
    const size_t read = stream.Extract(packet);

    EXPECT_EQ(stream_size, stream.data().size());
    EXPECT_EQ(read, 0);
}
