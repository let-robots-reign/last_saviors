#ifndef LAST_SAVIORS_PAWN_H
#define LAST_SAVIORS_PAWN_H

#include <algorithm>
#include <memory>

#include "citadel.h"
#include "enemy.h"

class Pawn : public Enemy {
   private:
    unsigned int damage_;

   public:
    Pawn(unsigned int current_time, unsigned int max_health, double speed,
         unsigned int attack_cooldown, size_t coins_for_death,
         unsigned int damage, Coordinate position = Coordinate());

    Pawn(const Pawn &) = delete;
    void attack(Attackable &target, unsigned int current_time) override;
    Attackable *findTarget(std::vector<Attackable> &possible_targets) override;
    bool canAttack(const Attackable &target) override;
};

#endif  // LAST_SAVIORS_PAWN_H
