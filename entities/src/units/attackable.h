#ifndef LAST_SAVIORS_ATTACKABLE_H
#define LAST_SAVIORS_ATTACKABLE_H

#include "unit.h"
#include <stdexcept>

class Attackable : public Unit {
   private:
    unsigned int health_;
    bool is_alive;

   public:
    explicit Attackable(unsigned int health, Coordinate position) noexcept(false);
    virtual ~Attackable() = default;
    void reduceHealth(unsigned int value);
    unsigned int getHealth() const { return health_; };
    void setHealth(unsigned int value) noexcept(false);
    bool isAlive() { return is_alive;}
};


#endif  // LAST_SAVIORS_ATTACKABLE_H
