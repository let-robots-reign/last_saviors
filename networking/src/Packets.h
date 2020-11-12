#pragma once
#include "Packet.h"
#include <string_view>

//no time to write all the implementations -> unconst
/*const*/

struct ChatMessagePacket : Packet {
public:
    ChatMessagePacket& operator=(ChatMessagePacket&&);
    std::shared_ptr<Packet> ToPacket() const override;
    ChatMessagePacket (std::string_view name, std::string_view message);
    static ChatMessagePacket Create(std::string_view name, std::string_view message);
    static ChatMessagePacket FromPacket(std::shared_ptr<Packet> Packet);
    /*const*/ std::string m_name;
    /*const*/ std::string m_message;
};

enum ObjectType : std::underlying_type_t<std::byte> {
    //some types here
};
struct CreateObjectPacket : Packet {
    CreateObjectPacket& operator=(CreateObjectPacket&&);
    std::shared_ptr<Packet> ToPacket() const override;
    CreateObjectPacket (const uint id, const ObjectType type, const std::vector<std::byte> binary);
    static CreateObjectPacket Create(const uint id, const ObjectType type, const std::vector<std::byte> binary);
    static CreateObjectPacket FromPacket(std::shared_ptr<Packet> Packet);
    /*const*/ uint m_id;
    /*const*/ ObjectType m_object_type;
    /*const*/ std::vector<std::byte> m_object_binary;
};
struct ModifyObjectPacket : Packet {
    ModifyObjectPacket& operator=(ModifyObjectPacket&&);
    std::shared_ptr<Packet> ToPacket() const override;
    ModifyObjectPacket (const uint id, const ObjectType type, const std::vector<std::byte> binary);
    static ModifyObjectPacket Create(const uint id, const ObjectType type, const std::vector<std::byte> binary);
    static ModifyObjectPacket FromPacket(std::shared_ptr<Packet> Packet);
    /*const*/ uint m_id;
    /*const*/ ObjectType m_object_type;
    /*const*/ std::vector<std::byte> m_object_binary;
};
struct DeleteObjectPacket : Packet {
    DeleteObjectPacket& operator=(DeleteObjectPacket&&);
    std::shared_ptr<Packet> ToPacket() const override;
    DeleteObjectPacket (const uint id);
    static DeleteObjectPacket Create(const uint id);
    static DeleteObjectPacket FromPacket(std::shared_ptr<Packet> Packet);
    /*const*/ uint m_id;
};

enum EventType{}; //not my part
struct EventPacket : Packet {
    EventPacket& operator=(EventPacket&&);
    std::shared_ptr<Packet> ToPacket() const override;
    EventPacket (const EventType type, const std::vector<std::byte> binary);
    static EventPacket Create(const EventType type, const std::vector<std::byte> binary);
    static EventPacket FromPacket(std::shared_ptr<Packet> Packet);
    EventType m_event_type;
    /*const*/ std::vector<std::byte> m_event_binary;
};
