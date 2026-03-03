#include "Game.h"
#include  "Dice.h"
#include <iostream>
#include <cstdlib>

Game::Game(const std::string& playerName)
    : player(playerName)
{
    setupBoard();
}

void Game::run() {
    std::cout << "Game started!\n";
}