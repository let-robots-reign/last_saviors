#include "application.h"

#include <sstream>
#include <fstream>

Application::Application() {
    std::tie(sizeX, sizeY) = readSizesFromConfig();
    loader.loadTextures();
    loader.loadMaps();
    loader.loadFont();
    loader.loadWaves();
    loader.calculatePath();
    std::string towerDescString = loader.loadTowerDescription();

    window.create(sf::VideoMode(sizeX, sizeY), "Last Saviors");
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);
    lastClickedTower.setPosition(605, sizeY);
    lastClickedTower.setTexture(*loader.getMouseTextures(Loader::MOUSE_INACTIVE_SELECT_ID));

    running = false, waveRunning = false, showQuiz = false;
    coins = 200, lives = 20;
    lastClickedID = 0;
    towerButtons = createTowerButtons();
    startButton = Button(705, 500, Loader::BUTTON_START_ID);
    pauseButton = Button(605, 500, Loader::BUTTON_PAUSE_ID);
    upgradeButton = Button(600, 350, Loader::BUTTON_UPGRADE_ID);
    quizButton = Button(600, 410, Loader::BUTTON_QUIZ_ID);
    statusText = createTextField(605, 0, "", 22, sf::Color(188, 175, 105));
    towerDescription = createTextField(645, 100, towerDescString, 15, sf::Color(188, 175, 105));

    for (auto &button : towerButtons) {
        addDrawable(&button);
    }
    addDrawable(&startButton);
    addDrawable(&pauseButton);
    addDrawable(&upgradeButton);
    addDrawable(&quizButton);

    map = GameMap(sizeY);
    for (size_t i = 0; i < loader.getMapSize(); ++i) {
        for (size_t j = 0; j < loader.getMapSize(); ++j) {
            addDrawable(map.getTileAt(i, j));
        }
    }
    spawner.setup();
}

void Application::run() {
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        handleMouseClick();
                    }
                default:
                    break;
            }
        }
        if (running) {
            spawner.spawn(enemies);
            spawner.move(enemies, coins, lives);

            for (auto &tower : towers) {
                tower.shoot(enemies, particles);
            }
            updateParticles(particles);

            if (spawner.movingFinished()) {
                running = false;
                particles = {};
            }
            if (lives <= 0) {
                window.close();
            }
        }

        std::stringstream status;
        status << "Lives: " << lives << "\nCoins: " << coins << "$\nWave: "
               << spawner.getWave() + 1 << "/" << spawner.getMaxWaves();
        statusText.setString(status.str());

        handleMouseCursor();
        update();
    }
}

std::pair<size_t, size_t> Application::readSizesFromConfig() {
    std::ifstream sizes("data/sizes.txt");
    size_t x = 0, y = 0;
    sizes >> x >> y;
    return {x, y};
}

QuizPuzzle Application::getQuiz() {
    return QuizPuzzle(0, "How are you?\ngdfgfdg\ngfg\nffffffffffff", {"Good", "Fine", "So-so", "Bad"}, 0);
}

void Application::update() {
    window.clear(sf::Color(90, 106, 41));

    for (auto *sprite : drawable) {
        window.draw(*sprite);
    }
    for (auto &enemy : enemies) {
        window.draw(enemy);
    }
    for (auto &particle : particles) {
        window.draw(particle);
    }

    if (showQuiz) {
        QuizPuzzle quiz = getQuiz();
        quizWidget = QuizWidget(quiz);
        window.draw(quizWidget);
    }

    window.draw(statusText);
    window.draw(towerDescription);
    window.draw(lastClickedTower);
    window.draw(mouseCursor);
    window.display();
}

void Application::handleMouseCursor() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (map.isInMap(mousePos) && !showQuiz) {
        size_t *pos = map.getTileCoords(mousePos);
        float fieldWidth = static_cast<float>(sizeY) / loader.getMapSize();
        mouseCursor.setPosition(fieldWidth * pos[0], fieldWidth * pos[1]);
        mouseCursor.setTexture(*loader.getMouseTextures(Loader::MOUSE_ACTIVE_SELECT_ID));
    } else {
        mouseCursor.setPosition(static_cast<sf::Vector2f>(mousePos));
        mouseCursor.setTexture(*loader.getMouseTextures(Loader::MOUSE_POINTER_ID));
    }
}

void Application::handleMouseClick() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (map.isInMap(mousePos)) {
        if (lastClickedID > 1) {
            size_t *pos = map.getTileCoords(mousePos);
            Tile *field = map.getTileAt(pos[0], pos[1]);
            placeTower(coins, field, towers, static_cast<TileType>(lastClickedID));
            lastClickedID = 0;
            lastClickedTower.setPosition(lastClickedTower.getPosition().x, sizeY);
        }
    } else if (startButton.isClicked(mousePos)) {
        if (!spawner.isRunning()) {
            if (!spawner.endOfWaves()) spawner.start();
        }
        running = true;
    } else if (pauseButton.isClicked(mousePos)) {
        running = false;
    } else if (quizButton.isClicked(mousePos)) {
        showQuiz = true;
    }

    for (auto &button : towerButtons) {
        if (button.isClicked(mousePos)) {
            lastClickedID = button.getID();
            lastClickedTower.setPosition(lastClickedTower.getPosition().x, 100 * (button.getID() - 1));
        }
    }
}

void Application::addDrawable(sf::Sprite *sprite) {
    drawable.push_back(sprite);
}

sf::Text Application::createTextField(size_t posx, size_t posy, const std::string &strText, size_t textSize,
                                      const sf::Color &color) {
    sf::Text textField(strText, *(loader.getFont()));
    textField.setPosition(posx, posy);
    textField.setColor(color);
    textField.setCharacterSize(textSize);
    return textField;
}
