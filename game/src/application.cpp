#include "application.h"

#include <sstream>
#include <utility>

Application::Application(Loader load) : loader(std::move(load)) {
    std::tie(sizeX, sizeY) = readSizesFromConfig();

    loader.loadTextures();
    loader.loadMaps();
    loader.loadFont();
    loader.loadWaves();
    loader.calculatePath();
    std::string towersDescription = loader.loadTowerDescription();

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
    startButton = Button(705, 540, Loader::BUTTON_START_ID, loader);
    pauseButton = Button(605, 540, Loader::BUTTON_PAUSE_ID, loader);
    statusText = createTextField(605, 0, "", 22);
    towerDescription = createTextField(645, 100, towersDescription, 15);

    for (auto &button : towerButtons) {
        addDrawable(&button);
    }
    addDrawable(&startButton);
    addDrawable(&pauseButton);

    map = GameMap(sizeY, loader);
    for (size_t i = 0; i < loader.getMapSize(); ++i) {
        for (size_t j = 0; j < loader.getMapSize(); ++j) {
            Tile tile = map.getTileAt(i, j);
            addDrawable(&tile);
        }
    }
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
                    break;
                default:
                    break;
            }
        }

        if (running) {
            // spawn and move enemies
            // towers shoot
            // update particles
        }

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
    window.clear(sf::Color(90, 106, 41));

    for (auto *sprite : drawables) {
        window.draw(*sprite);
    }
    // draw enemies and particles
    window.draw(statusText);
    window.draw(towerDescription);
    //window.draw(lastClickedTower);
    window.draw(mouseCursor);
    window.display();
}

void Application::handleMouseCursor() {
    sf::Vector2i mouserPos = sf::Mouse::getPosition(window);
    if (map.isInField(mouserPos)) {
        size_t *pos = map.getTileCoords(mouserPos);
        float tileWidth = static_cast<float>(sizeY) / loader.getMapSize();
        mouseCursor.setPosition(tileWidth * pos[0], tileWidth * pos[1]);
        mouseCursor.setTexture(loader.getMouseTextures(Loader::MOUSE_ACTIVE_SELECT_ID));
    } else {
        mouseCursor.setPosition(static_cast<sf::Vector2f>(mouserPos));
        mouseCursor.setTexture(loader.getMouseTextures(Loader::MOUSE_POINTER_ID));
    }
}

void Application::handleMouseClick() {

}

void Application::addDrawable(sf::Sprite *sprite) {

}

sf::Text Application::createTextField(size_t posx, size_t posy, std::string text, size_t textLength) {
    return sf::Text();
}
