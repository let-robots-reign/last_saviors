#include "sfml_tower.h"

SfmlTower::SfmlTower(size_t x_pos, size_t y_pos, Tile *tile, TileType tileType) : x(x_pos), y(y_pos), tile(tile), id(tileType), step(0) {
    tile->setTileType(tileType);
    switch (tileType) {
        case BASIC_TOWER:
            strength = 1;
            range = 65 * 65;
            shootDelay = 45;
            break;
        case CIRCLE_TOWER:
            strength = 1;
            range = 55 * 55;
            shootDelay = 85;
            break;
    }
}

void SfmlTower::shoot(std::vector<SfmlEnemy> &enemies, std::vector<Particle> &particles) {
    if (step % shootDelay == 0) {
        sf::Vector2f pos = tile->getPosition();
        for (SfmlEnemy &enemy : enemies) {
            sf::Vector2f enemyPos = enemy.getPosition();
            float dis = std::pow(pos.x - enemyPos.x + tile->getSize() / 2, 2) +
                        std::pow(pos.y - enemyPos.y + tile->getSize() / 2, 2);
            if (dis < range) {
                step = 1;
                particles.emplace_back(pos.x + tile->getSize() / 2, pos.y + tile->getSize() / 2,
                                             &enemy, strength, tile->getSize(), id - 2);
                if (id != CIRCLE_TOWER) { break; }
            }
        }
    } else {
        step++;
    }
}

bool placeTower(size_t &coins, size_t x, size_t y, Tile *tile, std::vector<SfmlTower> &towers, const TileType towerID) {
    size_t towerPrices[4] = {0, 0, 60, 90};
    size_t price = towerPrices[static_cast<size_t>(towerID)];
    if (coins >= price && tile->getTileType() == EMPTY) {
        coins -= price;
        SfmlTower tower(x, y, tile, towerID);
        towers.push_back(tower);
        return true;
    }
    return false;
}

bool upgradeTower(size_t &coins, size_t x, size_t y, Tile *tile, SfmlTower &tower) {
    tower.setShootDelay(std::max<size_t>(tower.getShootDelay() - 10, 10));
    tower.setRange(tower.getRange() * 1.25f);
    if (coins > SfmlTower::UPGRADE_COST) {
        coins -= SfmlTower::UPGRADE_COST;
        return true;
    }
    return false;
}
