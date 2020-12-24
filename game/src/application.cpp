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
    lastClickedTower.setPosition(605, sizeY);   // out of screen
    lastClickedTower.setTexture(*loader.getMouseTextures(2));

    running = false, waveRunning = false;
    money = 200, lives = 20;
    lastClickedID = 0;
    towerButtons = createTowerButtons();
    startButton = Button(705, 540, 0);
    pauseButton = Button(605, 540, 1);
    statusText = createTextField(605, 0, "", 22);
    towerDesc = createTextField(645, 100, towerDescString, 15);

    for (auto &button : towerButtons) {
        addDrawable(&button);
    }
    addDrawable(&startButton);
    addDrawable(&pauseButton);

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
                    if (event.mouseButton.button == sf::Mouse::Left) handleMouseClick();
                default:
                    break;
            }
        }
        if (running) {
            spawner.spawn(enemies);
            spawner.move(enemies, money, lives);

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
        status << "Lives: " << lives << "\nCoins: " << money << "$\nWave: "
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
    window.draw(statusText);
    window.draw(towerDesc);
    window.draw(lastClickedTower);
    window.draw(mouseCursor);
    window.display();
}

void Application::handleMouseCursor() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (map.isInMap(mousePos)) {
        size_t *pos = map.getTileCoords(mousePos);
        float fieldWidth = static_cast<float>(sizeY) / loader.getMapSize();
        mouseCursor.setPosition(fieldWidth * pos[0], fieldWidth * pos[1]);
        mouseCursor.setTexture(*loader.getMouseTextures(1));
    } else {
        mouseCursor.setPosition(static_cast<sf::Vector2f>(mousePos));
        mouseCursor.setTexture(*loader.getMouseTextures(0));
    }
}

void Application::handleMouseClick() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (map.isInMap(mousePos)) {
        if (lastClickedID > 1) {
            size_t *pos = map.getTileCoords(mousePos);
            Tile *field = map.getTileAt(pos[0], pos[1]);
            placeTower(money, field, towers, static_cast<TileType>(lastClickedID));
            lastClickedID = 0;
            lastClickedTower.setPosition(lastClickedTower.getPosition().x, sizeY);
        }
    } else if (startButton.isClicked(mousePos)) {
        if (!spawner.isRunning()) {       // && enemies.size() == 0){
            if (!spawner.endOfWaves()) spawner.start();
        }
        running = true;
    } else if (pauseButton.isClicked(mousePos)) {
        running = false;
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

sf::Text Application::createTextField(size_t posx, size_t posy, const std::string &strText, size_t textSize) {
    sf::Text textField(strText, *(loader.getFont()));
    textField.setPosition(posx, posy);
    textField.setColor(sf::Color(188, 175, 105));
    textField.setCharacterSize(textSize);
    return textField;
}
