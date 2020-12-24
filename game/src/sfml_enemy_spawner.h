#ifndef ENEMYSPAWNER_HPP
#define ENEMYSPAWNER_HPP

#include "globals.hpp"
#include "sfml_enemy.h"

#include <SFML/Graphics.hpp>

class EnemySpawner {
public:
    EnemySpawner();

    void setup();

    void start();

    void stop();

    void spawn(std::vector<SfmlEnemy> &enemies);

    void move(std::vector<SfmlEnemy> &enemies, size_t &coins, size_t &lives);

    size_t getMaxWaves();

    bool endOfWaves();

    bool isRunning() { return waveRunning; }

    bool movingFinished() { return endOfMoving; }

    size_t getWave() { return wave; }

private:
    size_t wave, step, spawnTimer;
    sf::Vector2f startVect;
    bool waveRunning, endOfMoving;
};

#endif
