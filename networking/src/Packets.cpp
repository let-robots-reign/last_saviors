#include "Packets.h"

#include <iostream>

ChatMessagePacket::ChatMessagePacket(const std::string name, const std::string message) : name(std::move(name)), message(std::move(message)) {}

ChatMessagePacket::ChatMessagePacket(const Packet & packet) {
    size_t offset = 0;
    PacketType::PacketType Type;
    offset += packet.stream.Read(Type, offset);
    offset += packet.stream.Read(name, offset);
    offset += packet.stream.Read(message, offset);
}

Packet ChatMessagePacket::ToPacket() const {
    Packet packet;
    packet.stream.Insert(PacketType::ChatMessage);
    packet.stream.Insert(name);
    packet.stream.Insert(message);
    return packet;
}
