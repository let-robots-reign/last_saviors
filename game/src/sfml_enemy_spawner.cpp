#include "sfml_enemy_spawner.h"

#include <utility>

EnemySpawner::EnemySpawner(Loader load) : sizeY(0), wave(0), step(0), loader(std::move(load)), spawnTimer(0),
                                          waveRunning(false), endOfMoving(true) {}

void EnemySpawner::setup() {
    int startX = loader.getStart();
    sizeY = readHeightFromConfig();
    startX *= sizeY;
    startX /= loader.getMapSize();
    startVect = sf::Vector2f(startX, 0);
}

void EnemySpawner::start() {
    waveRunning = true;
    endOfMoving = false;
}

void EnemySpawner::stop() {
    waveRunning = false;
}

void EnemySpawner::spawn(std::vector<SfmlEnemy> &enemies) {
    if (waveRunning) {
        if (spawnTimer % 15 == 0) {
            spawnTimer = 0;
            if ((*loader.getWaves())[wave].size() <= step) {
                waveRunning = false;
                step = 0;
                spawnTimer = 0;
                ++wave;
            } else {
                size_t enemyType = static_cast<size_t>((*loader.getWaves())[wave][step]);
                enemies.emplace_back(startVect, enemyType, sizeY / loader.getMapSize(), loader);
                ++step;
            }
        }
        ++spawnTimer;
    }
}

void EnemySpawner::move(std::vector<SfmlEnemy> &enemies, size_t &coins, size_t &lives) {
    auto it = enemies.begin();
    while (it != enemies.end()) {
        if (!it->go(*loader.getPath())) {
            if (it->isDead()) {
                coins += it->getCoinsForDeath();
                it = enemies.erase(it);
            } else {
                lives -= it->getDamage();
                it = enemies.erase(it);
                if (enemies.empty()) {
                    endOfMoving = true;
                }
            }
        } else {
            ++it;
        }
    }
}

int EnemySpawner::getMaxWaves() {
    return (*loader.getWaves()).size();
}

bool EnemySpawner::endOfWaves() {
    return wave == getMaxWaves() - 1;
}

size_t EnemySpawner::readHeightFromConfig() {
    std::ifstream sizes("assets/sizes.txt");
    size_t x = 0, y = 0;
    sizes >> x >> y;
    return y;
}
