#ifndef LAST_SAVIORS_ATTACKABLE_H
#define LAST_SAVIORS_ATTACKABLE_H

#include "unit.h"
#include <stdexcept>

class Attackable : public Unit {
   private:
    unsigned int health_;

   public:
    explicit Attackable(unsigned int health, Coordinate position) noexcept(false);
    virtual ~Attackable() = default;
    void reduceHealth(unsigned int value);
    unsigned int getHealth() const { return health_; };
    void setHealth(unsigned int value) noexcept(false);
    virtual void atDeath(){}
};


#endif  // LAST_SAVIORS_ATTACKABLE_H
