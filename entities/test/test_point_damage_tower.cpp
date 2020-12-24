#include "gtest/gtest.h"
#include "point_damage_tower.h"
#include "some_enemy.h"

const unsigned int kDamage = 10;
const unsigned int kHealth = 100;


TEST(PointDamageTower, attack) {
    PointDamageTower tower(
        0, std::vector<unsigned int>{100}, std::vector<unsigned int>(),
        std::vector<unsigned int>{kDamage}, std::vector<size_t>(),
        std::vector<size_t>(), std::vector<double>(), 10, Coordinate(), 0);
    std::vector<std::shared_ptr<Attackable>> targets;
    EXPECT_NO_THROW(tower.attack(targets));
    auto target1 = std::make_shared<SomeEnemy>(kHealth);
    targets.push_back(target1);
    tower.attack(targets);
    EXPECT_EQ(target1->getHealth(), kHealth - kDamage);
    auto target2 = std::make_shared<SomeEnemy>(kHealth);
    targets.push_back(target2);
    tower.attack(targets);
    EXPECT_EQ(target1->getHealth(), kHealth - 2 * kDamage);
    EXPECT_EQ(target2->getHealth(), kHealth);
}
const Coordinate kCitadelPosition(0, 0);
const double kAttackRadius = 6;
TEST(PointDamageTower, findTargets) {
    PointDamageTower tower(
        0, std::vector<unsigned int>{100}, std::vector<unsigned int>(),
        std::vector<unsigned int>{kDamage}, std::vector<size_t>(),
        std::vector<size_t>(), std::vector<double>{kAttackRadius}, 10, Coordinate(), 0);
    auto some_enemy = std::make_shared<SomeEnemy>(Coordinate(0, kAttackRadius - 1));
    auto closest_to_citadel_enemy =
        std::make_shared<SomeEnemy>(Coordinate(0, kAttackRadius - 2));
    auto some_attackable =
        std::make_shared<Attackable>(kHealth, Coordinate(0, kAttackRadius - 3));
    std::vector<std::shared_ptr<Attackable>> targets;
    std::vector<std::shared_ptr<Attackable>> result;
    result = tower.findTargets(targets, kCitadelPosition);
    EXPECT_TRUE(result.empty());
    targets = {some_enemy, closest_to_citadel_enemy, some_attackable};
    result = tower.findTargets(targets, kCitadelPosition);
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], closest_to_citadel_enemy);
}