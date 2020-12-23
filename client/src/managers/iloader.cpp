#include "iloader.h"

const char ILoader::ROAD_CHAR = '#';
const size_t ILoader::MOUSE_POINTER_ID = 0;
const size_t ILoader::MOUSE_ACTIVE_SELECT_ID = 1;
const size_t ILoader::MOUSE_INACTIVE_SELECT_ID = 2;
const size_t ILoader::BUTTON_START_ID = 0;
const size_t ILoader::BUTTON_PAUSE_ID = 1;

void ILoader::loadMaps() {
    std::ifstream mapFile("data/map.txt");
    std::string line;
    while (mapFile >> line) {
        if (!line.empty()) {
            CURRENT_MAP.push_back(line);
        }
    }
    mapSize = CURRENT_MAP.size();
}

void ILoader::loadWaves() {
    std::ifstream waveFile("data/waves.txt");
    std::string line;
    while (waveFile >> line) {
        waves.push_back(line);
    }
}
