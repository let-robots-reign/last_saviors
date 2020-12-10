#include "enemy_creator.h"
#include "mindmaster.h"

class MindmasterCreator : public EnemyCreator {
   private:
    MindmasterModel model_;
    static bool validityConfigurationCheck(unsigned int maxHealth, double speed,
                                           unsigned int attackCooldown,
                                           size_t coinsForDeath);

   public:
    MindmasterCreator(unsigned int maxHealth, double speed,
                      unsigned int attackCooldown,
                      size_t coinsForDeath) noexcept(false);

    void changeConfiguration(unsigned int maxHealth, double speed,
                             unsigned int attackCooldown,
                             size_t coinsForDeath) noexcept(false);
    std::shared_ptr<Enemy> createEnemy(time_t current_time,
                                       Coordinate position) const override;
};