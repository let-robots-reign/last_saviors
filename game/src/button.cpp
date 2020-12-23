#include "button.h"

Button::Button(size_t posx, size_t posy, size_t textureId, const sf::Texture &buttonTexture)
        : width(0), height(0), id(textureId) {
    initButton(posx, posy, buttonTexture);
}

Button::Button(size_t posx, size_t posy, FieldClass textureId, const sf::Texture &buttonTexture)
        : width(0), height(0), id(textureId) {
    initButton(posx, posy, buttonTexture);
}

bool Button::isClicked(const sf::Vector2i &click) {
    sf::Vector2f curPos = getPosition();
    size_t x = click.x - curPos.x;
    size_t y = click.y - curPos.y;
    return (x > 0 && x < width) && (y > 0 && y < height);
}

void Button::initButton(size_t posx, size_t posy, const sf::Texture &buttonTexture) {
    setPosition(posx, posy);
    setTexture(buttonTexture);
    sf::FloatRect rect = getLocalBounds();
    width = rect.width;
    height = rect.height;
}

std::vector<Button> createTowerButtons() {
    std::vector<Button> towerButtons;
    towerButtons.push_back(Button(605, 100, BASIC_TOWER));

}
