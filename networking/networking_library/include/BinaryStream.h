#pragma once
#include <vector>
#include <array>

struct BinaryStream {
public:

    void Push(const std::vector<std::byte> & data);
    std::vector<std::byte> Pop(const size_t amount);
    std::vector<std::byte> Get(const size_t amount, const size_t offset = 0) const;
    void Erase(const size_t amount, const size_t offset = 0);

    
    
    ///TODO: rewrite using std::span (C++20) if possible

    template <typename T>
    void Insert(const T & data) {
        const size_t size = sizeof(T);
        std::array<std::byte, size> binary;
        const std::byte *begin = reinterpret_cast<const std::byte *>(std::addressof(data));
        const std::byte *end = begin + size;
        std::copy(begin, end, binary.begin());
        Push(std::vector<std::byte>(binary.begin(), binary.end()));   //xd
    }

    template <typename T>
    void Extract(T & data, const size_t offset = 0) {
        Read(data, offset);
        Remove<T>(offset);
    }

    template <typename T>
    size_t Read(T & data, const size_t offset = 0) const {
        const size_t size = sizeof(T);
        const std::vector<std::byte> binary = Get(size, offset);
        std::byte *begin = reinterpret_cast<std::byte *>(std::addressof(data));
        std::copy(binary.begin(), binary.end(), begin);
        return sizeof(T);
    }

    template <typename T>
    size_t Remove(const size_t offset = 0) {
        Erase(sizeof(T), offset);
        return sizeof(T);
    }
    
    
    // same as Insert
    template <typename T>
    friend BinaryStream & operator<< (BinaryStream & buffer, const T & data) {
        buffer.Insert(data);
        return buffer;
    }

    // same as Extract
    template <typename T>
    friend BinaryStream & operator>> (BinaryStream & buffer, T & data) {
        buffer.Extract(data);
        return buffer;
    }
    

    const std::vector<std::byte> & data() const;

private:
    std::vector<std::byte> m_data;

};

// to use with game-specific types just make three specializations: Insert, Read, Remove
// remember to include file with those specializations, not only BinaryStream.h
