#ifndef CLIENT_GRID_H
#define CLIENT_GRID_H

#include <string>
#include <vector>
#include "itile.h"

using tilesContainer = std::vector<std::vector<ITile>>;

class Grid {
public:
    Grid(size_t w, size_t h, std::string map);

    void buildGrid();

    bool isInitialized() const;

    const ITile &getTileAt(size_t x, size_t y) const;

    void updateTileAt(size_t x, size_t y, TileType newType);

    void setTiles(const tilesContainer &tiles);

private:
    size_t width;
    size_t height;
    std::map<char, TileType> charsToType;
    std::string mapGenerator;
    bool initialized;
    tilesContainer tiles;

    void readConfigMapFromFile();

    static const std::map<std::string, TileType> stringsToTileTypes;

    TileType getTypeFromMap(char c);

};

const std::map<std::string, TileType> Grid::stringsToTileTypes = {
        {"Empty", EmptyTile},
        {"Road", RoadTile},
        {"Block", BlockTile},
        {"PlacedTower", PlacedTowerTile},
        {"PlacedShaft", PlacedShaftTile},
        {"Citadel", CitadelTile}
};

#endif //CLIENT_GRID_H
