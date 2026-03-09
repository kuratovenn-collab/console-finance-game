#include "UI.h"
#include "Game.h"
#include  "Dice.h"
#include "GamblingEvent.h"
#include "TrapEvent.h"
#include <iostream>
#include <memory>

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <random>

Game::Game(const std::string& playerName) : player(playerName) {
    setupBoard();
}
void Game::setupBoard() {
    const int totalCells = 16;
    std::vector<int> eventTypes;
    for (int i = 0; i < totalCells; ++i) {
        eventTypes.push_back(i % 6);
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(eventTypes.begin(), eventTypes.end(), g);

    for (int type : eventTypes) {
        if (type == 0 || type == 2 || type == 4) {
            board.addEvent(std::make_unique<GamblingEvent>("Tavern " + std::to_string(type)));
        } else {
            board.addEvent(std::make_unique<TrapEvent>("Danger " + std::to_string(type)));
        }
    }
}


void Game::run() {

    std::cout << BOLD << GREEN << "Game started!"<< RESET <<"\n";

    while (player.getPosition() < board.size()) {

        processTurn();

        if (player.getLives() <= 0) {
            std::cout << "You lost all lives! Restarting from beginning...\n";
            ///player.reset();
            break;
        }
    }

    checkEnding();
}
void Game::processTurn() {

    std::cout << "\nPress Enter to roll dice...";
    std::cin.get();
    int roll = Dice::roll();
    std::cout << "You rolled: " << BOLD << roll << RESET << "\n";

    player.move(roll);
    std::cout << "Current position: " << player.getPosition() << "\n";
    if (player.getPosition() >= board.size()) {
        return;
    }


    Event& event = board.getEventAt(player.getPosition());
    std::cout << "Event: " << BOLD << event.getTitle() << RESET << "\n";
    event.play(player);
    std::cout << "--- Player Stats ---\n";
    std::cout << "Position: " << BLUE << player.getPosition() << RESET  << " /" << BLUE << " 16 " << RESET << "\n";
    std::cout << "Money: " << YELLOW << player.getMoney() << RESET << "\n";
    std::cout << "Lives: "  << RED << player.getLives() << RESET  << "\n";
    std::cout << "--------------------\n";
}
void Game::checkEnding() {
    printLine();
    if (player.getLives() <= 0) {
        std::cout << RED << BOLD << "=====YOU DIED=====\n" "==YOUR ADVENTURE ENDS HERE==" << RESET << "\n";
    } else {
        std::cout << GREEN << BOLD << "===CONGRATULATIONS!===\n""==YOU REACHED THE END==" << RESET << "\n";
        int money = player.getMoney();
        if (money < 50)
            std::cout << "poor.\n";
        else if (money < 150)
            std::cout << "not poor.\n";
        else
            std::cout << "rich\n";
    }
}
