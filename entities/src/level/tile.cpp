#include "tile.h"

Tile::Tile(TileType type) : tileType(type) {}

void Tile::updateTile(TileType newType) {
    tileType = newType;
}

bool Tile::canPlaceTower() const {
    return tileType == BlockTile;
}

bool Tile::canPlaceShaft() const {
    return tileType == EmptyTile;
}
