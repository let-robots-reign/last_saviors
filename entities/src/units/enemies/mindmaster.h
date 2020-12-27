#ifndef LAST_SAVIORS_MINDMASTER_H
#define LAST_SAVIORS_MINDMASTER_H

#include "enemy.h"
#include "algorithm"
#include "tower.h"

class Mindmaster : public Enemy {
   public:
    Mindmaster(unsigned int current_time, unsigned int max_health, double speed,
          unsigned int attack_cooldown, size_t coins_for_death,
          Coordinate position = Coordinate());

    bool canAttack(const std::shared_ptr<Attackable> &target) override;
    void attack(std::shared_ptr<Attackable> &target, unsigned int current_time) override;
    std::shared_ptr<Attackable> findTarget(
        std::vector<std::shared_ptr<Attackable>> &possible_targets) override;
};

#endif  // LAST_SAVIORS_MINDMASTER_H
