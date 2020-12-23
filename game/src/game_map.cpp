#include "game_map.h"

GameMap::GameMap(size_t windowHeight, const Loader &loader) : size(loader.getMapSize()), windowSize(windowHeight) {
    tileWidth = windowHeight / size;
    for (size_t i = 0; i < size; ++i) {
        std::vector<Tile> tilesRow;
        for (size_t j = 0; j < size; ++j) {
            tilesRow.emplace_back(tileWidth, i * tileWidth, j * tileWidth, loader);
            if (loader.getCurrentMap()[i][j] == Loader::ROAD_CHAR) {
                getTileAt(i, j).setTileType(ROAD, loader);
            }
        }
    }
}

bool GameMap::isInField(const sf::Vector2i &pos) const {
    bool xIsValid = pos.x > 0 && pos.x < windowSize;
    bool yIsValid = pos.y > 0 && pos.y < windowSize;
    return xIsValid && yIsValid;
}

size_t *GameMap::getTileCoords(const sf::Vector2i &pos) const {
    // TODO: return Coordinate class
    static size_t tileCoords[2];
    tileCoords[0] = pos.x / tileWidth;
    tileCoords[1] = pos.y / tileWidth;
    return tileCoords;
}
