#include "../Packet.h"

Packet::Packet() {

}

Packet::Packet(Packet&&) {

}

Packet::Packet(const Packet &) {

}

Packet& Packet::operator=(const Packet&) {
    
}

PacketType Packet::Type() {

}

const Packet::std::vector<std::byte> &data() const {

}
