#ifndef LAST_SAVIORS_ENEMY_H
#define LAST_SAVIORS_ENEMY_H

#include <ctime>

#include "attackable.h"
#include "list"
#include "player.h"
#include "unit.h"

class Enemy : public Attackable {
   protected:
    time_t time_of_last_attack_;

   public:
    Enemy(unsigned int health, time_t current_time, Coordinate position = Coordinate());

    virtual void attack(Attackable& target, time_t current_time) = 0;
    virtual Attackable* findTarget(std::list<Attackable>& possible_targets) = 0;
    virtual bool isReadyForAttack(time_t current_time) = 0;
    virtual bool canAttack(const Attackable& target) = 0;
};

#endif  // LAST_SAVIORS_ENEMY_H
