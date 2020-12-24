#ifndef TOWER_HPP
#define TOWER_HPP

#include "globals.hpp"
#include "enums.h"
#include "tile.h"
#include "particle.h"
#include "sfml_enemy.h"

#include <SFML/Graphics.hpp>

class SfmlTower {
public:
    SfmlTower() {}

    SfmlTower(Tile *field, TileType tileType);

    void shoot(std::vector<SfmlEnemy> &enemies, std::vector<Particle> &particles);

private:
    Tile *tile;
    TileType id;
    size_t step, shootDelay, strength;
    float range;
};

bool placeTower(size_t &coins, Tile *tile, std::vector<SfmlTower> &towers, TileType towerID);

#endif
