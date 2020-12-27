#ifndef LOADER_HPP
#define LOADER_HPP

#include "iloader.h"
#include "enums.h"
#include <SFML/Graphics.hpp>
#include <fstream>

class Loader : public ILoader {
public:
    Loader() {}

    void loadTextures() override;

    void loadFont() override;

    void calculatePath() override;

    std::vector<std::string> *getCurrentMap() override {
        return &CURRENT_MAP;
    }

    std::vector<std::string> *getWaves() override {
        return &waves;
    }

    std::vector<Directions> *getPath() {
        return &path;
    }

    sf::Font *getFont() {
        return &font;
    }

    size_t getMapSize() override {
        return mapSize;
    }

    size_t getStart() override {
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
    sf::Texture fieldTextures[6], enemyTextures[2], buttonTextures[4], particleTextures[4], mouseTextures[3];
    std::vector<Directions> path;
    sf::Font font;
    int start;

    int findStart();
};

#endif
