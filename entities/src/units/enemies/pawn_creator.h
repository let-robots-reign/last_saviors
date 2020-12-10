#include "enemy_creator.h"
#include "pawn.h"

class PawnCreator : public EnemyCreator {
   private:
    PawnModel model_;
    static bool validityConfigurationCheck(unsigned int maxHealth,
                                           unsigned int damage, double speed,
                                           unsigned int attackCooldown,
                                           size_t coinsForDeath);

   public:
    PawnCreator(unsigned int maxHealth, unsigned int damage, double speed,
                unsigned int attackCooldown,
                size_t coinsForDeath) noexcept(false);

    void changeConfiguration(unsigned int maxHealth, unsigned int damage,
                             double speed, unsigned int attackCooldown,
                             size_t coinsForDeath) noexcept(false);
    std::shared_ptr<Enemy> createEnemy(time_t current_time,
                                       Coordinate position) const override;
};