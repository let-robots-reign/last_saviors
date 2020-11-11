#include "../BinaryStream.h"


BinaryStream::BinaryStream() {

}
BinaryStream::~BinaryStream() {

}

void BinaryStream::Push(const std::vector<std::byte> data) {

}

std::vector<std::byte> BinaryStream::Pop(const size_t amount_bytes) {

}

template <typename T>
void BinaryStream::Write(const T &data) {

}

template <typename T>
void BinaryStream::Read(T &data) {

}

/*
    overload some methods for game objects, etc
    mb inherit a class and overload methods there
*/

template <typename T>
BinaryStream &operator<< (T &data, BinaryStream &buffer) {

}

template <typename T>
BinaryStream &operator>> (const T &data, BinaryStream &buffer) {

}


