#pragma once
#include "Packet.h"

struct ChatMessagePacket {
public:
    std::shared_ptr<Packet> ToPacket() const override;
    static ChatMessagePacket Create(std::string_view name, std::string_view message);
    static ChatMessagePacket FromPacket(std::shared_ptr<Packet> Packet);
    const std::string m_name;
    const std::string m_message;
}

enum ObjectType : std::byte {
    //some types here
}
struct CreateObjectPacket {
    std::shared_ptr<Packet> ToPacket() const override;
    static CreateObjectPacket Create(const uint id, const ObjectType type, const std::vector<std::byte> binary);
    static CreateObjectPacket FromPacket(std::shared_ptr<Packet> Packet);
    const uint m_id;
    const ObjectType m_object_type;
    const std::vector<std::byte> m_object_binary;
}
struct ModifyObjectPacket {
    std::shared_ptr<Packet> ToPacket() const override;
    static ModifyObjectPacket Create(const uint id, const ObjectType type, const std::vector<std::byte> binary);
    static ModifyObjectPacket FromPacket(std::shared_ptr<Packet> Packet);
    const uint m_id;
    const ObjectType m_object_type;
    const std::vector<std::byte> m_object_binary;
}
struct DeleteObjectPacket {
    std::shared_ptr<Packet> ToPacket() const override;
    static DeleteObjectPacket Create(const uint id);
    static DeleteObjectPacket FromPacket(std::shared_ptr<Packet> Packet);
    const uint m_id;
}

enum EventType; //not my part
struct EventPacket {
    std::shared_ptr<Packet> ToPacket() const override;
    static EventPacket Create(const EventType type, const std::vector<std::byte> binary);
    static EventPacket FromPacket(std::shared_ptr<Packet> Packet);
    EventType m_event_type;
    const std::vector<std::byte> m_event_binary;
}
