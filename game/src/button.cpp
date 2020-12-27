#include "button.h"

Button::Button(size_t posx, size_t posy, size_t textureID) {
    initButton(posx, posy, textureID, *loader.getButtonTexture(textureID));
}

Button::Button(size_t posx, size_t posy, TileType textureID) {
    initButton(posx, posy, textureID, *loader.getFieldTexture(textureID));
}

void Button::initButton(size_t posx, size_t posy, size_t textureID, const sf::Texture &texture) {
    id = textureID;
    setPosition(posx, posy);
    setTexture(texture);
    sf::FloatRect rect = getLocalBounds();
    width = rect.width;
    height = rect.height;
}

bool Button::isClicked(const sf::Vector2i &click) {
    sf::Vector2f pos = getPosition();
    size_t x = click.x - pos.x, y = click.y - pos.y;
    return x > 0 && x < width && y > 0 && y < height;
}

std::vector<Button> createTowerButtons() {
    std::vector<Button> towerButtons;
    towerButtons.emplace_back(605, 100, BASIC_TOWER);
    towerButtons.emplace_back(605, 200, CIRCLE_TOWER);
    return towerButtons;
}
