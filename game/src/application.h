#ifndef GAME_HPP
#define GAME_HPP

#include "event.h"
#include "functor_event_handler.h"
#include "enums.h"
#include "vars.h"
#include "button.h"
#include "game_map.h"
#include "sfml_enemy.h"
#include "sfml_enemy_spawner.h"
#include "sfml_tower.h"
#include "rich_text.h"
#include "quiz_widget.h"

#include <SFML/Graphics.hpp>

class Application {
public:
    Application();

    void run();

    std::vector<size_t> getSize() { return std::vector<size_t>(sizeX, sizeY); }

    static sfe::RichText createTextField(size_t posx, size_t posy, size_t textSize);

private:
    size_t sizeX, sizeY;
    static constexpr size_t COINS_FINE_FOR_CLOSE = 20;

    sf::RenderWindow window;
    std::vector<sf::Sprite *> drawable;
    sf::Sprite mouseCursor, lastClickedTower;

    size_t lastClickedID;
    std::vector<Button> towerButtons;
    Button startButton, pauseButton, upgradeButton, quizButton;
    sfe::RichText statusText, towerDescription;
    QuizWidget quizWidget;

    bool running, waveRunning, showQuiz;
    size_t coins;
    int lives;

    GameMap map;
    std::vector<SfmlEnemy> enemies;
    EnemySpawner spawner;
    std::vector<SfmlTower> towers;
    std::vector<Particle> particles;

    std::pair<size_t, size_t> readSizesFromConfig();

    QuizPuzzle getQuiz();

    void checkQuiz();

    void update();

    void handleMouseCursor();

    void handleMouseClick();

    void addDrawable(sf::Sprite *sprite);
};

#endif
