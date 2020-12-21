#include <memory>

#include "point_damage_tower.h"
#include "tower_creator.h"

class PointDamageTowerCreator: public TowerCreator {
   private:
    int level_;
    size_t max_level_;
    std::vector<unsigned int> max_health_per_level_;
    std::vector<unsigned int> attack_cooldown_per_level_;
    std::vector<unsigned int> damage_per_level_;
    std::vector<size_t> repair_cost_per_level_;
    std::vector<size_t> upgrade_cost_per_level_;
    std::vector<double> attack_radius_per_level_;

   public:
    PointDamageTowerCreator(int level,
                            size_t max_level,
                            std::vector<unsigned int> &max_health_per_level,
                            std::vector<unsigned int> &attack_cooldown_per_level,
                            std::vector<unsigned int> &damage_per_level,
                            std::vector<size_t> &repair_cost_per_level,
                            std::vector<size_t> &upgrade_cost_per_level,
                            std::vector<double> &attack_radius_per_level);

    std::shared_ptr<Tower> createTower(unsigned int current_time,
                                       Coordinate position) const override;

    void changeConfiguration(int level,
    size_t max_level,
    std::vector<unsigned int> &max_health_per_level,
    std::vector<unsigned int> &attack_cooldown_per_level,
    std::vector<unsigned int> &damage_per_level,
    std::vector<size_t> &repair_cost_per_level,
    std::vector<size_t> &upgrade_cost_per_level,
    std::vector<double> &attack_radius_per_level);

};