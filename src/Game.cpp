#include "Game.h"
#include  "Dice.h"
#include <iostream>
#include <cstdlib>

Game::Game(const std::string& playerName)
    : player(playerName)
{
    setupBoard();
}
void Game::setupBoard() {
for (int i = 0; i < 12; ++i) {
        board.addEvent(std::make_unique<GamblinEvent>());
    }
}

void Game::run() {

    std::cout << "Game started!\n";

}
