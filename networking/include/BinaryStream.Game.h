#pragma once
#include "BinaryStream.h"
#include "Serializable.h"
#include <string>


template<>
void BinaryStream::Insert<std::string>(const std::string & string);

template<>
void BinaryStream::Extract<std::string>(std::string & string);
