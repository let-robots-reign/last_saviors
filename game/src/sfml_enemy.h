#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "pawn.h"
#include "enums.h"
#include "globals.h"
#include <SFML/Graphics.hpp>

class SfmlEnemy : public Pawn, public sf::Sprite {
public:
    SfmlEnemy(sf::Vector2f pos, size_t id_, float tileWidth);

    void hurt(size_t damage);

    bool go(std::vector<Directions> &path);

private:
    size_t id;
};

#endif
