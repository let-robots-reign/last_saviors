#include "BinaryStream.h"

BinaryStream::BinaryStream(const std::vector<std::byte> & data) : m_data(data) {}

void BinaryStream::Push(const std::vector<std::byte> & data) {
    m_data.insert(m_data.end(), data.begin(), data.end());
}

std::vector<std::byte> BinaryStream::Pop(const size_t amount) {
    std::vector<std::byte> popped = Get(amount);
    Erase(amount);
    return popped;
}

std::vector<std::byte> BinaryStream::Get(const size_t amount, const size_t offset) const {
    if (m_data.size() < offset + amount)
        return {};
    return std::vector<std::byte>(m_data.begin() + offset, m_data.begin() + offset + amount);
}

void BinaryStream::Erase(const size_t amount, const size_t offset) {
    if (m_data.size() < offset + amount)
        return;
    m_data.erase(m_data.begin() + offset, m_data.begin() + offset + amount);
}


const std::vector<std::byte> & BinaryStream::data() const {
    return m_data;
}
