#ifndef LAST_SAVIORS_MINDMASTER_H
#define LAST_SAVIORS_MINDMASTER_H

#include "enemy.h"
#include "algorithm"
#include "tower.h"

class Mindmaster : public Enemy {
   public:
    Mindmaster(unsigned int current_time, unsigned int max_health, double speed,
          unsigned int attack_cooldown, size_t coins_for_death,
          Coordinate position);

    bool canAttack(const Attackable &target) override;
    void attack(Attackable &target, unsigned int current_time) override;
    Attackable *findTarget(std::vector<Attackable> &possible_targets) override;
};

#endif  // LAST_SAVIORS_MINDMASTER_H
