#include "PacketBase.h"

PacketType::PacketType Packet::Type() const {
    PacketType::PacketType type = 0;
    stream.Read(type);
    return type;
}
