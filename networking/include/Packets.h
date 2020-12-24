#pragma once
#include "PacketBase.h"
#include "ClientQuiz.h"
#include "BinaryStream.Game.h"
#include <string>


namespace PacketType {
    const PacketType ChatMessage = 1;  // unique
}

struct ChatMessagePacket {
    std::string name;
    std::string message;

    ChatMessagePacket(const std::string name, const std::string message);
    ChatMessagePacket(const Packet & packet);
    Packet ToPacket() const;
};



namespace PacketType {
    const PacketType QuizRequestPacket = 2;  // unique
}

struct QuizRequestPacket {
    QuizRequestPacket();
    QuizRequestPacket(const Packet & packet);
    Packet ToPacket() const;
};



namespace PacketType {
    const PacketType QuizResponsePacket = 3;  // unique
}

struct QuizResponsePacket {    
    ClientQuiz quiz;
    
    QuizResponsePacket(const ClientQuiz & quiz);
    QuizResponsePacket(const Packet & packet);
    Packet ToPacket() const;
};



namespace PacketType {
    const PacketType QuizAnswerPacket = 4;  // unique
}

struct QuizAnswerPacket {
    ///TODO: index? depends on Quiz struct
    uint8_t answer;
    
    QuizAnswerPacket(const uint8_t & answer);
    QuizAnswerPacket(const Packet & packet);
    Packet ToPacket() const;
};



namespace PacketType {
    const PacketType QuizResultPacket = 5;  // unique
}

struct QuizResultPacket {
    bool result;
    
    QuizResultPacket(bool result);
    QuizResultPacket(const Packet & packet);
    Packet ToPacket() const;
};
