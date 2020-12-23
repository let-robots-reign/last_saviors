#ifndef GAME_BUTTON_H
#define GAME_BUTTON_H

#include "enums.h"
#include <SFML/Graphics.hpp>

class Button : public sf::Sprite {
public:
    Button() {}

    Button(size_t posx, size_t posy, size_t textureId, const sf::Texture& buttonTexture);

    Button(size_t posx, size_t posy, FieldClass textureId, const sf::Texture& buttonTexture);

    inline size_t getID() const {
        return id;
    }

    bool isClicked(const sf::Vector2i &click);

private:
    size_t width, height, id;

    void initButton(size_t posx, size_t posy, const sf::Texture& buttonTexture);
};

std::vector<Button> createTowerButtons();

#endif //GAME_BUTTON_H
