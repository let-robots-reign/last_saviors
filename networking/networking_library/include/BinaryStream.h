#pragma once
#include <vector>
#include <array>

struct BinaryStream {
public:

    void Push(const std::vector<std::byte> & data);
    std::vector<std::byte> Pop(const size_t amount);

    std::vector<std::byte> Get(const size_t offset, const size_t amount) const;
    std::vector<std::byte> Get(const size_t amount) const;

    void Erase(const size_t offset, const size_t amount);
    void Erase(const size_t amount);
    
    ///TODO: rewrite using std::span (C++20) if possible

    // inserts a primitive/struct
    template <typename T>
    void Insert(const T & data) {
        const size_t size = sizeof(T);
        std::array<std::byte, size> binary;
        const std::byte *begin = reinterpret_cast<const std::byte *>(std::addressof(data));
        const std::byte *end = begin + size;
        std::copy(begin, end, binary.begin());
        Push(std::vector<std::byte>(binary.begin(), binary.end()));   //xd
    }

    // extracts a primitive/struct
    template <typename T>
    void Extract(T & data, const size_t offset = 0) {
        Read(data, offset);
        Erase(offset, sizeof(T));
    }

    // reads a primitive/struct (same as Extract but it copies instead of cutting)
    template <typename T>
    void Read(T & data, const size_t offset = 0) const {
        const size_t size = sizeof(T);
        const std::vector<std::byte> binary = Get(offset, size);
        std::byte *begin = reinterpret_cast<std::byte *>(std::addressof(data));
        std::copy(binary.begin(), binary.end(), begin);
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
