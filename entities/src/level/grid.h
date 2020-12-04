#ifndef CLIENT_GRID_H
#define CLIENT_GRID_H

#include <string>
#include <vector>
#include "tile.h"

using tilesContainer = std::vector<std::vector<Tile>>;

class Grid {
public:
    Grid(size_t w, size_t h, std::string map);

    void buildGrid();

    bool isInitialized() const;

    const Tile &getTileAt(size_t x, size_t y) const;

    void updateTileAt(size_t x, size_t y, TileType newType);

    void setTiles(const tilesContainer &tiles);

private:
    size_t width;
    size_t height;
    std::string mapGenerator;
    bool initialized;
    std::vector<std::vector<Tile>> tiles;
};

#endif //CLIENT_GRID_H
