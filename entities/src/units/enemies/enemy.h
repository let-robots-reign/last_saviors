#ifndef LAST_SAVIORS_ENEMY_H
#define LAST_SAVIORS_ENEMY_H

#include <ctime>
#include <memory>
#include <vector>

#include "attackable.h"
#include "player.h"
#include "unit.h"

class Enemy : public Attackable {
protected:
    unsigned int time_of_last_attack_;
    unsigned int max_health_;
    double speed_;
    unsigned int attack_cooldown_;
    size_t coins_for_death_;

    size_t health, counter, steps, value, freezeCounter;
    unsigned int location;
    float speed;
    bool dead, freezed;

public:
    Enemy() {};

    Enemy(unsigned int current_time, unsigned int max_health, double speed,
          unsigned int attack_cooldown, size_t coins_for_death,
          Coordinate position);

    virtual void attack(std::shared_ptr<Attackable> &target, unsigned int current_time) = 0;

    virtual std::shared_ptr<Attackable> findTarget(
            std::vector<std::shared_ptr<Attackable>> &possible_targets) = 0;

    bool isReadyForAttack(unsigned int current_time) const;

    virtual bool canAttack(const std::shared_ptr<Attackable> &target) = 0;

    size_t getCoinsForDeath() const { return coins_for_death_; }

    size_t getValue() { return std::max<size_t>(value / 2 + 1, 2); }

    size_t getHealth() { return health; }

    bool isDead() { return dead; }

    bool isFreezed() { return freezed; }

    float getSpeed() const;

    void freeze();
};

#endif  // LAST_SAVIORS_ENEMY_H
