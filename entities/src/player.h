#ifndef LAST_SAVIORS_PLAYER_H
#define LAST_SAVIORS_PLAYER_H

#include <cstddef>

class Player {
   private:
    size_t initial_coins_;
    size_t coins_;

   public:
    Player(size_t initial_coins);
    void increaseCoins(size_t value);
    void reduceCoins(size_t value);
    size_t getCoins() const {return coins_; }
};

#endif  // LAST_SAVIORS_PLAYER_H
