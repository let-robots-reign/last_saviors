#ifndef LAST_SAVIORS_SFML_ENEMY_SPAWNER_H
#define LAST_SAVIORS_SFML_ENEMY_SPAWNER_H

#include "sfml_enemy.h"

class EnemySpawner {
public:
    EnemySpawner(Loader load);

    void setup();

    void start();

    void stop();

    void spawn(std::vector<SfmlEnemy> &enemies);

    void move(std::vector<SfmlEnemy> &enemies, size_t &coins, size_t &lives);

    int getMaxWaves();

    bool endOfWaves();

    inline bool isRunning() {
        return waveRunning;
    }

    inline bool movingFinished() {
        return endOfMoving;
    }

    inline int getWave() {
        return wave;
    }

private:
    size_t sizeY;
    size_t wave, step, spawnTimer;
    Loader loader;
    sf::Vector2f startVect;
    bool waveRunning, endOfMoving;

    size_t readHeightFromConfig();
};

#endif //LAST_SAVIORS_SFML_ENEMY_SPAWNER_H
