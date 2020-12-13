#include "BinaryStream.h"

void BinaryStream::Push(const std::vector<std::byte> & data) {
    m_data.insert(m_data.end(), data.begin(), data.end());
}

std::vector<std::byte> BinaryStream::Pop(const size_t amount) {
    std::vector<std::byte> popped(m_data.begin(), m_data.begin() + amount);
    Erase(amount);
    return popped;
}

void BinaryStream::Erase(const size_t amount) {
    m_data.erase(m_data.begin(), m_data.begin() + amount);
}

const std::vector<std::byte> & BinaryStream::data() const {
    return m_data;
}
