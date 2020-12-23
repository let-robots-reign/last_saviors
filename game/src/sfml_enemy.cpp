#include "sfml_enemy.h"

SfmlEnemy::SfmlEnemy(sf::Vector2f pos, size_t id, float tileWidth, Loader &loader)
        : Enemy(id + 1), id(id), location(0) {
    pos.x += tileWidth / 2;
    pos.y -= tileWidth / 2;
    setPosition(pos);
    setOrigin(10, 10);
    setTexture(*loader.getEnemyTexture(id));
    speed_ = 2;
    steps = tileWidth / speed_;
}

void SfmlEnemy::receiveDamage(size_t damage, Loader &loader) {
    health_ -= damage;
    if (health_ <= 0) {
        dead = true;
    } else {
        setTexture(*loader.getEnemyTexture(id));
    }
}

bool SfmlEnemy::go(std::vector<Directions> &path) {
    if (dead || location >= path.size()) {
        return false;
    }
    if (freezed) {
        if (freeze_counter >= steps * 2.5) {
            freezed = false;
        }
        ++freeze_counter;
        return true;
    }
    switch (path[location]) {
        case RIGHT:
            move(0, speed_);
            break;
        case LEFT:
            move(0, -speed_);
            break;
        case UP:
            move(-speed_, 0);
        case DOWN:
            move(speed_, 0);
            break;
    }
    ++counter;
    if (counter >= steps) {
        counter %= steps;
        ++location;
    }
    return true;
}
