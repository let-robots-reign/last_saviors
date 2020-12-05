#ifndef LAST_SAVIORS_PLAYER_H
#define LAST_SAVIORS_PLAYER_H

#include <cstddef>

enum TowerType { kAreaDamageTower, kPointDamageTower };

class Player {
   private:
    const size_t INITIAL_COINS = 200; // todo model
    size_t coins_;

   public:
    Player();
    void buildTower(TowerType type);//todo это вообще не надо
    void takePuzzle(int complexity);
    void increaseCoins(size_t value);
    void reduceCoins(size_t value);
    size_t getCoins() {return coins_; }
    void buildShaft();
};

#endif  // LAST_SAVIORS_PLAYER_H
