#ifndef LAST_SAVIORS_PAWN_H
#define LAST_SAVIORS_PAWN_H
#include "enemy.h"
#include "pawn_model.h"

class Pawn : public Ememy {
   public:
    void attack(AttackableBuilding *building) override;
    bool canAttack() override;
    void atDeath(Player *player) override;

   private:
    PawnModel *model;
};

#endif  // LAST_SAVIORS_PAWN_H
