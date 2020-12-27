#include "Packets.h"


ChatMessagePacket::ChatMessagePacket(const std::string name, const std::string message) : name(std::move(name)), message(std::move(message)) {}

ChatMessagePacket::ChatMessagePacket(const Packet & packet) {
    size_t offset = 0;
    PacketType::PacketType Type;
    offset += packet.stream.Read(Type, offset);
    offset += packet.stream.Read(name, offset);
    offset += packet.stream.Read(message, offset);
}

Packet ChatMessagePacket::ToPacket() const {
    Packet packet;
    packet.stream.Insert(PacketType::ChatMessage);
    packet.stream.Insert(name);
    packet.stream.Insert(message);
    return packet;
}



QuizRequestPacket::QuizRequestPacket() {}

QuizRequestPacket::QuizRequestPacket(const Packet & packet) {
    size_t offset = 0;
    PacketType::PacketType Type;
    offset += packet.stream.Read(Type, offset);
}

Packet QuizRequestPacket::ToPacket() const {
    Packet packet;
    packet.stream.Insert(PacketType::QuizRequestPacket);
    return packet;
}


#include <iostream>
QuizResponsePacket::QuizResponsePacket(const ClientQuiz & quiz) : quiz(quiz) {
    std::cout << this->quiz.question << std::endl;
}

QuizResponsePacket::QuizResponsePacket(const Packet & packet) {
    size_t offset = 0;
    PacketType::PacketType Type;
    offset += packet.stream.Read(Type, offset);
    offset += packet.stream.Read(quiz, offset);
}

Packet QuizResponsePacket::ToPacket() const {
    Packet packet;
    packet.stream.Insert(PacketType::QuizResponsePacket);
    packet.stream.Insert(quiz);
    return packet;
}



QuizAnswerPacket::QuizAnswerPacket(const uint8_t & answer) : answer(answer) {}

QuizAnswerPacket::QuizAnswerPacket(const Packet & packet) {
    size_t offset = 0;
    PacketType::PacketType Type;
    offset += packet.stream.Read(Type, offset);
    offset += packet.stream.Read(answer, offset);
}

Packet QuizAnswerPacket::ToPacket() const {
    Packet packet;
    packet.stream.Insert(PacketType::QuizAnswerPacket);
    packet.stream.Insert(answer);
    return packet;
}



QuizResultPacket::QuizResultPacket(bool result) : result(result) {}

QuizResultPacket::QuizResultPacket(const Packet & packet) {
    size_t offset = 0;
    PacketType::PacketType Type;
    offset += packet.stream.Read(Type, offset);
    offset += packet.stream.Read(result, offset);
}

Packet QuizResultPacket::ToPacket() const {
    Packet packet;
    packet.stream.Insert(PacketType::QuizResultPacket);
    packet.stream.Insert(result);
    return packet;
}

QuizAbortionPacket::QuizAbortionPacket() {}

QuizAbortionPacket::QuizAbortionPacket(const Packet & packet) {
    size_t offset = 0;
    PacketType::PacketType Type;
    offset += packet.stream.Read(Type, offset);
}

Packet QuizAbortionPacket::ToPacket() const {
    Packet packet;
    packet.stream.Insert(PacketType::QuizAbortionPacket);
    return packet;
}
