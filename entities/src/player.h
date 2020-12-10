#ifndef LAST_SAVIORS_PLAYER_H
#define LAST_SAVIORS_PLAYER_H

#include "player_model.h"
#include <cstddef>

class Player {
   private:
    PlayerModel model_;
    size_t coins_;

   public:
    Player(const PlayerModel& model);
    void increaseCoins(size_t value);
    void reduceCoins(size_t value);
    size_t getCoins() const {return coins_; }
};

#endif  // LAST_SAVIORS_PLAYER_H
