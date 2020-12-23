#ifndef GAME_LOADER_H
#define GAME_LOADER_H

#include "iloader.h"
#include "enums.h"
#include <SFML/Graphics.hpp>

class Loader : public ILoader {
public:
    Loader() : ILoader(), start(-1) {}

    void loadTextures() override;

    void loadFont() override;

    std::string loadTowerDescription() const override;

    inline std::vector<std::string> getCurrentMap() const override {
        return CURRENT_MAP;
    }

    inline std::vector<std::string> getWaves() const override {
        return waves;
    }

    inline size_t getMapSize() const override {
        return mapSize;
    }

    inline size_t getStart() const override {
        return start;
    }

    inline std::vector<Directions> getPath() const {
        return path;
    }

    inline sf::Font getFont() const {
        return font;
    }

    void calculatePath() override;

    inline sf::Texture getFieldTexture(TileType field) const {
        return fieldTextures[static_cast<size_t>(field)];
    }

    inline sf::Texture getEnemyTexture(size_t enemyID) const {
        return enemyTextures[enemyID];
    }

    inline sf::Texture getButtonTexture(size_t buttonID) const {
        return buttonTextures[buttonID];
    }

    inline sf::Texture getParticleTextures(size_t particleID) const {
        return particleTextures[particleID];
    }

    inline sf::Texture getMouseTextures(size_t id) const {
        return mouseTextures[id];
    }

private:
    sf::Texture fieldTextures[4], enemyTextures[2], buttonTextures[2], particleTextures[2], mouseTextures[3];
    std::vector<Directions> path;
    sf::Font font;
    int start;

    int findStart();
};

#endif //GAME_LOADER_H
