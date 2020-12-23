#include "loader.h"

#include <sstream>

void Loader::loadTextures() {
    fieldTextures[0].loadFromFile("assets/images/grass.jpg");
    fieldTextures[1].loadFromFile("assets/images/path.jpg");
    fieldTextures[2].loadFromFile("assets/images/tower0.gif");
    fieldTextures[3].loadFromFile("assets/images/tower1.gif");

//    enemyTextures[0].loadFromFile("assets/images/enemy1.gif");
//    enemyTextures[1].loadFromFile("assets/images/enemy2.gif");

    buttonTextures[0].loadFromFile("assets/images/buttonstart");
    buttonTextures[1].loadFromFile("assets/images/buttonpause");

    mouseTextures[0].loadFromFile("assets/images/mouse0");
    mouseTextures[1].loadFromFile("assets/images/mouse1");
    mouseTextures[2].loadFromFile("assets/images/mouse2");
}

void Loader::loadFont() {
    font.loadFromFile("assets/Roboto.ttf");
}

std::string Loader::loadTowerDescription() const {
    std::ifstream towersData("towers.txt");
    std::stringstream description;
    std::string line;
    while (!towersData.eof()) {
        std::getline(towersData, line);
        description << line << '\n';
    }
    return description.str();
}

int Loader::findStart() {
    int start_index = -1;
    size_t i = 0;
    while (start_index == -1 && i < CURRENT_MAP.size()) {
        if (CURRENT_MAP[i][0] == Loader::ROAD_CHAR) {
            start_index = i;
        }
        ++i;
    }
    return start_index;
}

void Loader::calculatePath() {
    path = {};
    std::vector<int> last = {-1, -1};
    start = findStart();
    int i = start;
    int j = 0;

    path.push_back(RIGHT);
    while (i >= 0 && j >= 0 && i < mapSize && j < mapSize) {
        if (last[0] != i + 1 && i < mapSize - 1 && CURRENT_MAP[i + 1][j] == Loader::ROAD_CHAR) {
            path.push_back(DOWN);
            ++i;
        } else if (last[0] != i - 1 && i > 0 && CURRENT_MAP[i - 1][j] == Loader::ROAD_CHAR) {
            path.push_back(UP);
            --i;
        } else if (last[1] != j + 1 && j < mapSize - 1 && CURRENT_MAP[i][j + 1] == Loader::ROAD_CHAR) {
            path.push_back(RIGHT);
            ++j;
        } else if (last[1] != j - 1 && j > 0 && CURRENT_MAP[i][j - 1] == Loader::ROAD_CHAR) {
            path.push_back(LEFT);
            --j;
        } else {
            break;
        }
        last = {i, j};
    }
}

