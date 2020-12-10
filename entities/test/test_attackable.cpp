#include "gmock/gmock.h"
#include "attackable.h"

class MockAttackable: public Attackable{
   public:
    MockAttackable(int health, Coordinate position):Attackable(health, position){};
    MOCK_METHOD0(atDeath, void());
};

const int kDefaultHealth = 100;
const int kFatalDamage = 120;
const int kNonLethalDamage = 80;
TEST(TestAttackable, reduceHealthAndKeepAlive ){
    MockAttackable attackable = MockAttackable(kDefaultHealth, Coordinate());
    EXPECT_CALL(attackable, atDeath()).Times(0);
    attackable.reduceHealth(kNonLethalDamage);
}

TEST(TestAttackable, reduceHealthAndFinish ){
    MockAttackable attackable = MockAttackable(kDefaultHealth, Coordinate());
    EXPECT_CALL(attackable, atDeath()).Times(1);
    attackable.reduceHealth(kFatalDamage);
}