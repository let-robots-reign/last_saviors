#include "level.h"

Level::Level(std::string map) : grid(Grid(1000, 1000, std::move(map))) {}

void Level::initScene() {
    initGrid();
    startWave();
    spawnEnemies();
}

void Level::initGrid() {
    grid.buildGrid();
}

void Level::startWave() {

}

void Level::spawnEnemies() {

}

