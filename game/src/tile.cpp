#include "tile.h"

Tile::Tile(size_t size, float posx, float posy) : sf::Sprite(), size(size) {
    setPosition(posx, posy);
    setTileType(EMPTY);
}

void Tile::setTileType(TileType type) {
    tileType = type;
    setTexture(*loader.getFieldTexture(tileType));
}
