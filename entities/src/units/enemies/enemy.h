#ifndef LAST_SAVIORS_ENEMY_H
#define LAST_SAVIORS_ENEMY_H

#include <ctime>

#include "attackable_building.h"
#include "player.h"
#include "unit.h"

class Enemy : public Unit {
private:
    int health_;

protected:
    time_t timeOfLastAttack_;

public:
    explicit Enemy(int health, Coordinate position = Coordinate());

    virtual void attack(AttackableBuilding *building) = 0;

    virtual bool canAttack() = 0;

    void reduceHealth(AttackableBuilding *building);

    virtual void atDeath(Player *player) = 0;

    inline int getHealth() const { return health_; };
};

#endif  // LAST_SAVIORS_ENEMY_H
