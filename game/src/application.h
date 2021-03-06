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

#include "TCPClient.h"
#include "GameClientLogic.h"
#include "ClientQuiz.h"

class Application {
public:
    Application();

    void run();

    std::vector<size_t> getSize() { return std::vector<size_t>(sizeX, sizeY); }

    static sfe::RichText createTextField(size_t posx, size_t posy, size_t textSize);

    inline static ClientQuiz currentQuiz = ClientQuiz();
    inline static bool resultReceived = false;
    inline static bool currentQuizResult = false;

private:
    size_t sizeX, sizeY;
    static constexpr size_t COINS_FINE_FOR_CLOSE = 20;
    static constexpr size_t COINS_FOR_RIGHT_ANSWER = 20;
    static constexpr size_t COINS_FINE_FOR_WRONG_ANSWER = 10;

    TCPClient<GameClientLogic> Client;

    sf::RenderWindow window;
    std::vector<sf::Sprite *> drawable;
    sf::Sprite mouseCursor, lastClickedTower;

    size_t lastClickedID;
    std::vector<Button> towerButtons;
    Button startButton, pauseButton, upgradeButton, quizButton;
    sfe::RichText statusText, towerDescription;
    QuizWidget quizWidget;

    bool running, waveRunning, showQuiz, wantToUpgrade;
    size_t coins;
    int lives;

    GameMap map;
    std::vector<SfmlEnemy> enemies;
    EnemySpawner spawner;
    std::vector<SfmlTower> towers;
    std::vector<Particle> particles;

    std::pair<size_t, size_t> readSizesFromConfig();

    void fetchQuiz();

    void sendAnswer();

    void checkQuiz();

    void update();

    void handleMouseCursor();

    void handleMouseClick();

    void addDrawable(sf::Sprite *sprite);
};


#endif
