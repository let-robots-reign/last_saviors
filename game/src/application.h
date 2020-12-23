#ifndef GAME_HPP
#define GAME_HPP

#include "enums.h"
#include "globals.hpp"
#include "button.h"
#include "game_map.h"

#include <SFML/Graphics.hpp>

class Game {
    sf::RenderWindow window;
    std::vector<sf::Sprite *> drawables;
    sf::Sprite mouseCursor, lastClickedTower;

    size_t lastClickedID;
    std::vector<Button> towerButtons;
    Button startButton, pauseButton;
    sf::Text statusText, towerDescription;

    bool running, waveRunning;
    size_t lives, coins;

    GameMap map;

    void update();

    void handleMouseCursor();

    void handleMouseClick();

    void addDrawable(sf::Sprite *sprite);

    sf::Text createTextField(size_t posx, size_t posy, std::string strText, size_t textSize);

public:
    Game();

    void run();

    std::vector<size_t> getSize() { return std::vector<size_t>(sizeX, sizeY); }
};

#endif
