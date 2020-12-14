#pragma once
#include "BinaryStream.h"
#include "PacketBase.h"


template<>
void BinaryStream::Insert<Packet>(const Packet & packet);

template<>
size_t BinaryStream::Read<Packet>(Packet & packet, const size_t offset) const;

template<>
size_t BinaryStream::Remove<Packet>(const size_t offset);
