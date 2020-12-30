#pragma once
#include <stdint.h>
#include "BinaryStream.h"

namespace PacketType {
    struct PacketType {
        uint16_t Type;
        PacketType() : Type(0) {}
        PacketType(const uint16_t type) : Type(type) {}
        friend bool operator== (const PacketType & left, const PacketType & right) { return left() == right(); }
        uint16_t operator()() const { return Type; }
        static constexpr size_t size() { return (size_t)sizeof(Type); }
    };
}

struct Packet {
    BinaryStream stream;
    PacketType::PacketType Type() const;
    const std::vector<std::byte> & data() const;
};
//yes, it contains a BinaryStream, which is basically a std::vector<std::byte> with useful serialization methods


// example:
/*
struct ChatMessagePacket {
    std::string name;
    std::string message;

    ChatMessagePacket(const std::string name, const std::string message);
    ChatMessagePacket(const Packet & packet);
    Packet ToPacket() const;
};

// enum alternative, since we can not know what packets are going to be used
namespace PacketType {
    const PacketType ChatMessage = 1337;  // unique
}
*/
