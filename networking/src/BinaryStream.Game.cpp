#include "BinaryStream.Game.h"
#include <algorithm>


template<>
void BinaryStream::Insert<std::string>(const std::string & string) {
    const uint16_t size = string.size();
    Insert(size);
    std::vector<std::byte> vec(size);
    std::transform(string.begin(), string.end(), vec.begin(), [] (char c) { return std::byte(c); });
    Push(vec);
}

template<>
void BinaryStream::Extract<std::string>(std::string & string, const size_t offset) {
    uint16_t size = 0;
    Extract(size, offset);
    string.resize(size);
    const std::vector<std::byte> vec = Get(offset, size);
    Erase(offset, size);
    std::transform(vec.begin(), vec.end(), string.begin(), [] (std::byte b) { return char(b); });
}
