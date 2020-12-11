#include "BinaryStream.h"

void BinaryStream::Push(const std::vector<std::byte> & data) {
    m_data.insert(m_data.end(), data.begin(), data.end());
}

std::vector<std::byte> BinaryStream::Pop(const size_t amount_bytes) {
    std::vector<std::byte> popped(m_data.begin(), m_data.begin() + amount_bytes);
    m_data.erase(m_data.begin(), m_data.begin() + amount_bytes);
    return popped;
}

const std::vector<std::byte> & BinaryStream::data() const {
    return m_data;
}
