#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "mindmaster.h"

using ::testing::Return;

const unsigned int kAttackCooldown = 10;
const unsigned int kStartTime = 0;
const unsigned int kMaxHealth = 100;
const double kSpeed = 2;
const size_t kCoinsForDeath = 2;
const unsigned int kDamage = 5;


class SomeTower : public Tower {
   public:
    SomeTower()
        : Tower(1, std::vector<unsigned int>{kMaxHealth}, std::vector<unsigned int>(),
                std::vector<unsigned int>(), std::vector<size_t>(),
                std::vector<size_t>(), std::vector<double>(), kStartTime,
                Coordinate(), 0){};
    explicit SomeTower(Coordinate position)
        : Tower(1, std::vector<unsigned int>{kMaxHealth},
                std::vector<unsigned int>(), std::vector<unsigned int>(),
                std::vector<size_t>(), std::vector<size_t>(),
                std::vector<double>(), kStartTime, position, 0){};
    void attack(std::vector<std::shared_ptr<Attackable>> &enemies) override{};
    std::vector<std::shared_ptr<Attackable>> findTargets(
        const std::vector<std::shared_ptr<Attackable>> &enemies,
        Coordinate citadel_position) override {
        return std::vector<std::shared_ptr<Attackable>>();
    };
};

TEST(Mindmaster, canAttack) {
    Mindmaster mindmaster(kStartTime, kMaxHealth, kSpeed, kAttackCooldown,
                          kCoinsForDeath);
    auto tower = std::make_shared<SomeTower>();
    EXPECT_TRUE(mindmaster.canAttack(tower));
    auto any_other_attackable = std::make_shared<Attackable>(100, Coordinate());
    EXPECT_FALSE(mindmaster.canAttack(any_other_attackable));
}

class MockMindmasterWithCanAttack : public Mindmaster {
   public:
    MockMindmasterWithCanAttack()
        : Mindmaster(kStartTime, kMaxHealth, kSpeed, kAttackCooldown,
                     kCoinsForDeath) {}
    MOCK_METHOD(bool, canAttack, (const std::shared_ptr<Attackable> &target),
                (override));
};

TEST(Mindmaster, attack) {
    MockMindmasterWithCanAttack mindmaster;
    const unsigned int kTimeOfFirstAttack = kStartTime + kAttackCooldown;
    const unsigned int kTimeBeforeFirstAttack = kTimeOfFirstAttack - 1;
    const unsigned int kHealth = 100;
    auto attackable = std::make_shared<Attackable>(kHealth, Coordinate());
    EXPECT_CALL(mindmaster, canAttack)
        .Times(2)
        .WillOnce(Return(false))
        .WillOnce(Return(true));
    mindmaster.attack(attackable, kTimeBeforeFirstAttack);
    EXPECT_EQ(attackable->getHealth(), kHealth);
    mindmaster.attack(attackable, kTimeOfFirstAttack);
    EXPECT_EQ(attackable->getHealth(), kHealth);
    mindmaster.attack(attackable, kTimeOfFirstAttack);
    EXPECT_EQ(attackable->getHealth(), kHealth / 2);
}

TEST(Mindmaster, findTarget) {
    Mindmaster pawn(kStartTime, kMaxHealth, kSpeed, kAttackCooldown,
                    kCoinsForDeath);
    auto attackable = std::make_shared<Attackable>(100, Coordinate());
    auto nearest_tower = std::make_shared<SomeTower>(Coordinate(0, 10));
    auto tower = std::make_shared<SomeTower>(Coordinate(0, 15));
    std::vector<std::shared_ptr<Attackable>> targets{attackable, nearest_tower,
                                                     tower};
    auto final_target = pawn.findTarget(targets);
    EXPECT_EQ(final_target, nearest_tower);
}
