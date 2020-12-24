#ifndef GAME_HPP
#define GAME_HPP

#include "enums.h"
#include "globals.h"
#include "button.h"
#include "game_map.h"
#include "sfml_enemy.h"
#include "sfml_enemy_spawner.h"
#include "sfml_tower.h"

#include <SFML/Graphics.hpp>

class Application {
public:
    Application();

    void run();

    std::vector<size_t> getSize() { return std::vector<size_t>(sizeX, sizeY); }

private:
    size_t sizeX, sizeY;

    sf::RenderWindow window;
    std::vector<sf::Sprite *> drawable;
    sf::Sprite mouseCursor, lastClickedTower;

    size_t lastClickedID;
    std::vector<Button> towerButtons;
    Button startButton, pauseButton;
    sf::Text statusText, towerDesc;

    bool running, waveRunning;
    size_t money;
    int lives;

    GameMap map;
    std::vector<SfmlEnemy> enemies;
    EnemySpawner spawner;
    std::vector<SfmlTower> towers;
    std::vector<Particle> particles;

    std::pair<size_t, size_t> readSizesFromConfig();

    void update();

    void handleMouseCursor();

    void handleMouseClick();

    void addDrawable(sf::Sprite *sprite);

    sf::Text createTextField(size_t posx, size_t posy, const std::string& strText, size_t textSize);
};

#endif
