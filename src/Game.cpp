#include "UI.h"
#include "Game.h"
#include  "Dice.h"
#include "GamblingEvent.h"
#include "TrapEvent.h"
#include "CorpseEvent.h"
#include "InsiderTradingEvent.h"
#include "PillEvent.h"
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

    for (int i = 1; i < totalCells - 1; ++i) {
        if (eventTypes[i] == eventTypes[i - 1]) {
            std::swap(eventTypes[i], eventTypes[i + 1]);
        }
    }

    for (int type : eventTypes) {
        switch (type) {
            case 0: board.addEvent(std::make_unique<GamblingEvent>("Old Oak Tavern")); break;
            case 1: board.addEvent(std::make_unique<TrapEvent>("Bandit Ambush")); break;
            case 2: board.addEvent(std::make_unique<CorpseEvent>("Mysterious Body")); break;
            case 3: board.addEvent(std::make_unique<InsiderTradingEvent>("Shady Deal")); break;
            case 4: board.addEvent(std::make_unique<PillEvent>("Unknown Pill")); break;
            case 5:board.addEvent(std::make_unique<GamblingEvent>("High Stakes Table"));break;
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
    UI_H::drawBoard(player.getPosition(), 16);
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

    if (player.getLives() <= 0) {
        std::cout << RED << BOLD << "=====YOU DIED=====\n" "==YOUR ADVENTURE ENDS HERE==" << RESET << "\n";
    } else {
        std::cout << GREEN << BOLD << "===CONGRATULATIONS!===\n""==YOU REACHED THE END==" << RESET << "\n";
        std::cout << "You've reached the final destination. The gatekeeper checks your pouch...\n\n";
        int money = player.getMoney();
        if (money < 50){
            std::cout << YELLOW << "THE PENNILESS SURVIVOR:" << RESET << "\n";
        UI_H::typeWrite("You survived, but at what cost? You don't even have enough gold");
        UI_H::typeWrite("to buy a decent meal. You'll probably end up cleaning tavern stables");
        UI_H::typeWrite("to pay off your debts. At least you're alive (mostly).");
        }
        else if (money < 150) {
            std::cout << BLUE << "THE HUMBLE MERCHANT:" << RESET << "\n";
            UI_H::typeWrite( "A solid result! You have enough gold to rent a room and start");
            UI_H::typeWrite("a small business. You didn't become a king, but you didn't");
            UI_H::typeWrite("starve either. A perfectly balanced statistical outcome.");
        }
        else {
            std::cout << GOLD << "THE TECH MOGUL OF THE REALM:" << RESET << "\n";
            UI_H::typeWrite("Unbelievable! With this much gold, you could buy the entire");
            UI_H::typeWrite("kingdom (or at least a high-end GPU). Bards will sing songs");
            UI_H::typeWrite("about your wealth and your incredible luck with the dice!");
        }
    }
}
