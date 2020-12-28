#ifndef TOWER_HPP
#define TOWER_HPP

#include "vars.h"
#include "enums.h"
#include "tile.h"
#include "particle.h"
#include "point_damage_tower.h"
#include "sfml_enemy.h"

#include <SFML/Graphics.hpp>

class SfmlTower : public PointDamageTower {
public:
    SfmlTower(size_t x_pos, size_t y_pos, Tile *tile, TileType tileType);

    void shoot(std::vector<SfmlEnemy> &enemies, std::vector<Particle> &particles);

    inline size_t getX() const {
        return x;
    }

    inline size_t getY() const {
        return y;
    }

    static constexpr size_t UPGRADE_COST = 20;

private:
    size_t x, y;
    size_t step;
    Tile *tile;
    TileType id;
};

bool placeTower(size_t &coins, size_t x, size_t y, Tile *tile, std::vector<SfmlTower> &towers, TileType towerID);

bool upgradeTower(size_t &coins, size_t x, size_t y, Tile *tile, SfmlTower &tower);

#endif
