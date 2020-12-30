#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "pawn.h"

using ::testing::Return;

const unsigned int kAttackCooldown = 10;
const unsigned int kStartTime = 0;
const unsigned int kMaxHealth = 100;
const double kSpeed = 2;
const size_t kCoinsForDeath = 2;
const unsigned int kDamage = 5;


TEST(Pawn, canAttack) {
    Pawn pawn(kStartTime, kMaxHealth, kSpeed, kAttackCooldown, kCoinsForDeath,
              kDamage);
    auto citadel = std::make_shared<Citadel>(1);
    EXPECT_TRUE(pawn.canAttack(citadel));
    auto any_other_attackable = std::make_shared<Attackable>(100, Coordinate());
    EXPECT_FALSE(pawn.canAttack(any_other_attackable));
}

class MockPawnWithCanAttack : public Pawn {
   public:
    MockPawnWithCanAttack()
        : Pawn(kStartTime, kMaxHealth, kSpeed, kAttackCooldown, kCoinsForDeath,
               kDamage) {}
    MOCK_METHOD(bool, canAttack, (const std::shared_ptr<Attackable> &target),
                (override));
};

TEST(Pawn, attack) {
    MockPawnWithCanAttack pawn;
    const unsigned int kTimeOfFirstAttack = kStartTime + kAttackCooldown;
    const unsigned int kTimeBeforeFirstAttack = kTimeOfFirstAttack - 1;
    const unsigned int kHealth = 100;
    auto attackable = std::make_shared<Attackable>(kHealth, Coordinate());
    EXPECT_CALL(pawn, canAttack)
        .Times(2)
        .WillOnce(Return(false))
        .WillOnce(Return(true));
    pawn.attack(attackable, kTimeBeforeFirstAttack);
    EXPECT_EQ(attackable->getHealth(), kHealth);
    pawn.attack(attackable, kTimeOfFirstAttack);
    EXPECT_EQ(attackable->getHealth(), kHealth);
    pawn.attack(attackable, kTimeOfFirstAttack);
    EXPECT_EQ(attackable->getHealth(), kHealth - kDamage);
}

TEST(Pawn, findTarget) {
    Pawn pawn(kStartTime, kMaxHealth, kSpeed, kAttackCooldown, kCoinsForDeath,
              kDamage);
    auto first_attackable = std::make_shared<Attackable>(100, Coordinate());
    auto second_attackable =
        std::make_shared<Attackable>(100, Coordinate(1, 2));
    auto citadel = std::make_shared<Citadel>(100, Coordinate(0, 5));
    std::vector<std::shared_ptr<Attackable>> targets{first_attackable, citadel,
                                                     second_attackable};
    auto final_target = pawn.findTarget(targets);
    EXPECT_EQ(final_target, citadel);
}
