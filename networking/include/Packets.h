#pragma once
#include "PacketBase.h"
#include "BinaryStream.Game.h"
#include <string>
///TODO: #include Ilya's Quiz struct

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

///TODO: Ilya's Quiz
//struct Quiz {}; //(probable same as ClientQuiz but with "uint8_t correct" field)
struct ClientQuiz {
    ClientQuiz() = default;
    ClientQuiz(const Quiz & quiz) :
            question(quiz.quesion),
            optionA(quiz.optionA),
            optionB(quiz.optionB),
            optionC(quiz.optionC),
            optionD(quiz.optionD)
        {}
    std::string question;
    std::string optionA;
    std::string optionB;
    std::string optionC;
    std::string optionD;
};
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
