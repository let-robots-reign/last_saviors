#ifndef LAST_SAVIORS_ENEMY_CREATOR_H
#define LAST_SAVIORS_ENEMY_CREATOR_H

#include <memory>

#include "enemy.h"

class EnemyCreator {
   private:
   public:
    virtual ~EnemyCreator() = default;
    virtual std::shared_ptr<Enemy> createEnemy(time_t current_time,
                                               Coordinate position) const = 0;
};

#endif  // LAST_SAVIORS_ENEMY_CREATOR_H
