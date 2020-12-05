#ifndef LAST_SAVIORS_MINDMASTER_H
#define LAST_SAVIORS_MINDMASTER_H

#include "enemy.h"
#include "mindmaster_model.h"

class Mindmaster : public Enemy {
   private:
    const MindmasterModel *model_;

   public:
    explicit Mindmaster(const MindmasterModel *model, time_t current_time,
                        Coordinate position = Coordinate());
    void attack(Attackable &target, time_t current_time) override;
    Attackable *findTarget(std::list<Attackable> &possible_targets) override;
    bool isReadyForAttack(time_t current_time) override;
};

#endif  // LAST_SAVIORS_MINDMASTER_H
