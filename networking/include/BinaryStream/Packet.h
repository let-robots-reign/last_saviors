#pragma once
#include "BinaryStream.h"
//#include "PacketBase.h"
#include "Packets.h"


template<>
void BinaryStream::Insert<Packet>(const Packet & packet);

template<>
size_t BinaryStream::Read<Packet>(Packet & packet, const size_t offset) const;

template<>
size_t BinaryStream::Erase<Packet>(const size_t offset);



template<>
void BinaryStream::Insert<ClientQuiz>(const ClientQuiz & quiz);

template<>
size_t BinaryStream::Read<ClientQuiz>(ClientQuiz & quiz, const size_t offset) const;

template<>
size_t BinaryStream::Erase<ClientQuiz>(const size_t offset);
