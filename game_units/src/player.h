#ifndef LAST_SAVIORS_PLAYER_H
#define LAST_SAVIORS_PLAYER_H

#include <cstddef>

enum TowerType { AreaDamageTower, PointDamageTower };

class Player {
   private:
    const size_t INITIAL_COINS = 200;
    size_t coins;

   public:
    Player();
    void buildTower(TowerType type);
    void takePuzzle(int complexity);
    void increaseCoins(size_t value);
    void reduceCoins(size_t value);
    void buildShaft();
};

#endif  // LAST_SAVIORS_PLAYER_H
