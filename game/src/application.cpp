#include "application.h"

#include <sstream>
#include <utility>
#include <iostream>

Application::Application(Loader load) : loader(std::move(load)) {
    std::tie(sizeX, sizeY) = readSizesFromConfig();
    std::cout << "Started loading\n";
    loader.loadTextures();
    std::cout << "1\n";
    loader.loadMaps();
    std::cout << "2\n" << loader.getMapSize() << std::endl;
    loader.loadFont();
    std::cout << "3\n";
    loader.loadWaves();
    std::cout << "4\n";
    loader.calculatePath();
    std::cout << "5\n";
    std::string towersDescription = loader.loadTowerDescription();
    std::cout << "Finished loading\n";

    window.create(sf::VideoMode(sizeX, sizeY), "Last Saviors");
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);
    lastClickedTower.setPosition(605, sizeY);
    lastClickedTower.setTexture(loader.getMouseTextures(Loader::MOUSE_INACTIVE_SELECT_ID));

    running = false;
    waveRunning = false;
    coins = 200;
    lives = 20;
    lastClickedID = 0;

    towerButtons = createTowerButtons(loader);
    std::cout << "6\n";
    startButton = Button(705, 540, Loader::BUTTON_START_ID, loader);
    pauseButton = Button(605, 540, Loader::BUTTON_PAUSE_ID, loader);
    statusText = createTextField(605, 0, "", 22);
    towerDescription = createTextField(645, 100, towersDescription, 15);
    std::cout << "7\n";
    for (auto &button : towerButtons) {
        addDrawable(&button);
    }
    addDrawable(&startButton);
    addDrawable(&pauseButton);
    std::cout << "8\n";
    map = GameMap(sizeY, loader);
    for (size_t i = 0; i < loader.getMapSize(); ++i) {
        for (size_t j = 0; j < loader.getMapSize(); ++j) {
            Tile tile = map.getTileAt(i, j);
            addDrawable(&tile);
        }
    }
    std::cout << "Finished constructor\n";
}

void Application::run() {
    while (window.isOpen()) {
        std::cout << "Here\n";
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
                    break;
                default:
                    break;
            }
        }
//
//        if (running) {
//            // spawn and move enemies
//            // towers shoot
//            // update particles
//        }

        std::stringstream status;
        status << "Lives: " << lives << "\nCoins: " << coins << "$";
        statusText.setString(status.str());

        handleMouseCursor();
        update();
    }
}

std::pair<size_t, size_t> Application::readSizesFromConfig() const {
    std::ifstream sizes("assets/sizes.txt");
    size_t x = 0, y = 0;
    sizes >> x >> y;
    return {x, y};
}

void Application::update() {
    std::cout << "Updating\n";
    window.clear(sf::Color(90, 106, 41));

    for (sf::Sprite *sprite : drawables) {
        window.draw(*sprite);
    }
    // draw enemies and particles
    window.draw(statusText);
    window.draw(towerDescription);
    //window.draw(lastClickedTower);
    window.draw(mouseCursor);
    window.display();
    std::cout << "Displaying\n";
}

void Application::handleMouseCursor() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (map.isInField(mousePos)) {
        size_t *pos = map.getTileCoords(mousePos);
        float tileWidth = static_cast<float>(sizeY) / loader.getMapSize();
        mouseCursor.setPosition(tileWidth * pos[0], tileWidth * pos[1]);
        mouseCursor.setTexture(loader.getMouseTextures(Loader::MOUSE_ACTIVE_SELECT_ID));
    } else {
        mouseCursor.setPosition(static_cast<sf::Vector2f>(mousePos));
        mouseCursor.setTexture(loader.getMouseTextures(Loader::MOUSE_POINTER_ID));
    }
}

void Application::handleMouseClick() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (map.isInField(mousePos)) {
        if (lastClickedID > 1) {
            size_t *pos = map.getTileCoords(mousePos);
            Tile tile = map.getTileAt(pos[0], pos[1]);
            // place tower
            lastClickedID = 0;
            lastClickedTower.setPosition(lastClickedTower.getPosition().x, sizeY);
        }
    } else if (startButton.isClicked(mousePos)) {
        // start waves
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
    drawables.push_back(sprite);
}

sf::Text Application::createTextField(size_t posx, size_t posy, const std::string& text, size_t textSize) {
    sf::Text textField(text, loader.getFont());
    textField.setPosition(posx, posy);
    textField.setColor(sf::Color(188, 175, 105));
    textField.setCharacterSize(textSize);
    return textField;
}
