#include "PacketBase.h"

PacketType::PacketType Packet::Type() const {
    PacketType::PacketType type = 0;
    stream.Read(type);
    return type;
}

Packet::Packet(const std::vector<std::byte> & data) : stream(data) {}

const std::vector<std::byte> & Packet::data() const {
    return stream.data();
}
