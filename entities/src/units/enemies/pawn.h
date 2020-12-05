#ifndef LAST_SAVIORS_PAWN_H
#define LAST_SAVIORS_PAWN_H

#include <memory>

#include "algorithm"
#include "citadel.h"
#include "enemy.h"
#include "pawn_model.h"

class Pawn : public Enemy {
   private:
    const std::shared_ptr<PawnModel> model_;

   public:
    Pawn(const std::shared_ptr<PawnModel> &model, time_t current_time,
         Coordinate position = Coordinate());
    void attack(Attackable &target, time_t current_time) override;
    Attackable *findTarget(std::list<Attackable> &possible_targets) override;
    bool isReadyForAttack(time_t current_time) override;
    bool canAttack(const Attackable &target) override;
};

#endif  // LAST_SAVIORS_PAWN_H
