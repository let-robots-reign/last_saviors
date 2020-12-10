#ifndef CLIENT_TILE_TYPE_H
#define CLIENT_TILE_TYPE_H

#include <map>

enum TileType {
    EmptyTile,
    RoadTile,
    BlockTile,
    PlacedTowerTile,
    PlacedShaftTile,
    CitadelTile
};

class Tile {
public:
    explicit Tile(TileType type);

    void updateTile(TileType newType);

    bool canPlaceTower() const;

    bool canPlaceShaft() const;

private:
    TileType tileType;
};

#endif //CLIENT_TILE_TYPE_H
