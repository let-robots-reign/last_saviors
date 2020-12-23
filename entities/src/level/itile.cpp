#include "itile.h"

ITile::ITile(TileType type) : tileType(type) {}

void ITile::updateTile(TileType newType) {
    tileType = newType;
}

bool ITile::canPlaceTower() const {
    return tileType == BlockTile;
}

bool ITile::canPlaceShaft() const {
    return tileType == EmptyTile;
}
