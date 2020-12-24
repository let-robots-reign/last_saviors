#ifndef LOADER_HPP
#define LOADER_HPP

#include "enums.h"
#include <SFML/Graphics.hpp>
#include <fstream>

class Loader {
public:
    Loader() {}

    void loadTextures();

    void loadMaps();

    void loadFont();

    void loadWaves();

    void calculatePath();

    std::string loadTowerDescription();

    std::vector<std::string> *getCurrentMap() {
        return &CURRENT_MAP;
    }

    std::vector<std::string> *getWaves() {
        return &waves;
    }

    std::vector<Directions> *getPath() {
        return &path;
    }

    sf::Font *getFont() {
        return &font;
    }

    size_t getMapSize() {
        return mapSize;
    }

    size_t getStart() {
        return start;
    }

    sf::Texture *getFieldTexture(TileType field) {
        return &(fieldTextures[static_cast<size_t>(field)]);
    }

    sf::Texture *getEnemyTexture(size_t enemyID) {
        return &(enemyTextures[enemyID]);
    }

    sf::Texture *getButtonTexture(size_t buttonID) {
        return &(buttonTextures[buttonID]);
    }

    sf::Texture *getParticleTextures(size_t particleID) {
        return &(particleTextures[particleID]);
    }

    sf::Texture *getMouseTextures(size_t id) {
        return &(mouseTextures[id]);
    }

private:
    sf::Texture fieldTextures[6], enemyTextures[2], buttonTextures[2], particleTextures[4], mouseTextures[3];
    std::vector<std::string> CURRENT_MAP;
    std::vector<std::string> waves;
    std::vector<Directions> path;
    sf::Font font;
    size_t mapSize;
    int start;

    int findStart();
};

#endif
