#include <gtest/gtest.h>
#include <stdint.h>

extern "C" int FFX_Battle_ComputeEffectiveHp(int base, int debuff, int shield);

TEST(BattleHp, FullHealthNoMods) {
    EXPECT_EQ(FFX_Battle_ComputeEffectiveHp(1000, 0, 0), 1000);
}

TEST(BattleHp, WithShield) {
    EXPECT_EQ(FFX_Battle_ComputeEffectiveHp(1000, 0, 500), 1500);
}

TEST(BattleHp, WithDebuff) {
    EXPECT_EQ(FFX_Battle_ComputeEffectiveHp(1000, 200, 0), 800);
}

TEST(BattleHp, ClampedAtZero) {
    EXPECT_EQ(FFX_Battle_ComputeEffectiveHp(100, 200, 0), 0);
}

TEST(BattleHp, MixedMods) {
    EXPECT_EQ(FFX_Battle_ComputeEffectiveHp(1000, 300, 200), 900);
}
