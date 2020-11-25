#ifndef LAST_SAVIORS_SHAFT_H
#define LAST_SAVIORS_SHAFT_H

#include <time.h>

#include "model_factory.h"
#include "player.h"
#include "unit.h"

class Shaft : public Unit {
   private:
    time_t timeOfLastUsage_;
    int level_;
    const ShaftModel *model_;

   public:
    explicit Shaft(const ShaftModel *model, Coordinate position = Coordinate(),
                   int level = 1);
    bool canGetCoins();
    void getCoins(Player *player);
};

#endif  // LAST_SAVIORS_SHAFT_H
