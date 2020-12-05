#ifndef LAST_SAVIORS_ATTACKABLE_H
#define LAST_SAVIORS_ATTACKABLE_H

#include "unit.h"

class Attackable : public Unit {
   private:
    int health_;

   public:
    explicit Attackable(int health, Coordinate position);
    ~Attackable() = default;
    void reduceHealth(int value);
    int getHealth() const { return health_; };
    void setHealth(int value);
    virtual void onFinish(){}
};


#endif  // LAST_SAVIORS_ATTACKABLE_H
