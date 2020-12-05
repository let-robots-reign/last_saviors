#ifndef LAST_SAVIORS_SHAFT_H
#define LAST_SAVIORS_SHAFT_H

#include <ctime>

#include "shaft_model.h"
#include "player.h"
#include "unit.h"

class Shaft : public Unit {
   private:
    time_t time_of_last_usage_;
    int level_;
    const ShaftModel *model_;

   public:
    explicit Shaft(const ShaftModel *model, time_t current_time,
                   Coordinate position = Coordinate(), int level = 1);
    bool canGetCoins(time_t current_time);
    void getCoins(Player *player, time_t current_time);

};

#endif  // LAST_SAVIORS_SHAFT_H
