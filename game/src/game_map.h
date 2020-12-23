#ifndef LAST_SAVIORS_GAME_MAP_H
#define LAST_SAVIORS_GAME_MAP_H

#include "enums.h"
#include "tile.h"
#include <SFML/Graphics.hpp>

class GameMap {
public:
    GameMap() = default;

    GameMap(size_t windowHeight, const Loader &loader);

    Tile getTileAt(size_t i, size_t j) {
        return field[i][j];
    }

    bool isInField(const sf::Vector2i &pos) const;

    size_t *getTileCoords(const sf::Vector2i &pos) const;

    inline size_t getSize() const {
        return size;
    }

    inline size_t getTileWidth() const {
        return tileWidth;
    }

private:
    size_t size, windowSize, tileWidth;
    std::vector<std::vector<Tile>> field;
};

#endif //LAST_SAVIORS_GAME_MAP_H
