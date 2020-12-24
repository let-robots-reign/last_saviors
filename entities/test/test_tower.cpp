#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "tower.h"
#include "some_enemy.h"

const unsigned int kStartTime = 0;
const size_t kLevel = 0;
const size_t kMaxLevel = 1;
const std::vector<unsigned int> kMaxHealthPerLevel{100, 100};
const std::vector<unsigned int> kAttackCooldownPerLevel{10, 10};
const std::vector<unsigned int> kDamagePerLevel{2, 2};
const std::vector<size_t> kRepairCostPerLevel{20, 20};
const std::vector<size_t> kUpgradeCostPerLevel{30, 30};
const std::vector<double> kAttackRadiusPerLevel{0.1, 0.1};

class MockTower: public Tower {
   public:
    MockTower():Tower(kMaxLevel, kMaxHealthPerLevel, kAttackCooldownPerLevel,
                        kDamagePerLevel, kRepairCostPerLevel, kUpgradeCostPerLevel,
                        kAttackRadiusPerLevel, kStartTime, Coordinate(), kLevel){};

    size_t getLevel(){return level_;};
    MOCK_METHOD(void, attack,(std::vector<std::shared_ptr<Attackable>> &enemies), (override));
    MOCK_METHOD(std::vector<std::shared_ptr<Attackable>>, findTargets,(const std::vector<std::shared_ptr<Attackable>> &enemies, Coordinate citadel_position), (override));
};


TEST(Tower, upgrade){
    MockTower tower;
    Player player(kUpgradeCostPerLevel[kLevel] - 1);
    tower.upgrade(player, kStartTime);
    EXPECT_EQ(tower.getLevel(), kLevel);
    player.increaseCoins(kUpgradeCostPerLevel[kLevel]);
    tower.upgrade(player, kStartTime);
    EXPECT_EQ(tower.getLevel(), kLevel + 1);
    player.increaseCoins(kUpgradeCostPerLevel[kLevel + 1]);
    tower.upgrade(player, kStartTime);
    EXPECT_EQ(tower.getLevel(), kLevel + 1);
}

TEST(Tower, repair){
    const unsigned int damage = 5;
    MockTower tower;
    tower.reduceHealth(damage);
    Player player(kRepairCostPerLevel[kLevel] - 1);
    tower.repair(player, kStartTime);
    EXPECT_EQ(tower.getHealth(), kMaxHealthPerLevel[kLevel] - damage);
    player.increaseCoins(kRepairCostPerLevel[kLevel]);
    tower.repair(player, kStartTime);
    EXPECT_EQ(tower.getHealth(), kMaxHealthPerLevel[kLevel]);
}


TEST(Tower, canAttack){
    MockTower tower;
    auto enemy = std::make_shared<SomeEnemy>();
    EXPECT_TRUE(tower.canAttack(enemy));
    auto any_other_attackable = std::make_shared<Attackable>(100, Coordinate());
    EXPECT_FALSE(tower.canAttack(any_other_attackable));
}

TEST(Tower, isReadyForAttack){
    MockTower tower;
    const unsigned int kCurrentTime = 0;
    const unsigned int kTimeOfFirstAttack = kCurrentTime + kAttackCooldownPerLevel[kLevel];
    const unsigned int kTimeBeforeFirstAttack = kTimeOfFirstAttack - 1;
    const unsigned int kTimeAfterFirstAttack = kTimeOfFirstAttack + 1;
    EXPECT_FALSE(tower.isReadyForAttack(kTimeBeforeFirstAttack));
    EXPECT_TRUE(tower.isReadyForAttack(kTimeOfFirstAttack));
    EXPECT_TRUE(tower.isReadyForAttack(kTimeAfterFirstAttack));
}