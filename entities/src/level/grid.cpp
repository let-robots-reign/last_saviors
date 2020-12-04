#include "grid.h"

#include <sstream>

Grid::Grid(size_t w, size_t h, std::string map) : width(w), height(h), initialized(false), mapGenerator(std::move(map)) {}

void Grid::buildGrid() {
    initialized = true;
    std::istringstream iss(mapGenerator);
    std::string line;
    size_t line_index = 0;
    while (getline(iss, line, '\n')) {
        for (size_t char_index = 0; char_index < line.size(); ++char_index) {
            tiles[line_index][char_index].updateTile(symbolsToTileTypes[line[char_index]]);
        }
    }
}

bool Grid::isInitialized() const {
    return initialized;
}

const Tile &Grid::getTileAt(size_t x, size_t y) const {
    return tiles[x][y];
}

void Grid::updateTileAt(size_t x, size_t y, TileType newType) {
    tiles[x][y].updateTile(newType);
}

void Grid::setTiles(const tilesContainer &ptiles) {
    tiles = ptiles;
}
