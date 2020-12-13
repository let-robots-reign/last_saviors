#pragma once
#include "PacketBase.h"
#include "BinaryStream.Game.h"
#include <string>

namespace PacketType {
    const PacketType ChatMessage = 1;  // unique
}

struct ChatMessagePacket {
    std::string name;
    std::string message;

    ChatMessagePacket(const std::string name, const std::string message);
    ChatMessagePacket(Packet & packet);
    Packet ToPacket() const;
};
