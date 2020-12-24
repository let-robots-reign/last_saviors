#ifndef LAST_SAVIORS_TILE_H
#define LAST_SAVIORS_TILE_H

#include "enums.h"
#include "loader.h"
#include <SFML/Graphics.hpp>

class Tile : public sf::Sprite {
public:
    Tile(size_t size, float posx, float posy, Loader &loader);

    void setTileType(const TileType &type, Loader &loader);

    inline TileType getTileType() const {
        return tileType;
    }

    inline size_t getSize() const {
        return size;
    }

private:
    size_t size;
    TileType tileType;
};

#endif //LAST_SAVIORS_TILE_H