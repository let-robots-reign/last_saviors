#ifndef GAME_LOADER_H
#define GAME_LOADER_H

#include "iloader.h"
#include "enums.h"
#include <SFML/Graphics.hpp>

class Loader : public ILoader {
public:
    Loader() = default;

    void loadTextures() override;

    void loadMaps() override;

    void loadWaves() override;

    std::string loadTowerDescription() override {
        return std::string();
    }

    inline std::vector<std::string> *getCurrentMap() override {
        return &CURRENT_MAP;
    }

    inline std::vector<std::string> *getWaves() override {
        return &waves;
    }

    inline size_t getMapSize() override {
        return mapSize;
    }

    inline size_t getStart() override {
        return start;
    }

    inline std::vector<Directions> *getPath() {
        return &path;
    }

    inline sf::Font *getFont() {
        return &font;
    }

    void calculatePath();

    inline sf::Texture *getFieldTexture(FieldClass field) {
        return &(fieldTextures[static_cast<size_t>(field)]);
    }

    inline sf::Texture *getEnemyTexture(size_t enemyID) {
        return &(enemyTextures[enemyID]);
    }

    inline sf::Texture *getButtonTexture(size_t buttonID) {
        return &(buttonTextures[buttonID]);
    }

    inline sf::Texture *getParticleTextures(size_t particleID) {
        return &(particleTextures[particleID]);
    }

    inline sf::Texture *getMouseTextures(size_t id) {
        return &(mouseTextures[id]);
    }

private:
    sf::Texture fieldTextures[6], enemyTextures[2], buttonTextures[2], particleTextures[2], mouseTextures[3];
    std::vector<std::string> CURRENT_MAP;
    std::vector<std::string> waves;
    std::vector<Directions> path;
    sf::Font font;
    size_t mapSize, start;

    size_t findStart();
};

#endif //GAME_LOADER_H
