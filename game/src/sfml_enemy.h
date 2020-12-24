#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "enums.h"
#include "globals.h"
#include <SFML/Graphics.hpp>

class SfmlEnemy : public sf::Sprite {
public:
    SfmlEnemy(sf::Vector2f pos, size_t id_, float fieldWidth);

    size_t getValue() { return std::max<size_t>(value / 2 + 1, 2); }

    size_t getHealth() { return health; }

    bool isDead() { return dead; }

    bool isFreezed() { return freezed; }

    void freeze();

    void hurt(size_t damage);

    bool go(std::vector<Directions> &path);

private:
    size_t id, health, counter, steps, value, freezeCounter;
    unsigned int location;
    float speed;
    bool dead, freezed;
};

#endif
