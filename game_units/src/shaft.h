#ifndef LAST_SAVIORS_SHAFT_H
#define LAST_SAVIORS_SHAFT_H

#include "model_factory.h"
#include "player.h"
#include "unit.h"

class Shaft : public Unit {
   private:
    time_t timeOfLastUsage;
    int level;
    ShaftModel *model;

   public:
    Shaft();
    Shaft(Coordinate position, int level = 1);
    bool canGetCoins();
    void getCoins(Player *player);
};

#endif  // LAST_SAVIORS_SHAFT_H
