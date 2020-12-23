#include "loader.h"

#include <sstream>

void Loader::loadTextures() {
    fieldTextures[0].loadFromFile("assets/images/grass.jpg");
    fieldTextures[1].loadFromFile("assets/images/path.jpg");
    fieldTextures[2].loadFromFile("assets/images/tower0.gif");
    fieldTextures[3].loadFromFile("assets/images/tower1.gif");

//    for(size_t i = 0; i<size_t(sizeof(enemyTextures)/sizeof(sf::Texture)); ++i){
//        enemyTextures[i].loadFromFile("assets/images/enemy"+std::to_string(i)+".gif");
//    }
//    for(size_t i = 0; i<size_t(sizeof(particleTextures)/sizeof(sf::Texture)); ++i){
//        particleTextures[i].loadFromFile("assets/images/particle"+std::to_string(i)+".gif");
//    }
    buttonTextures[0].loadFromFile("assets/images/buttonstart.gif");
    buttonTextures[1].loadFromFile("assets/images/buttonpause.gif");
    mouseTextures[0].loadFromFile("assets/images/mouse0.gif");
    mouseTextures[1].loadFromFile("assets/images/mouse1.gif");
    mouseTextures[2].loadFromFile("assets/images/mouse2.gif");
}

void Loader::loadFont() {
    font.loadFromFile("assets/Roboto.ttf");
}

int Loader::findStart() {
    for (size_t i = 0; i < mapSize; ++i) {
        if (CURRENT_MAP[i][0] == '#') {
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
        if (last[0] != i + 1 && i < mapSize - 1 && CURRENT_MAP[i + 1][j] == '#') {
            path.push_back(DOWN);
            last = {i, j};
            ++i;
        } else if (last[0] != i - 1 && i > 0 && CURRENT_MAP[i - 1][j] == '#') {
            path.push_back(UP);
            last = {i, j};
            --i;
        } else if (last[1] != j + 1 && j < mapSize - 1 && CURRENT_MAP[i][j + 1] == '#') {
            path.push_back(RIGHT);
            last = {i, j};
            ++j;
        } else if (last[1] != j - 1 && j > 0 && CURRENT_MAP[i][j - 1] == '#') {
            path.push_back(LEFT);
            last = {i, j};
            --j;
        } else {
            break;
        }
    }
}

std::string Loader::loadTowerDescription() const {
    std::ifstream towersData("assets/towers.txt");
    std::stringstream description;
    std::string line;
    while (!towersData.eof()) {
        std::getline(towersData, line);
        description << line << '\n';
    }
    return description.str();
}
