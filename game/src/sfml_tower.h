#ifndef TOWER_HPP
#define TOWER_HPP

#include "globals.h"
#include "enums.h"
#include "tile.h"
#include "particle.h"
#include "point_damage_tower.h"
#include "sfml_enemy.h"

#include <SFML/Graphics.hpp>

class SfmlTower : public PointDamageTower {
public:
    SfmlTower(Tile *field, TileType tileType);

    void shoot(std::vector<SfmlEnemy> &enemies, std::vector<Particle> &particles);

private:
    size_t step;
    Tile *tile;
    TileType id;
};

bool placeTower(size_t &coins, Tile *tile, std::vector<SfmlTower> &towers, TileType towerID);

#endif
