#ifndef FIELD_HPP
#define FIELD_HPP

#include "enums.h"
#include "globals.h"
#include <SFML/Graphics.hpp>

class Tile : public sf::Sprite {
public:
    Tile() {}

    Tile(size_t size_, float posx, float posy);

    size_t getTileType() const { return tileType; };

    void setTileType(TileType newType);

    size_t getSize() const { return size; }

private:
    size_t size;
    TileType tileType;
};

#endif
