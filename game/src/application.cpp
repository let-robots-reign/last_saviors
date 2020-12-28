#include "application.h"

#include "Packets.h"

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

    running = false, waveRunning = false, showQuiz = false, wantToUpgrade = false;
    coins = 200, lives = 20;
    lastClickedID = 0;
    towerButtons = createTowerButtons();
    startButton = Button(705, 500, Loader::BUTTON_START_ID);
    pauseButton = Button(605, 500, Loader::BUTTON_PAUSE_ID);
    upgradeButton = Button(600, 350, Loader::BUTTON_UPGRADE_ID);
    quizButton = Button(600, 410, Loader::BUTTON_QUIZ_ID);
    statusText = createTextField(605, 0, 22);
    towerDescription = createTextField(645, 100, 15);
    towerDescription << sf::Color(188, 175, 105) << towerDescString;

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

        statusText = createTextField(605, 0, 22);
        statusText << sf::Color(188, 175, 105) << sf::Text::Bold << "Lives: " << std::to_string(lives)
                   << "\nCoins: " << sf::Color::Yellow << std::to_string(coins) << sf::String(L" ©\n")
                   << sf::Color(188, 175, 105) << "Wave: " << std::to_string(spawner.getWave())
                   << " /" << std::to_string(spawner.getMaxWaves());

        Client.ReceiveAndProcess();
        if (!currentQuiz.question.empty()) {
            showQuiz = true;
        }
        if (resultReceived) {
            std::cout << "Correctness: " << currentQuizResult << std::endl;

            if (currentQuizResult) {
                coins += COINS_FOR_RIGHT_ANSWER;
            } else {
                if (COINS_FINE_FOR_WRONG_ANSWER >= coins) {
                    coins = 0;
                } else {
                    coins -= COINS_FINE_FOR_WRONG_ANSWER;
                }
            }

            resultReceived = false;
            showQuiz = false;
            currentQuiz = ClientQuiz();
            quizWidget = QuizWidget();
        }

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

void Application::fetchQuiz() {
    std::cout << "Getting Quiz\n";
    if (!Client.Connected()) {
        std::cout << "Not connected\n";
        Client.Connect(Address(*IPAddress::Create(std::string("46.138.240.15")), 3000));
        std::cout << "Attempted to connect " << Client.Connected() << "\n";
    }

    std::cout << "Sending Packet\n";
    Client.Send(QuizRequestPacket().ToPacket());
}

void Application::checkQuiz() {
    int userAnswer = quizWidget.getCurrentUserAnswer();
    std::cout << "Checking Quiz\nUser answer is " << quizWidget.getCurrentUserAnswer() << std::endl;
    if (userAnswer == QuizWidget::CLICKED_CLOSE) {
        if (COINS_FINE_FOR_CLOSE > coins) {
            coins = 0;
        } else {
            coins -= COINS_FINE_FOR_CLOSE;
        }
        quizWidget = QuizWidget();
        showQuiz = false;

        Client.Send(QuizAbortionPacket().ToPacket());
    }

    Client.Send(QuizAnswerPacket(userAnswer).ToPacket());
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
        if (!quizWidget.isInitialized()) {
            quizWidget = QuizWidget(currentQuiz);
        }
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
        if (wantToUpgrade && map.getTileAt(pos[0], pos[1])->getTileType() > 1) {
            mouseCursor.setTexture(*loader.getMouseTextures(Loader::MOUSE_UPGRADE_ID));
        } else {
            mouseCursor.setTexture(*loader.getMouseTextures(Loader::MOUSE_ACTIVE_SELECT_ID));
        }
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
            if (!spawner.endOfWaves()) {
                spawner.start();
            }
        }
        running = true;
    } else if (pauseButton.isClicked(mousePos)) {
        running = false;
        showQuiz = false;
    } else if (quizButton.isClicked(mousePos) && !showQuiz && running) {
        fetchQuiz();
    } else if (upgradeButton.isClicked(mousePos) && !showQuiz && running) {
        wantToUpgrade = true;
    }

    if (showQuiz && running && quizWidget.checkButtonClicked(mousePos) != QuizWidget::CLICKED_OUTSIDE) {
        checkQuiz();
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

sfe::RichText Application::createTextField(size_t posx, size_t posy, size_t textSize) {
    sfe::RichText textField(*(loader.getFont()));
    textField.setPosition(posx, posy);
    textField.setCharacterSize(textSize);
    return textField;
}
