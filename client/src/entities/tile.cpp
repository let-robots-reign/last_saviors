#include "tile.h"


Tile::Tile(TileType type) : tileType(type) {}

void Tile::updateTile(TileType newType) {

}

bool Tile::canPlaceTower() const {
    return false;
}

bool Tile::canPlaceShaft() const {
    return false;
}
