#pragma once
#include "Board.h"
#include "Player.h"
#include <string>

class Game {
private:
    Player player;
    Board board;
    void setupBoard;
    void processTurn;
    void checkEnding;
public:
    Game(const std::string& playerName);
    void run;
};