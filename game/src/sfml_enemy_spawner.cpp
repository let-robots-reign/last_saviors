#include "sfml_enemy_spawner.h"

EnemySpawner::EnemySpawner() : wave(0), step(0), spawnTimer(0), sizeY(600) {}

void EnemySpawner::setup() {
    size_t startX = loader.getStart();
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
    if (!waveRunning) return;
    if (spawnTimer % 15 == 0) {
        spawnTimer = 0;
        if (int((*loader.getWaves())[wave].length()) <= step) {
            waveRunning = false;
            step = 0;
            spawnTimer = 0;
            ++wave;
        } else {
            size_t enemyClass = static_cast<size_t>((*loader.getWaves())[wave][step]) - static_cast<size_t>('0');
            enemies.emplace_back(startVect, enemyClass, sizeY / loader.getMapSize());
            ++step;
        }
    }
    ++spawnTimer;
}

void EnemySpawner::move(std::vector<SfmlEnemy> &enemies, size_t &coins, int &lives) {
    auto i = enemies.begin();
    while (i != enemies.end()) {
        if (!i->go(*loader.getPath())) {
            if (i->isDead()) {
                coins += i->getValue();
                i = enemies.erase(i);
            } else {
                lives -= i->getValue();
                i = enemies.erase(i);
                if (enemies.empty()) {
                    endOfMoving = true;
                }
            }
        } else {
            ++i;
        }
    }
}

size_t EnemySpawner::getMaxWaves() {
    return (*loader.getWaves()).size();
}

bool EnemySpawner::endOfWaves() {
    return wave == (size_t) getMaxWaves();
}
