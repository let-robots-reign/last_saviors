#ifndef CLIENT_GRID_H
#define CLIENT_GRID_H

#include <vector>
#include "tile.h"

class Grid {
public:
    Grid(size_t w, size_t h);

    const Tile &getTileAt(size_t x, size_t y) const;
private:
    size_t width;
    size_t height;
    std::vector<std::vector<Tile>> tiles;
};

#endif //CLIENT_GRID_H
