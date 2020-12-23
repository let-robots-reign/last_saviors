#ifndef LAST_SAVIORS_APPLICATION_H
#define LAST_SAVIORS_APPLICATION_H

#include "enums.h"
#include "button.h"
#include "game_map.h"
#include <SFML/Graphics.hpp>

class Game {
public:
    Game();

    void run();

    inline std::vector<size_t> getSize() const {
        return std::vector<size_t>(sizeX, sizeY);
    }

private:
    size_t sizeX, sizeY;
    const std::vector<size_t> towerPrices;

    sf::RenderWindow window;
    bool fastForward = false;
    std::vector<sf::Sprite *> drawables;
    sf::Sprite mouseCursor, lastClickedTower;

    size_t lastClickedID;
    std::vector<Button> towerButtons;
    Button startButton, pauseButton;
    sf::Text statusText, towerDescription;

    bool running, waveRunning;
    size_t lives, coins;

    GameMap map;
    // std::vector<Enemy *> enemies;
    // enemies factory
    // std::vector<Tower *> towers;
    // std::vector<Bullet *> bullets;

    void readConfigFile();

    void update();

    void handleMouseCursor();

    void handleMouseClick();

    void addDrawable(sf::Sprite *sprite);

    sf::Text createTextField(size_t posx, size_t posy, std::string text, size_t textLength);
};

#endif //LAST_SAVIORS_APPLICATION_H
