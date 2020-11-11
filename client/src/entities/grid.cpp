#include "grid.h"

Grid::Grid(size_t w, size_t h, std::string map) : width(w), height(h), mapGenerator(std::move(map)) {}

void Grid::buildGrid() {
    initialized = true;
    // logic...
}

bool Grid::isInitialized() {
    return false;
}

const Tile &Grid::getTileAt(size_t x, size_t y) const {
    return tiles[x][y];
}

void Grid::updateTileAt(size_t x, size_t y, TileType newType) const {

}
