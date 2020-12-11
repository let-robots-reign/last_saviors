#include "Packets.h"

ChatMessagePacket& ChatMessagePacket::operator=(ChatMessagePacket&&) {

}
std::shared_ptr<Packet> ChatMessagePacket::ToPacket() const {

}
ChatMessagePacket::ChatMessagePacket(std::string_view name, std::string_view message) {

}
ChatMessagePacket ChatMessagePacket::Create(std::string_view name, std::string_view message) {

}
ChatMessagePacket ChatMessagePacket::FromPacket(std::shared_ptr<Packet> Packet) {

}

CreateObjectPacket& CreateObjectPacket::operator=(CreateObjectPacket&&) {
    
}
std::shared_ptr<Packet> CreateObjectPacket::ToPacket() const {

}
CreateObjectPacket::CreateObjectPacket(const uint id, const ObjectType type, const std::vector<std::byte> binary) {

}
CreateObjectPacket CreateObjectPacket::Create(const uint id, const ObjectType type, const std::vector<std::byte> binary) {

}
CreateObjectPacket CreateObjectPacket::FromPacket(std::shared_ptr<Packet> Packet) {

}

ModifyObjectPacket& ModifyObjectPacket::operator=(ModifyObjectPacket&&) {
    
}
std::shared_ptr<Packet> ModifyObjectPacket::ToPacket() const {

}
ModifyObjectPacket::ModifyObjectPacket(const uint id, const ObjectType type, const std::vector<std::byte> binary) {

}
ModifyObjectPacket ModifyObjectPacket::Create(const uint id, const ObjectType type, const std::vector<std::byte> binary) {

}
ModifyObjectPacket ModifyObjectPacket::FromPacket(std::shared_ptr<Packet> Packet) {

}

DeleteObjectPacket& DeleteObjectPacket::operator=(DeleteObjectPacket&&) {
    
}
std::shared_ptr<Packet> DeleteObjectPacket::ToPacket() const {

}
DeleteObjectPacket::DeleteObjectPacket(const uint id) {

}
DeleteObjectPacket DeleteObjectPacket::Create(const uint id) {

}
DeleteObjectPacket DeleteObjectPacket::FromPacket(std::shared_ptr<Packet> Packet) {

}

EventPacket& EventPacket::operator=(EventPacket&&) {
    
}
std::shared_ptr<Packet> EventPacket::ToPacket() const {

}
EventPacket::EventPacket(const EventType type, const std::vector<std::byte> binary) {

}
EventPacket EventPacket::Create(const EventType type, const std::vector<std::byte> binary) {

}
EventPacket EventPacket::FromPacket(std::shared_ptr<Packet> Packet) {

}

