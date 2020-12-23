#include "gmock/gmock.h"
#include "attackable.h"


const int kDefaultHealth = 100;
const int kFatalDamage = 120;
const int kNonLethalDamage = 80;
TEST(TestAttackable, reduceHealthAndKeepAlive ){
    Attackable attackable = Attackable(kDefaultHealth, Coordinate());
    attackable.reduceHealth(kNonLethalDamage);
    EXPECT_TRUE(attackable.isAlive());
}

TEST(TestAttackable, reduceHealthAndFinish ){
    Attackable attackable = Attackable(kDefaultHealth, Coordinate());
    attackable.reduceHealth(kFatalDamage);
    EXPECT_FALSE(attackable.isAlive());
}