#ifndef LAST_SAVIORS_MINDMASTER_H
#define LAST_SAVIORS_MINDMASTER_H

#include "enemy.h"
#include "mindmaster_model.h"

class Mindmaster : public Ememy {
   public:
    void attack(AttackableBuilding *building) override;
    bool canAttack() override;
    void atDeath(Player *player) override;

   private:
    MindmasterModel *model;
};

#endif  // LAST_SAVIORS_MINDMASTER_H
