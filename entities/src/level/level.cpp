#include "level.h"

Level::Level(std::string map) : mapGenerator(std::move(map)), grid(Grid(1000, 1000, "")) {}

void Level::initScene() {
}

void Level::initGrid() {
    grid.buildGrid();
}

void Level::startWave() {

}

void Level::spawnEnemies() {

}

