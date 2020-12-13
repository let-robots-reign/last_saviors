#include "PacketBase.h"

PacketType::PacketTypeStruct Packet::Type() const {
    PacketType::PacketTypeStruct type = 0;
    stream.Read(type);
    return type;
}
