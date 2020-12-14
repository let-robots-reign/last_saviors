#include "BinaryStream/Packet.h"

template<>
void BinaryStream::Insert<Packet>(const Packet & packet) {
    const uint64_t packet_size = packet.data().size();
    Insert(packet_size);
    Push(packet.data());
}

template<>
size_t BinaryStream::Read<Packet>(Packet & packet, const size_t offset) const {
    uint64_t packet_size = 0;
    size_t read_offset = 0;
    read_offset += Read(packet_size, read_offset + offset);
    if (read_offset == 0) return 0;
    const std::vector<std::byte> packet_data = Get(packet_size, read_offset + offset);
    if (packet_data.size() == 0) return 0;
    packet = Packet(packet_data);
    return packet_size + packet_data.size();
}

template<>
size_t BinaryStream::Remove<Packet>(const size_t offset) {
    uint64_t packet_size = 0;
    size_t read_offset = 0;
    read_offset += Read(packet_size, read_offset + offset);
    const size_t remove_size = read_offset + packet_size;
    if (m_data.size() < offset + remove_size) return 0;
    Erase(remove_size, offset);
    return remove_size;
}
