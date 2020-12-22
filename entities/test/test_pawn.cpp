#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "pawn.h"

using ::testing::Return;

const unsigned int kAttackCooldown = 10;
const unsigned int kStartTime = 0;
const unsigned int kTimeOfFirstAttack = kStartTime + kAttackCooldown;
const unsigned int kTimeAfterFirstAttack = kTimeOfFirstAttack + 1;
const unsigned int kMaxHealth = 100;
const double kSpeed = 2;
const size_t kCoinsForDeath = 2;
const unsigned int kDamage = 5;

//todo enemy
/*
TEST(Pawn, isReadyForAttack) {
    const unsigned int kTimeBeforeFirstAttack = kTimeOfFirstAttack - 1;
    Pawn pawn(kStartTime, kMaxHealth, kSpeed, kAttackCooldown, kCoinsForDeath,
              kDamage);
    EXPECT_FALSE(pawn.isReadyForAttack(kTimeBeforeFirstAttack));
    EXPECT_TRUE(pawn.isReadyForAttack(kTimeOfFirstAttack));
}*/

TEST(Pawn, canAttack) {
    Pawn pawn(kStartTime, kMaxHealth, kSpeed, kAttackCooldown, kCoinsForDeath,
              kDamage);
    Citadel citadel(1);
    EXPECT_TRUE(pawn.canAttack(citadel));
    Attackable anyOtherAttackable(100, Coordinate());
    EXPECT_FALSE(pawn.canAttack(anyOtherAttackable));
}
class MockPawn : public Pawn {
   public:
    MockPawn()
        : Pawn(kStartTime, kMaxHealth, kSpeed, kAttackCooldown, kCoinsForDeath,
               kDamage) {}
    MOCK_METHOD(bool, canAttack, (const Attackable &target), (override));
};

TEST(Pawn, attack) {
    MockPawn pawn;
    const unsigned int kTimeBeforeFirstAttack = kTimeOfFirstAttack - 1;
    const unsigned int kHealth = 100;
    Attackable attackable(kHealth, Coordinate());
    EXPECT_CALL(pawn, canAttack)
        .Times(2)
        .WillOnce(Return(false))
        .WillRepeatedly(Return(true));
    pawn.attack(attackable, kTimeBeforeFirstAttack);
    EXPECT_EQ(attackable.getHealth(), kHealth);
    pawn.attack(attackable, kTimeOfFirstAttack);
    EXPECT_EQ(attackable.getHealth(), kHealth);
    pawn.attack(attackable, kTimeOfFirstAttack);
    EXPECT_EQ(attackable.getHealth(), kHealth - kDamage);
}

TEST(Pawn, findTarget){

}