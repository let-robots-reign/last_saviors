#ifndef LAST_SAVIORS_MINDMASTER_H
#define LAST_SAVIORS_MINDMASTER_H

#include "enemy.h"
#include "model_factory.h"

class Mindmaster : public Enemy {
   public:
    Mindmaster();
    Mindmaster(Coordinates position);
    void attack(AttackableBuilding *building) override;
    bool canAttack() override;
    void atDeath(Player *player) override;

   private:
    MindmasterModel *model;
};

#endif  // LAST_SAVIORS_MINDMASTER_H
