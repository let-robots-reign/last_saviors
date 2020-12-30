#include "BinaryStream/Packet.h"

template<>
void BinaryStream::Insert<Packet>(const Packet & packet) {
    const uint64_t packet_size = packet.data().size();
    Insert(packet_size);
    Push(packet.data());
}

template<>
size_t BinaryStream::Read<Packet>(Packet & packet, const size_t offset) const {
    uint64_t packet_size = 0;
    size_t read_offset = 0;
    read_offset += Read(packet_size, read_offset + offset);
    if (read_offset == 0) return 0;
    const std::vector<std::byte> packet_data = Get(packet_size, read_offset + offset);
    if (packet_data.size() == 0) return 0;
    packet = Packet(packet_data);
    return packet_size + packet_data.size();
}

template<>
size_t BinaryStream::Erase<Packet>(const size_t offset) {
    uint64_t packet_size = 0;
    size_t read_offset = 0;
    read_offset += Read(packet_size, read_offset + offset);
    const size_t erase_size = read_offset + packet_size;
    if (m_data.size() < offset + erase_size) return 0;
    Erase(erase_size, offset);
    return erase_size;
}



template<>
void BinaryStream::Insert<ClientQuiz>(const ClientQuiz & quiz) {
    const uint64_t quiz_size = quiz.question.size() + quiz.optionA.size() + quiz.optionB.size() + quiz.optionC.size() + quiz.optionD.size();
    Insert(quiz_size);
    Insert(quiz.question);
    Insert(quiz.optionA);
    Insert(quiz.optionB);
    Insert(quiz.optionC);
    Insert(quiz.optionD);
}

template<>
size_t BinaryStream::Read<ClientQuiz>(ClientQuiz & quiz, const size_t offset) const {
    uint64_t quiz_size = 0;
    size_t read_offset = 0;
    read_offset += Read(quiz_size, read_offset + offset);
    read_offset += Read(quiz.question, read_offset + offset);
    read_offset += Read(quiz.optionA, read_offset + offset);
    read_offset += Read(quiz.optionB, read_offset + offset);
    read_offset += Read(quiz.optionC, read_offset + offset);
    read_offset += Read(quiz.optionD, read_offset + offset);
    return quiz_size;
}

template<>
size_t BinaryStream::Erase<ClientQuiz>(const size_t offset) {
    uint64_t quiz_size = 0;
    uint64_t read_offset = 0;
    read_offset += Read(quiz_size, offset);
    Erase(quiz_size, offset);
    return quiz_size;
}
