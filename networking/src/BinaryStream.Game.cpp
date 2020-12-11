#include "BinaryStream.h"
#include "Serializable.h"

template<>
void BinaryStream::Write<Serializable>(const Serializable & serializable) {
    std::vector<std::byte> binary(serializable.ToBinary());
    Push(binary);
}
