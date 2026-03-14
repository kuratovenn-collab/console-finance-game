#include <gtest/gtest.h>
#include "../include/Player.h"
#include "../include/Dice.h"
#include "../include/Board.h"
#include "../include/TrapEvent.h"
#include "../include/CorpseEvent.h"
#include "../include/GamblingEvent.h"
#include "../include/BossEvent.h"
#include "../include/PillEvent.h"
#include "../include/InsiderTradingEvent.h"
#include "../include/Exceptions.h"
#include <memory>
#include <sstream>


TEST(PlayerTest, AddMoney) {
    Player p("Hero", 100);
    p.addMoney(50);
    EXPECT_EQ(p.getMoney(), 150);
}

TEST(PlayerTest, SpendMoney) {
    Player p("Hero", 100);
    p.spendMoney(30);
    EXPECT_EQ(p.getMoney(), 70);
}

TEST(PlayerTest, SpendMoneyInsufficientFunds) {
    Player p("Hero", 10);
    EXPECT_THROW(p.spendMoney(100), InsufficientFundsException);
}

TEST(PlayerTest, Move) {
    Player p("Hero");
    p.move(5);
    EXPECT_EQ(p.getPosition(), 5);
}

TEST(PlayerTest, MoveMultipleTimes) {
    Player p("Hero");
    p.move(3);
    p.move(4);
    EXPECT_EQ(p.getPosition(), 7);
}

TEST(PlayerTest, LoseLives) {
    Player p("Hero", 100, 3);
    EXPECT_THROW(p.loseLives(3), GameOverException);
}

TEST(PlayerTest, LoseLivesPartial) {
    Player p("Hero", 100, 3);
    p.loseLives(1);
    EXPECT_EQ(p.getLives(), 2);
}

TEST(PlayerTest, GainLife) {
    Player p("Hero", 100, 2);
    p.loseLives(-1);
    EXPECT_EQ(p.getLives(), 3);
}

TEST(PlayerTest, InitialState) {
    Player p("TestHero", 200, 5);
    EXPECT_EQ(p.getMoney(), 200);
    EXPECT_EQ(p.getLives(), 5);
    EXPECT_EQ(p.getPosition(), 0);
}


TEST(DiceTest, Range) {
    for (int i = 0; i < 200; i++) {
        int r = Dice::roll();
        EXPECT_GE(r, 1);
        EXPECT_LE(r, 6);
    }
}


TEST(BoardTest, AddAndSize) {
    Board board;
    board.addEvent(std::make_unique<TrapEvent>("Trap1"));
    board.addEvent(std::make_unique<TrapEvent>("Trap2"));
    EXPECT_EQ(board.size(), 2);
}

TEST(BoardTest, GetEventAt) {
    Board board;
    board.addEvent(std::make_unique<TrapEvent>("MyTrap"));
    EXPECT_EQ(board.getEventAt(0).getTitle(), "MyTrap");
}

TEST(BoardTest, GetEventAtOutOfBounds) {
    Board board;
    board.addEvent(std::make_unique<TrapEvent>("Only"));
    EXPECT_EQ(board.getEventAt(99).getTitle(), "Only");
}

TEST(TrapEventTest, GetTitle) {
    TrapEvent e("Bandit Ambush");
    EXPECT_EQ(e.getTitle(), "Bandit Ambush");
}

TEST(TrapEventTest, PlayReducesLives) {
    std::streambuf* old = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());

    Player p("Hero", 100, 3);
    TrapEvent e("Trap");
    try {
        e.play(p);
    } catch (...) {}
    EXPECT_EQ(p.getLives(), 2);

    std::cout.rdbuf(old);
}

TEST(TrapEventTest, PlayReducesMoney) {
    std::streambuf* old = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());

    Player p("Hero", 100, 3);
    TrapEvent e("Trap");
    try {
        e.play(p);
    } catch (...) {}
    EXPECT_LT(p.getMoney(), 100);

    std::cout.rdbuf(old);
}

TEST(TrapEventTest, PlayGameOverWhenNoLives) {
    std::streambuf* old = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());

    Player p("Hero", 100, 1);
    TrapEvent e("Fatal Trap");
    EXPECT_THROW(e.play(p), GameOverException);

    std::cout.rdbuf(old);
}


TEST(CorpseEventTest, GetTitle) {
    CorpseEvent e("Mysterious Body");
    EXPECT_EQ(e.getTitle(), "Mysterious Body");
}


TEST(GamblingEventTest, GetTitle) {
    GamblingEvent e("Old Oak Tavern", 10);
    EXPECT_EQ(e.getTitle(), "Old Oak Tavern");
}


TEST(BossEventTest, GetTitle) {
    BossEvent e("!!!DANGER!!!");
    EXPECT_EQ(e.getTitle(), "!!!DANGER!!!");
}

TEST(PillEventTest, GetTitle) {
    PillEvent e("Unknown Pill");
    EXPECT_EQ(e.getTitle(), "Unknown Pill");
}

TEST(InsiderTradingEventTest, GetTitle) {
    InsiderTradingEvent e("Shady Deal");
    EXPECT_EQ(e.getTitle(), "Shady Deal");
}


TEST(ExceptionsTest, GameOverExceptionMessage) {
    try {
        throw GameOverException("test message");
    } catch (const GameOverException& e) {
        EXPECT_NE(std::string(e.what()).find("test message"), std::string::npos);
    }
}

TEST(ExceptionsTest, InsufficientFundsExceptionMessage) {
    try {
        throw InsufficientFundsException("no gold");
    } catch (const InsufficientFundsException& e) {
        EXPECT_NE(std::string(e.what()).find("no gold"), std::string::npos);
    }
}

TEST(ExceptionsTest, CursedExceptionMessage) {
    try {
        throw CursedException("cursed!");
    } catch (const CursedException& e) {
        EXPECT_NE(std::string(e.what()).find("cursed!"), std::string::npos);
    }
}