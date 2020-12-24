#ifndef GAMEMAP_HPP
#define GAMEMAP_HPP

#include "vars.h"
#include "enums.h"
#include "tile.h"
#include <SFML/Graphics.hpp>

class GameMap {
public:
    GameMap() {}

    GameMap(size_t windowHeight);

    Tile *getTileAt(size_t i, size_t j) { return &map[i][j]; }

    size_t getSize() const { return size; }

    size_t getTileWidth() const { return tileWidth; }

    bool isInMap(const sf::Vector2i &pos) const;

    size_t *getTileCoords(const sf::Vector2i &pos) const;

private:
    size_t size, windowSize, tileWidth;
    std::vector<std::vector<Tile>> map;
};

#endif
