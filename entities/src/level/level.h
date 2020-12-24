#ifndef CLIENT_LEVEL_H
#define CLIENT_LEVEL_H

#include <string>
#include <utility>
#include "grid.h"

class Level {
public:
    explicit Level(std::string map);

    void initScene();

    inline Grid getGrid() const {
        return grid;
    }

private:
    Grid grid;

    void initGrid();

    void startWave();

    void spawnEnemies();
};

#endif //CLIENT_LEVEL_H
