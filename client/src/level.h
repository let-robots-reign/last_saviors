#ifndef CLIENT_LEVEL_H
#define CLIENT_LEVEL_H

#include <string>
#include <utility>
#include "grid.h"

class Level {
public:
    Level(std::string map, Grid g) : mapGenerator(std::move(map)), grid(std::move(g)) {}

    void initLevel();

    Grid getGrid();
private:
    std::string mapGenerator;
    Grid grid;
};

#endif //CLIENT_LEVEL_H
