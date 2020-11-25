#ifndef LAST_SAVIORS_MINDMASTER_H
#define LAST_SAVIORS_MINDMASTER_H

#include "enemy.h"
#include "model_factory.h"

class Mindmaster : public Enemy {
   private:
    const MindmasterModel *model_;

   public:
    explicit Mindmaster(const MindmasterModel *model,
               Coordinate position = Coordinate());
    void attack(AttackableBuilding *building) override;
    bool canAttack() override;
    void atDeath(Player *player) override;
};

#endif  // LAST_SAVIORS_MINDMASTER_H
