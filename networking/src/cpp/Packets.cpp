#include "../Packets.h"

std::shared_ptr<Packet> ChatMessagePacket::ToPacket() {

}
ChatMessagePacket ChatMessagePacket::Create(std::string_view name, std::string_view message) {

}
ChatMessagePacket ChatMessagePacket::FromPacket(std::shared_ptr<Packet> Packet) {

}


std::shared_ptr<Packet> CreateObjectPacket::ToPacket() {

}
CreateObjectPacket CreateObjectPacket::Create(const uint id, const ObjectType type, const std::vector<std::byte> binary) {

}
CreateObjectPacket CreateObjectPacket::FromPacket(std::shared_ptr<Packet> Packet) {

}


std::shared_ptr<Packet> ModifyObjectPacket::ToPacket() {

}
ModifyObjectPacket ModifyObjectPacket::Create(const uint id, const ObjectType type, const std::vector<std::byte> binary) {

}
ModifyObjectPacket ModifyObjectPacket::FromPacket(std::shared_ptr<Packet> Packet) {

}


std::shared_ptr<Packet> DeleteObjectPacket::ToPacket() {

}
DeleteObjectPacket DeleteObjectPacket::Create(const uint id) {

}
DeleteObjectPacket DeleteObjectPacket::FromPacket(std::shared_ptr<Packet> Packet) {

}


std::shared_ptr<Packet> EventPacket::ToPacket() {

}
EventPacket EventPacket::Create(const EventType type, const std::vector<std::byte> binary) {

}
EventPacket EventPacket::FromPacket(std::shared_ptr<Packet> Packet) {

}

