#ifndef LAST_SAVIORS_SHAFT_H
#define LAST_SAVIORS_SHAFT_H


#include <vector>

#include "player.h"
#include "unit.h"

class Shaft : public Unit {
   private:
    unsigned int time_of_last_usage_;
    int level_;
    int max_level_;
    std::vector<unsigned int> cooldown_per_level_;
    std::vector<size_t> amount_of_coins_per_level_;
    std::vector<size_t> upgrade_cost_per_level_;

   public:
    explicit Shaft(int max_level, std::vector<unsigned int> &cooldown_per_level,
                   std::vector<size_t> &amount_of_coins_per_level,
                   std::vector<size_t> &upgrade_cost_per_level,
                   unsigned int current_time,
                   Coordinate position = Coordinate(), int level = 0);
    bool canGetCoins(unsigned int current_time) const;
    void getCoins(Player &player, unsigned int current_time);
    void upgrade(Player &player, unsigned int current_time);
};

#endif  // LAST_SAVIORS_SHAFT_H
