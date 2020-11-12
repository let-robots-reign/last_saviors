#pragma once
#include <vector>

class Serializable {
public:
    virtual std::vector<std::byte> ToBinary() const = 0;
}
