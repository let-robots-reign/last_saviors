#pragma once
#include "BinaryStream.h"
#include "Serializable.h"
#include <string>


template<>
void BinaryStream::Insert<std::string>(const std::string & string);

template<>
size_t BinaryStream::Read<std::string>(std::string & string, const size_t offset) const;

template<>
size_t BinaryStream::Remove<std::string>(const size_t offset);
