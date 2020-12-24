#include "game_map.h"

GameMap::GameMap(size_t windowHeight) : size(loader.getMapSize()), windowSize(windowHeight) {
    tileWidth = windowSize / size;
    for (size_t i = 0; i < size; ++i) {
        map.emplace_back();
        for (size_t j = 0; j < size; ++j) {
            map[i].push_back(Tile(tileWidth, i * tileWidth, j * tileWidth));
            if ((*loader.getCurrentMap())[i][j] == '#') {
                getTileAt(i, j)->setTileType(PATH);
            }
        }
    }
}

bool GameMap::isInMap(const sf::Vector2i &pos) const {
    bool xIsValid = pos.x > 0 && pos.x < windowSize;
    bool yIsValid = pos.y > 0 && pos.y < windowSize;
    return xIsValid && yIsValid;
}

size_t *GameMap::getTileCoords(const sf::Vector2i &pos) const {
    static size_t field[2];
    field[0] = pos.x / tileWidth;
    field[1] = pos.y / tileWidth;
    return field;
}
