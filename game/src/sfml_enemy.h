#ifndef LAST_SAVIORS_SFML_ENEMY_H
#define LAST_SAVIORS_SFML_ENEMY_H

#include "enums.h"
#include "enemy.h"
#include "loader.h"
#include <SFML/Graphics.hpp>

class SfmlEnemy : public sf::Sprite, public Enemy {
public:
    SfmlEnemy(sf::Vector2f pos, size_t id, float tileWidth, Loader &loader);

    void receiveDamage(size_t damage, Loader &loader);

    bool go(std::vector<Directions> &path);

private:
    void attack(std::shared_ptr<Attackable> &target, unsigned int current_time) override;

    std::shared_ptr<Attackable> findTarget(std::vector<std::shared_ptr<Attackable>> &possible_targets) override;

    bool canAttack(const std::shared_ptr<Attackable> &target) override;

private:
    size_t location, steps, id;
};

#endif //LAST_SAVIORS_SFML_ENEMY_H
