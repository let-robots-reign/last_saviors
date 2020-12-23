#ifndef GAME_BUTTON_H
#define GAME_BUTTON_H

#include "enums.h"
#include "loader.h"
#include <SFML/Graphics.hpp>

class Button : public sf::Sprite {
public:
    Button() {}

    Button(size_t posx, size_t posy, size_t textureId, const Loader &loader);

    Button(size_t posx, size_t posy, FieldClass textureId, const Loader &loader);

    inline size_t getID() const {
        return id;
    }

    bool isClicked(const sf::Vector2i &click);

private:
    size_t width, height, id;

    void initButton(size_t posx, size_t posy, const sf::Texture &texture);
};

std::vector<Button> createTowerButtons(const Loader &loader);

#endif //GAME_BUTTON_H
