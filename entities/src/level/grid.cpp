#include "grid.h"

#include <sstream>
#include <fstream>
#include <algorithm>

Grid::Grid(size_t w, size_t h, std::string map) : width(w), height(h), initialized(false),
                                                  mapGenerator(std::move(map)) {}

/*
 * Пояснения к тому, как строится поле:
 * 1. Поле задается строкой из символов, каждый символ обозначает тип клетки
 * 2. Соответствие между символом и типом клетки задается в grid_config
 * 3. По grid_config строится charsToType
 * 4. По строке mapGenerator строится поле, т. е. матрица клеток
*/

void Grid::buildGrid() {
    readConfigMapFromFile();

    std::istringstream iss(mapGenerator);
    tilesContainer container;
    std::string line;
    while (getline(iss, line, '\n')) {
        std::vector<ITile> tilesRow;
        std::transform(line.begin(), line.end(), std::back_inserter(tilesRow),
                       [this](char c) -> ITile { return ITile(getTypeFromMap(c)); });
        container.push_back(tilesRow);
    }
    tiles = container;
    initialized = true;
}

void Grid::readConfigMapFromFile() {
    std::ifstream gridConfig("grid_config");
    if (gridConfig.is_open()) {
        std::string line;
        while (getline(gridConfig, line)) {
            line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
            if (line[0] == '#' || line.empty()) {
                continue;
            }
            auto delimiterPosition = line.find(':');
            std::string tileTypeStr = line.substr(0, delimiterPosition);
            char tileTypeChar = line.substr(delimiterPosition + 1)[0];
            charsToType[tileTypeChar] = stringsToTileTypes.at(tileTypeStr);
        }
    }
}

TileType Grid::getTypeFromMap(char c) {
    return charsToType.count(c) ? charsToType.at(c) : EmptyTile;
}

bool Grid::isInitialized() const {
    return initialized;
}

const ITile &Grid::getTileAt(size_t x, size_t y) const {
    return tiles[x][y];
}

void Grid::updateTileAt(size_t x, size_t y, TileType newType) {
    tiles[x][y].updateTile(newType);
}

void Grid::setTiles(const tilesContainer &ptiles) {
    tiles = ptiles;
}
