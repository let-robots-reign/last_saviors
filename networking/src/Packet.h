#pragma once
#include <vector>
#include <memory>

//size is important. 256 types of packets is enough
enum PacketType : std::underlying_type_t<std::byte> {
    CREATE_OBJECT,
    MODIFY_OBJECT,
    DELETE_OBJECT,
    CHAT_MESSAGE,
    EVENT,
    PUZZLE_REQUEST,
    PUZZLE_SOLUTION
    //...
    
};

struct Packet {
    Packet();
    Packet(Packet &&);
    Packet(const Packet &);
    Packet& operator=(const Packet &);
    virtual std::shared_ptr<Packet> ToPacket() const = 0;
    PacketType Type();

    const std::vector<std::byte> &data() const;

protected:
    const std::vector<std::byte> m_data;

};

