#pragma once
#include "Packet.h"

struct ChatMessagePacket : Packet {
public:
    std::shared_ptr<Packet> ToPacket() const override;
    static ChatMessagePacket Create(std::string_view name, std::string_view message);
    static ChatMessagePacket FromPacket(std::shared_ptr<Packet> Packet);
    const std::string m_name;
    const std::string m_message;
};

enum ObjectType : std::underlying_type_t<std::byte> {
    //some types here
};
struct CreateObjectPacket : Packet {
    std::shared_ptr<Packet> ToPacket() const override;
    static CreateObjectPacket Create(const uint id, const ObjectType type, const std::vector<std::byte> binary);
    static CreateObjectPacket FromPacket(std::shared_ptr<Packet> Packet);
    const uint m_id;
    const ObjectType m_object_type;
    const std::vector<std::byte> m_object_binary;
};
struct ModifyObjectPacket : Packet {
    std::shared_ptr<Packet> ToPacket() const override;
    static ModifyObjectPacket Create(const uint id, const ObjectType type, const std::vector<std::byte> binary);
    static ModifyObjectPacket FromPacket(std::shared_ptr<Packet> Packet);
    const uint m_id;
    const ObjectType m_object_type;
    const std::vector<std::byte> m_object_binary;
};
struct DeleteObjectPacket : Packet {
    std::shared_ptr<Packet> ToPacket() const override;
    static DeleteObjectPacket Create(const uint id);
    static DeleteObjectPacket FromPacket(std::shared_ptr<Packet> Packet);
    const uint m_id;
};

enum EventType{}; //not my part
struct EventPacket : Packet {
    std::shared_ptr<Packet> ToPacket() const override;
    static EventPacket Create(const EventType type, const std::vector<std::byte> binary);
    static EventPacket FromPacket(std::shared_ptr<Packet> Packet);
    EventType m_event_type;
    const std::vector<std::byte> m_event_binary;
};
