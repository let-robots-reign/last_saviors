#include "iloader.h"

const char ILoader::ROAD_CHAR = '#';
const char ILoader::EMPTY_TILE_CHAR = '.';

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
