#include "tile.h"


Tile::Tile(TileType type) : tileType(type) {}

bool Tile::canPlaceTower() {
    return false;
}

bool Tile::canPlaceShaft() {
    return false;
}
