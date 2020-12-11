#pragma once
#include <vector>

struct Serializable {
public:
    virtual std::vector<std::byte> ToBinary() const = 0;
    virtual ~Serializable() = 0;
};

