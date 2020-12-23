#include "button.h"

Button::Button(size_t posx, size_t posy, size_t textureId, Loader &loader)
        : width(0), height(0), id(textureId) {
    initButton(posx, posy, *loader.getButtonTexture(textureId));
}

Button::Button(size_t posx, size_t posy, TileType textureId, Loader &loader)
        : width(0), height(0), id(textureId) {
    initButton(posx, posy, *loader.getFieldTexture(textureId));
}

bool Button::isClicked(const sf::Vector2i &click) {
    sf::Vector2f curPos = getPosition();
    size_t x = click.x - curPos.x;
    size_t y = click.y - curPos.y;
    return (x > 0 && x < width) && (y > 0 && y < height);
}

void Button::initButton(size_t posx, size_t posy, const sf::Texture &texture) {
    setPosition(posx, posy);
    setTexture(texture);
    sf::FloatRect rect = getLocalBounds();
    width = rect.width;
    height = rect.height;
}

std::vector<Button> createTowerButtons(Loader &loader) {
    std::vector<Button> towerButtons;
    towerButtons.emplace_back(605, 100, BASIC_TOWER, loader);
    towerButtons.emplace_back(605, 200, CIRCLE_TOWER, loader);
    return towerButtons;
}