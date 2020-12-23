#include "tile.h"

Tile::Tile(size_t size, float posx, float posy, const Loader &loader) : sf::Sprite(), size(size) {
    setPosition(posx, posy);
    setTileType(EMPTY, loader);
}

void Tile::setTileType(const TileType &type, const Loader &loader) {
    tileType = type;
    setTexture(loader.getFieldTexture(tileType));
}
