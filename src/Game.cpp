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
        board.addEvent(std::make_unique<GamblingEvent>("Tavern Gambling"));
		board.addEvent(std::make_unique<TrapEvent>("Bandit Ambush"));
    }
}

void Game::run() {

    std::cout << "Game started!\n";

    while (player.getPosition() < board.size()) {

        processTurn();

        if (player.getLives() <= 0) {
            std::cout << "You lost all lives! Restarting from beginning...\n";
            ///player.reset();
        }
    }

    checkEnding();
}
void Game::processTurn() {


   std::cout << "\nPress Enter to roll dice...";
   std::cin.get();


   int roll = Dice::roll();
   std::cout << "You rolled: " << roll << "\n";


   player.move(roll);


   std::cout << "Current position: " << player.getPosition() << "\n";


   if (player.getPosition() >= board.size()) {
       return;
   }


   Event& event = board.getRandomEvent();
   std::cout << "Event: " << event.getTitle() << "\n";
   event.play(player);
}
void Game::checkEnding() {


   int money = player.getMoney();


   std::cout << "\n=== GAME OVER ===\n";


   if (money < 50)
       std::cout << "poor.\n";
   else if (money < 150)
       std::cout << "not poor.\n";
   else
       std::cout << "rich\n";
}

