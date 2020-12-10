#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "pawn.h"

using ::testing::Return;

const PawnModel kTestModel{100, 20, 1, 5, 10};
const unsigned int kStartTime = 0;
const unsigned int kTimeOfFirstAttack = kStartTime + kTestModel.attackCooldown;
const unsigned int kTimeAfterFirstAttack = kTimeOfFirstAttack + 1;
TEST(Pawn, isReadyForAttack) {
    const unsigned int kTimeBeforeFirstAttack = kTimeOfFirstAttack - 1;
    Pawn pawn(kTestModel, kStartTime);
    EXPECT_FALSE(pawn.isReadyForAttack(kTimeBeforeFirstAttack));
    EXPECT_TRUE(pawn.isReadyForAttack(kTimeOfFirstAttack));
}

TEST(Pawn, canAttack) {
    Pawn pawn(kTestModel, kStartTime);
    Citadel citadel({1});
    EXPECT_TRUE(pawn.canAttack(citadel));
    Attackable anyOtherAttackable(100, Coordinate());
    EXPECT_FALSE(pawn.canAttack(anyOtherAttackable));
}
class MockPawn : public Pawn {
   public:
    MockPawn(const PawnModel& model) : Pawn(model, kStartTime) {}
    MOCK_METHOD(bool, canAttack, (const Attackable& target));
    MOCK_METHOD(bool, isReadyForAttack, (time_t current_time));
};

TEST(Pawn, attack) {
    MockPawn pawn(kTestModel);
    const unsigned int kSomeTime = 70;
    Attackable attackable(100, Coordinate());
    EXPECT_CALL(pawn, canAttack)
        .Times(2)
        .WillOnce(Return(false))
        .WillRepeatedly(Return(true));
    EXPECT_CALL(pawn, isReadyForAttack)
        .Times(3)
        .WillOnce(Return(true))
        .WillOnce(Return(false))
        .WillRepeatedly(Return(true));
    pawn.attack(attackable, kSomeTime);
    EXPECT_EQ(attackable.getHealth(), 100);
    pawn.attack(attackable, kSomeTime);
    EXPECT_EQ(attackable.getHealth(), 100);
    pawn.attack(attackable, kSomeTime);
    EXPECT_EQ(attackable.getHealth(), 100 - kTestModel.damage);
}