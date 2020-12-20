#ifndef LAST_SAVIORS_ENEMY_H
#define LAST_SAVIORS_ENEMY_H

#include <ctime>
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

   public:
    Enemy(unsigned int current_time, unsigned int max_health, double speed,
          unsigned int attack_cooldown, size_t coins_for_death,
          Coordinate position);

    virtual void attack(Attackable& target, unsigned int current_time) = 0;
    virtual Attackable* findTarget(
        std::vector<Attackable>& possible_targets) = 0;
    bool isReadyForAttack(unsigned int current_time) const;
    virtual bool canAttack(const Attackable& target) = 0;
    size_t getCoinsForDeath() { return coins_for_death_; }
};

#endif  // LAST_SAVIORS_ENEMY_H
