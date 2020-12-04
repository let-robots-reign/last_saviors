#pragma once
#include <vector>

struct BinaryStream {
public:
    BinaryStream();
    ~BinaryStream();

    void Push(const std::vector<std::byte> data);
    std::vector<std::byte> Pop(const size_t amount_bytes);
    
    template <typename T>
    void Write(const T &data) {

    }

    template <typename T>
    void Read(T &data) {

    }

    /*
        overload some methods for game objects, etc
        mb inherit a class and override methods in it
    */

    
    
    template <typename T>
    friend BinaryStream &operator<< (BinaryStream &buffer, const T &data) {

    }

    template <typename T>
    friend BinaryStream &operator>> (BinaryStream &buffer, const T &data) {

    }
    

    const std::vector<std::byte> & data() const;

private:
    std::vector<std::byte> m_data;

};
