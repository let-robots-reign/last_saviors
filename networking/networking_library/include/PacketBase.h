#pragma once
#include <stdint.h>
#include "BinaryStream.h"

namespace PacketType {
    struct PacketType {
        const uint16_t Type;
        PacketType(const uint16_t type) : Type(type) {}
        uint16_t operator()() const { return Type; }
        static constexpr size_t size() { return (size_t)sizeof(Type); }
    };
}

struct Packet {
    BinaryStream stream;
    PacketType::PacketType Type() const;
};
//yes it contains a BinaryStream, which is basically a std::vector<std::byte> with useful serialization methods


// example:
/*
struct ChatMessagePacket {
    std::string name;
    std::string message;

    ChatMessagePacket(const std::string name, const std::string message);
    ChatMessagePacket(Packet & packet);
    Packet ToPacket() const;
};

namespace PacketType {
    const PacketType ChatMessage = 1337;  // unique
}
*/
