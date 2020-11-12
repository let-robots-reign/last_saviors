#ifndef LAST_SAVIORS_PAWN_H
#define LAST_SAVIORS_PAWN_H
#include "enemy.h"
#include "model_factory.h"

class Pawn : public Enemy {
   public:
    Pawn();
    Pawn(Coordinate position);
    void attack(AttackableBuilding *building) override;
    bool canAttack() override;
    void atDeath(Player *player) override;

   private:
    PawnModel *model;
};

#endif  // LAST_SAVIORS_PAWN_H
