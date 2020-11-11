#ifndef CLIENT_TILE_TYPE_H
#define CLIENT_TILE_TYPE_H

enum TileType {
    EmptyTile,
    RoadTile,
    BlockTile,
    PlacedTowerTile,
    CitadelTile
};

class Tile {
public:
    explicit Tile(TileType type);

    bool canPlaceTower();

    bool canPlaceShaft();
private:
    TileType tileType;
};

#endif //CLIENT_TILE_TYPE_H
