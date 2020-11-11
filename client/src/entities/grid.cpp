#include "grid.h"

Grid::Grid(size_t w, size_t h) : width(w), height(h) {}

const Tile &Grid::getTileAt(size_t x, size_t y) const {
    return tiles[x][y];
}
