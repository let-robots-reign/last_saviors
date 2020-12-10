#pragma once
#include <vector>

struct BinaryStream {
public:
    BinaryStream() = default;
    ~BinaryStream() = default;

    void Push(const std::vector<std::byte> & data);
    std::vector<std::byte> Pop(const size_t amount_bytes);
    
    // for primitives, structs with no pointers, etc
    template <typename T>
    void Write(const T &data) {
        const size_t size = sizeof(T);
        std::vector<std::byte> binary(size);
        const std::byte *begin = reinterpret_cast<const std::byte *>(std::addressof(data));
        const std::byte *end = begin + size;
        std::copy(begin, end, binary.begin());
        Push(binary);
    }

    // for primitives, structs with no pointers, etc
    template <typename T>
    void Read(T &data) {
        const size_t size = sizeof(T);
        const std::vector<std::byte> binary = Pop(size);
        std::byte *begin = reinterpret_cast<std::byte *>(std::addressof(data));
        std::copy(binary.begin(), binary.end(), begin);
    }

    /*
        game-specific template specializations are in BinaryStream.Game.cpp
    */

    
    
    template <typename T>
    friend BinaryStream &operator<< (BinaryStream &buffer, const T &data) {
        buffer.Write(data);
        return buffer;
    }

    template <typename T>
    friend BinaryStream &operator>> (BinaryStream &buffer, const T &data) {
        buffer.Read(data);
        return buffer;
    }
    

    const std::vector<std::byte> & data() const;

private:
    std::vector<std::byte> m_data;

};
