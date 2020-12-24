#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "globals.hpp"
#include "enums.h"
#include <SFML/Graphics.hpp>

class Button : public sf::Sprite {
public:
    Button() {}

    Button(size_t posx, size_t posy, size_t textureID);

    Button(size_t posx, size_t posy, TileType textureID);

    size_t getID() { return id; }

    bool isClicked(const sf::Vector2i &click);

private:
    size_t width, height, id;
};

std::vector<Button> createTowerButtons();

#endif
