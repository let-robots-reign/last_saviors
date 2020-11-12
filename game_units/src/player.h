#ifndef LAST_SAVIORS_PLAYER_H
#define LAST_SAVIORS_PLAYER_H

enum TowerType { AreaDamageTower, PointDamageTower };

class Player {
   private:
    const int INITIAL_COINS = 200;
    int coins;

   public:
    Player();
    void buildTower(TowerType type);
    void takePuzzle(int complexity);
    void increaseCoins(int value);
    void reduceCoins(int value);
    void buildShaft();
};

#endif  // LAST_SAVIORS_PLAYER_H
