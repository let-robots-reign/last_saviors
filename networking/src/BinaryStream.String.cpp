#include "BinaryStream/String.h"
#include <algorithm>

template<>
void BinaryStream::Insert<std::string>(const std::string & string) {
    const uint16_t string_size = string.size();
    Insert(string_size);
    std::vector<std::byte> vec(string_size);
    std::transform(string.begin(), string.end(), vec.begin(), [] (char c) { return std::byte(c); });
    Push(vec);
}

template<>
size_t BinaryStream::Read<std::string>(std::string & string, const size_t offset) const {
    uint16_t string_size = 0;
    Read(string_size, offset);
    const size_t read_size = sizeof(string_size) + string_size;
    string.resize(string_size);
    const std::vector<std::byte> vec = Get(string_size, offset + sizeof(string_size));
    std::transform(vec.begin(), vec.end(), string.begin(), [] (std::byte b) { return char(b); });
    return read_size;
}

template<>
size_t BinaryStream::Erase<std::string>(const size_t offset) {
    uint16_t string_size = 0;
    Read(string_size, offset);
    const size_t erase_size = sizeof(string_size) + string_size;
    if (m_data.size() < offset + erase_size) return 0;
    Erase(erase_size, offset);
    return erase_size;
}
