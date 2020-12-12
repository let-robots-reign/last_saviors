#pragma once
#include <vector>
#include <memory>

//size is important. 256 types of packets is enough
enum PacketType : int8_t {
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

///TODO: refactor Packets
///TODO: add PacketDispatcher with std::map<PacketType, lambda that takes Packet, returns void, containes logic>
// something like this
// struct Packet {
//     const std::vector<std::byte> data;
//     PacketType Type();

//     template<typename PacketChild>
//     PacketChild FromPacket();
// };

// struct PacketChild {
//     const std::string message;
//     Packet ToPacket() const;
// };
