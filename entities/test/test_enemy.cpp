#include "enemy.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"


const unsigned int kAttackCooldown = 10;
class MockEnemy : public Enemy {
   public:
    MockEnemy(unsigned int current_time, unsigned int attack_cooldown)
        : Enemy(current_time, 100, 1, attack_cooldown, 100, Coordinate()) {}

    MOCK_METHOD(void, attack,
                (std::shared_ptr<Attackable> & target,
                 unsigned int current_time),
                (override));
    MOCK_METHOD(bool, canAttack, (const std::shared_ptr<Attackable> &target),
                (override));
    MOCK_METHOD(std::shared_ptr<Attackable>, findTarget,
                (std::vector<std::shared_ptr<Attackable>> & possible_targets),
                (override));
};


TEST(Enemy, isReadyForAttack) {
    const unsigned int kCurrentTime = 0;
    const unsigned int kTimeOfFirstAttack = kCurrentTime + kAttackCooldown;
    const unsigned int kTimeBeforeFirstAttack = kTimeOfFirstAttack - 1;
    const unsigned int kTimeAfterFirstAttack = kTimeOfFirstAttack + 1;
    MockEnemy enemy(kCurrentTime, kAttackCooldown);
    EXPECT_FALSE(enemy.isReadyForAttack(kTimeBeforeFirstAttack));
    EXPECT_TRUE(enemy.isReadyForAttack(kTimeOfFirstAttack));
    EXPECT_TRUE(enemy.isReadyForAttack(kTimeAfterFirstAttack));
}
