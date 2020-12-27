#include "sfml_tower.h"

SfmlTower::SfmlTower(Tile *field_, TileType tileType) : tile(field_), id(tileType), step(0) {
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

bool placeTower(size_t &coins, Tile *tile, std::vector<SfmlTower> &towers, const TileType towerID) {
    size_t towerPrices[4] = {0, 0, 60, 90};
    size_t price = towerPrices[static_cast<size_t>(towerID)];
    if (coins >= price && tile->getTileType() == EMPTY) {
        coins -= price;
        SfmlTower tower(tile, towerID);
        towers.push_back(tower);
        return true;
    }
    return false;
}
