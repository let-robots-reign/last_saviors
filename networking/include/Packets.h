#pragma once
#include "BinaryStream.Game.h"
#include "PacketBase.h"
#include <string>

namespace PacketType {
    const PacketTypeStruct ChatMessage = 1;  // unique
}

struct ChatMessagePacket {
    std::string name;
    std::string message;

    ChatMessagePacket(const std::string name, const std::string message);
    ChatMessagePacket(Packet & packet);
    Packet ToPacket() const;
};
