#ifndef LAST_SAVIORS_TOWER_H
#define LAST_SAVIORS_TOWER_H

#include <ctime>
#include <list>
#include <vector>

#include "attackable.h"
#include "player.h"
#include "enemy.h"

class Tower : public Attackable {
   protected:
    unsigned int time_of_last_attack_;
    size_t level_;
    size_t max_level_;
    std::vector<unsigned int> max_health_per_level_;
    std::vector<unsigned int> attack_cooldown_per_level_;
    std::vector<unsigned int> damage_per_level_;
    std::vector<size_t> repair_cost_per_level_;
    std::vector<size_t> upgrade_cost_per_level_;
    std::vector<double> attack_radius_per_level_;


   public:
    Tower(size_t max_level, std::vector<unsigned int> &max_health_per_level,
          std::vector<unsigned int> &attack_cooldown_per_level,
          std::vector<unsigned int> &damage_per_level,
          std::vector<size_t> &repair_cost_per_level,
          std::vector<size_t> &upgrade_cost_per_level,
          std::vector<double> &attack_radius_per_level,
          unsigned int current_time, Coordinate position, size_t level);
    virtual void attack(std::vector<Attackable> &enemies) = 0;
    virtual bool isReadyForAttack(unsigned int current_time);
    virtual std::vector<Attackable> findTargets(
        const std::vector<Attackable> &enemies, Coordinate citadel_position) = 0;
    virtual bool canAttack(const Attackable& enemy);
    void upgrade(Player &player, unsigned int current_time);
    void repair(Player &player, unsigned int current_time);
};

#endif  // LAST_SAVIORS_TOWER_H
