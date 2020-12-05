#ifndef LAST_SAVIORS_TOWER_H
#define LAST_SAVIORS_TOWER_H

#include <ctime>
#include <list>

#include "attackable.h"

class Tower : public Attackable {
   protected:
    time_t time_of_last_attack_;
    int level_;

   public:
    Tower(int health, time_t current_time, Coordinate position, int level);
    virtual void attack(std::list<Attackable> &enemies) = 0;
    virtual bool isReadyForAttack(time_t current_time) = 0;
    virtual std::list<Attackable> findTargets(
        std::list<Attackable> &enemies) = 0;
    virtual void upgrade(time_t current_time) {
        ++level_;  // todo ask model about max level
        time_of_last_attack_ = current_time;
    };
};

#endif  // LAST_SAVIORS_TOWER_H
