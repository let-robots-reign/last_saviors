#include "loader.h"

#include <sstream>

void Loader::loadTextures() {
    fieldTextures[0].loadFromFile("data/images/grass.jpg");
    fieldTextures[1].loadFromFile("data/images/path.jpg");
    fieldTextures[2].loadFromFile("data/images/tower0.gif");
    fieldTextures[3].loadFromFile("data/images/tower1.gif");
    fieldTextures[4].loadFromFile("data/images/tower2.gif");
    fieldTextures[5].loadFromFile("data/images/tower3.gif");

    enemyTextures[0].loadFromFile("data/images/enemy0.png");
    enemyTextures[1].loadFromFile("data/images/enemy1.png");

    particleTextures[0].loadFromFile("data/images/particle0.gif");
    particleTextures[1].loadFromFile("data/images/particle1.gif");

    buttonTextures[0].loadFromFile("data/images/buttonstart.gif");
    buttonTextures[1].loadFromFile("data/images/buttonpause.gif");
    buttonTextures[2].loadFromFile("data/images/upgrade.png");
    buttonTextures[3].loadFromFile("data/images/quiz.png");

    mouseTextures[0].loadFromFile("data/images/mouse0.gif");
    mouseTextures[1].loadFromFile("data/images/mouse1.gif");
    mouseTextures[2].loadFromFile("data/images/mouse2.gif");
}

void Loader::loadFont() {
    font.loadFromFile("data/Roboto-Regular.ttf");
}

int Loader::findStart() {
    for (size_t i = 0; i < mapSize; ++i) {
        if (CURRENT_MAP[i][0] == Loader::ROAD_CHAR) {
            return i;
        }
    }
    return -1;
}

void Loader::calculatePath() {
    path = {};
    std::vector<int> last = {-1, -1};
    start = findStart();
    int i = start, j = 0;

    path.push_back(RIGHT);
    while (i >= 0 && j >= 0 && i < mapSize && j < mapSize) {
        if (last[0] != i + 1 && i < mapSize - 1 && CURRENT_MAP[i + 1][j] == Loader::ROAD_CHAR) {
            path.push_back(DOWN);
            last = {i, j};
            i++;
        } else if (last[0] != i - 1 && i > 0 && CURRENT_MAP[i - 1][j] == Loader::ROAD_CHAR) {
            path.push_back(UP);
            last = {i, j};
            i--;
        } else if (last[1] != j + 1 && j < mapSize - 1 && CURRENT_MAP[i][j + 1] == Loader::ROAD_CHAR) {
            path.push_back(RIGHT);
            last = {i, j};
            j++;
        } else if (last[1] != j - 1 && j > 0 && CURRENT_MAP[i][j - 1] == Loader::ROAD_CHAR) {
            path.push_back(LEFT);
            last = {i, j};
            j--;
        } else { break; }
    }
}
