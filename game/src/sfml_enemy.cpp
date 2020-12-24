#include "sfml_enemy.h"

SfmlEnemy::SfmlEnemy(sf::Vector2f pos, size_t id_, float tileWidth) : sf::Sprite(), Pawn(), id(id_) {
    pos.x += tileWidth / 2;
    pos.y -= tileWidth / 2;
    setPosition(pos);
    setOrigin(10, 10);
    setTexture(*loader.getEnemyTexture(id));
    dead = false, freezed = false;
    value = health = id + 1;
    location = counter = 0;
    speed = getSpeed();
    steps = tileWidth / speed;
}

void SfmlEnemy::hurt(size_t damage) {
    if (damage >= health) {
        health = 0;
        dead = true;
    } else {
        health -= damage;
        setTexture(*loader.getEnemyTexture(id - 1));
    }
}

bool SfmlEnemy::go(std::vector<Directions> &path) {
    if (dead || location >= path.size()) {
        return false;
    }
    if (freezed) {
        if (freezeCounter >= steps * 2.5) {
            freezed = false;
        }
        ++freezeCounter;
        return true;
    }
    switch (path[location]) {
        case RIGHT:
            move(0, speed);
            break;
        case LEFT:
            move(0, -speed);
            break;
        case UP:
            move(-speed, 0);
            break;
        case DOWN:
            move(speed, 0);
            break;
    }
    ++counter;
    if (counter >= steps) {
        counter %= steps;
        ++location;
    }
    return true;
}
