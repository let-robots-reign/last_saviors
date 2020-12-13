#include "BinaryStream.h"

void BinaryStream::Push(const std::vector<std::byte> & data) {
    m_data.insert(m_data.end(), data.begin(), data.end());
}

std::vector<std::byte> BinaryStream::Pop(const size_t amount) {
    std::vector<std::byte> popped = Get(0, amount);
    Erase(0, amount);
    return popped;
}

std::vector<std::byte> BinaryStream::Get(const size_t offset, const size_t amount) const {
    return std::vector<std::byte>(m_data.begin() + offset, m_data.begin() + offset + amount);
}

std::vector<std::byte> BinaryStream::Get(const size_t amount) const {
    return Get(0, amount);
}

void BinaryStream::Erase(const size_t offset, const size_t amount) {
    m_data.erase(m_data.begin() + offset, m_data.begin() + offset + amount);
}

void BinaryStream::Erase(const size_t amount) {
    Erase(0, amount);
}


const std::vector<std::byte> & BinaryStream::data() const {
    return m_data;
}
