#include "tile.h"

Tile::Tile(size_t size_, float posx, float posy) : sf::Sprite(), size(size_) {
    setPosition(posx, posy);
    setTileType(EMPTY);
}

void Tile::setTileType(TileType newType) {
    tileType = newType;
    setTexture(*loader.getFieldTexture(tileType));
}
