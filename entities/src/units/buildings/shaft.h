#ifndef LAST_SAVIORS_SHAFT_H
#define LAST_SAVIORS_SHAFT_H

#include <ctime>

#include "shaft_model.h"
#include "player.h"
#include "unit.h"

class Shaft : public Unit {
   private:
    unsigned int time_of_last_usage_;
    int level_;
    const ShaftModel model_;

   public:
    explicit Shaft(ShaftModel  model, unsigned int current_time,
                   Coordinate position = Coordinate(), int level = 0);
    bool canGetCoins(unsigned int current_time) const;
    void getCoins(Player &player, unsigned int current_time);
    void upgrade(Player &player, unsigned int current_time);

};

#endif  // LAST_SAVIORS_SHAFT_H
