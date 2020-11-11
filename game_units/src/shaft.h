#ifndef LAST_SAVIORS_SHAFT_H
#define LAST_SAVIORS_SHAFT_H

#include "player.h"
#include "shaft_model.h"
#include "unit.h"

class Shaft : public Unit {
   private:
    time_t timeOfLastUsage;
    int level;
    ShaftModel *model;

   public:
    bool canGetCoins();
    void getCoins(Player *player);
};

#endif  // LAST_SAVIORS_SHAFT_H
