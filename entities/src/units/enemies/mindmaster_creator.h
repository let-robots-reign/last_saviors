#include "enemy_creator.h"
#include "mindmaster.h"

class MindmasterCreator : public EnemyCreator {
   private:
    unsigned int max_health_;
    double speed_;
    unsigned int attack_cooldown_;
    size_t coins_for_death_;

    static bool validityConfigurationCheck(unsigned int max_health,
                                           double speed,
                                           unsigned int attack_cooldown,
                                           size_t coins_for_death);

   public:
    MindmasterCreator(unsigned int max_health, double speed,
                      unsigned int attack_cooldown,
                      size_t coins_for_death) noexcept(false);

    void changeConfiguration(unsigned int max_health, double speed,
                             unsigned int attack_cooldown,
                             size_t coins_for_death) noexcept(false);
    std::shared_ptr<Enemy> createEnemy(unsigned int current_time,
                                       Coordinate position) const override;
};