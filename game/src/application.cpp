#include "application.h"

Application::Application(Loader load) : loader(std::move(load)) {
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
    lastClickedTower.setTexture(*loader.getMouseTextures(2));

    running = false, waveRunning = false;
    coins = 200, lives = 20;
    lastClickedID = 0;
    towerButtons = createTowerButtons(loader);
    startButton = Button(705, 540, 0, loader);
    pauseButton = Button(605, 540, 1, loader);
    statusText = createTextField(605, 0, "", 22);
    towerDescription = createTextField(645, 100, towerDescString, 15);

    for (Button &button : towerButtons) {
        addDrawable(&button);
    }
    addDrawable(&startButton);
    addDrawable(&pauseButton);

    map = GameMap(sizeY, loader);
    for (size_t i = 0; i < loader.getMapSize(); ++i) {
        for (size_t j = 0; j < loader.getMapSize(); ++j) {
            addDrawable(map.getTileAt(i, j));
        }
    }
    // Spawner.setup();
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

        statusText.setString("Lives: " + std::to_string(lives) +
                             "\nMoney: " + std::to_string(coins));

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

    for (sf::Sprite *sprite : drawables) {
        window.draw(*sprite);
    }
//    for (Enemy &enemy : enemies) {
//        window.draw(enemy);
//    }
//    for (Particle &particle : particles) {
//        window.draw(particle);
//    }
    window.draw(statusText);
    window.draw(towerDescription);
    window.draw(lastClickedTower);
    window.draw(mouseCursor);
    window.display();
}

void Application::handleMouseCursor() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (map.isInField(mousePos)) {
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
    if (map.isInField(mousePos)) {
        if (lastClickedID > 1) {
            size_t *pos = map.getTileCoords(mousePos);
            Tile *field = map.getTileAt(pos[0], pos[1]);
            //placeTower(coins, field, Towers, static_cast<TileType>(lastClickedID));
            lastClickedID = 0;
            lastClickedTower.setPosition(lastClickedTower.getPosition().x, sizeY);
        }
    } else if (startButton.isClicked(mousePos)) {
//        if (!Spawner.isRunning()) {       // && enemies.size() == 0){
//            if (!Spawner.endOfWaves()) Spawner.start();
//        }
        running = true;
    } else if (pauseButton.isClicked(mousePos)) {
        running = false;
    }
    for (Button &button : towerButtons) {
        if (button.isClicked(mousePos)) {
            lastClickedID = button.getID();
            lastClickedTower.setPosition(lastClickedTower.getPosition().x, 100 * (button.getID() - 1));
        }
    }
}

void Application::addDrawable(sf::Sprite *sprite) {
    drawables.push_back(sprite);
}

sf::Text Application::createTextField(size_t posx, size_t posy, std::string strText, size_t textSize) {
    sf::Text textField(strText, *(loader.getFont()));
    textField.setPosition(posx, posy);
    textField.setColor(sf::Color(188, 175, 105));
    textField.setCharacterSize(textSize);
    return textField;
}
