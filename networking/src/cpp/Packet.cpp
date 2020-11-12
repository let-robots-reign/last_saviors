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

const std::vector<std::byte> & Packet::data() const {

}
