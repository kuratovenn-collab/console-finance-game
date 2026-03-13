#include <gtest/gtest.h>

#include "../include/Player.h"
#include "../include/Dice.h"

TEST(PlayerTest, AddMoney) {

    Player p("Hero",100);
    p.addMoney(50);
    EXPECT_EQ(p.getMoney(),150);
}

TEST(PlayerTest, SpendMoney) {

    Player p("Hero",100);
    p.spendMoney(30);
    EXPECT_EQ(p.getMoney(),70);
}

TEST(PlayerTest, Move) {

    Player p("Hero");
    p.move(5);
    EXPECT_EQ(p.getPosition(),5);
}

TEST(DiceTest, Range) {

    for(int i=0;i<100;i++){

        int r = Dice::roll();
        EXPECT_GE(r,1);
        EXPECT_LE(r,6);
    }
}