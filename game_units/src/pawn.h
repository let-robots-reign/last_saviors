#ifndef LAST_SAVIORS_PAWN_H
#define LAST_SAVIORS_PAWN_H
#include "enemy.h"
#include "model_factory.h"

class Pawn : public Enemy {
   private:
    const PawnModel *model_;

   public:
    explicit Pawn(const PawnModel *model, Coordinate position = Coordinate());
    void attack(AttackableBuilding *building) override;
    bool canAttack() override;
    void atDeath(Player *player) override;
};

#endif  // LAST_SAVIORS_PAWN_H
