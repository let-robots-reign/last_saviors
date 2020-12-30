#include "iloader.h"

#include <sstream>
#include <iostream>

const char ILoader::ROAD_CHAR = '#';
const size_t ILoader::MOUSE_POINTER_ID = 0;
const size_t ILoader::MOUSE_ACTIVE_SELECT_ID = 1;
const size_t ILoader::MOUSE_INACTIVE_SELECT_ID = 2;
const size_t ILoader::MOUSE_UPGRADE_ID = 3;
const size_t ILoader::BUTTON_START_ID = 0;
const size_t ILoader::BUTTON_PAUSE_ID = 1;
const size_t ILoader::BUTTON_UPGRADE_ID = 2;
const size_t ILoader::BUTTON_QUIZ_ID = 3;

void ILoader::loadMaps() {
    std::ifstream mapFile("data/map.txt");
    while (!mapFile.eof()) {
        std::string line;
        mapFile >> line;
        if (!line.empty()) {
            CURRENT_MAP.push_back(line);
        }
    }
    mapSize = CURRENT_MAP.size();
}

void ILoader::loadWaves() {
    std::ifstream waveFile("data/waves.txt");
    std::string line;
    while (!waveFile.eof()) {
        waveFile >> line;
        waves.push_back(line);
    }
}

std::string ILoader::loadTowerDescription() {
    std::ifstream data("data/towers.txt");
    std::stringstream description;
    while (!data.eof()) {
        std::string line;
        std::getline(data, line);
        description << line << "\n";
    }
    return description.str();
}
