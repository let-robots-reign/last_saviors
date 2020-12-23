#ifndef GAMEMAP_HPP
#define GAMEMAP_HPP

#include "globals.hpp"
#include "enums.h"
#include "tile.h"
#include <SFML/Graphics.hpp>

class Game;

class GameMap {
public:
    GameMap() {}

    explicit GameMap(size_t windowHeight);

    bool isInField(const sf::Vector2i &pos) const;

    size_t *getTileCoords(const sf::Vector2i &pos) const;

    inline Tile *getTileAt(size_t i, size_t j) {
        return &field[i][j];
    }

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

#endif
