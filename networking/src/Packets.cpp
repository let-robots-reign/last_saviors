#include "Packets.h"

#include <iostream>

ChatMessagePacket::ChatMessagePacket(const std::string name, const std::string message) : name(std::move(name)), message(std::move(message)) {}

ChatMessagePacket::ChatMessagePacket(Packet & packet) {
    packet.stream.Erase(PacketType::PacketType::size());
    packet.stream.Extract(name);
    packet.stream.Extract(message);
}

Packet ChatMessagePacket::ToPacket() const {
    Packet packet;
    packet.stream.Insert(PacketType::ChatMessage);
    packet.stream.Insert(name);
    packet.stream.Insert(message);
    return packet;
}
