#ifndef GAME_HPP
#define GAME_HPP

#include "enums.h"
#include "globals.hpp"
#include "button.h"
#include "game_map.h"
#include "sfml_enemy.h"
#include "sfml_enemy_spawner.h"
#include "sfml_tower.h"

#include <SFML/Graphics.hpp>

class Application {
    sf::RenderWindow window;
    bool fastForward = false;
    std::vector<sf::Sprite *> drawable;
    sf::Sprite mouseCursor, lastClickedTower;

    size_t lastClickedID;
    std::vector<Button> towerButtons;
    Button startButton, pauseButton;
    sf::Text statusText, towerDesc;

    bool running, waveRunning;
    size_t lives, money;

    GameMap map;
    std::vector<SfmlEnemy> enemies;
    EnemySpawner spawner;
    std::vector<SfmlTower> towers;
    std::vector<Particle> particles;

    void update();

    void handleMouseCursor();

    void handleMouseClick();

    void addDrawable(sf::Sprite *sprite);

    sf::Text createTextField(size_t posx, size_t posy, std::string strText, size_t textSize);

public:
    Application();

    void run();

    std::vector<size_t> getSize() { return std::vector<size_t>(sizeX, sizeY); }
};

#endif
