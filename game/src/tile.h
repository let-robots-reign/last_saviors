#ifndef FIELD_HPP
#define FIELD_HPP

#include "enums.h"
#include "globals.hpp"
#include <SFML/Graphics.hpp>

class Tile : public sf::Sprite {
public:
    Tile() {}

    Tile(size_t size, float posx, float posy);

    void setTileType(TileType type);

    inline size_t getTileType() const {
        return tileType; 
    }

    inline size_t getSize() const {
        return size;
    }
    
private:
    size_t size;
    TileType tileType;
};

#endif
