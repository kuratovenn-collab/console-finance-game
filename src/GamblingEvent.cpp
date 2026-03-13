//
// Created by Максим Богини on 06.03.2026.
//

#include "GamblingEvent.h"
#include <iostream>

GamblingEvent::GamblingEvent(std::string t, int bet)
    : title(std::move(t)), minBet(bet) {}

bool GamblingEvent::play(Player& player) {
    std::cout << "\n=== " << title << " ===\n";
    std::cout << "You are now in the Tavern of Orcs...A hooded figure emerges from the shadows. 'The minimum bet is " << minBet << " gold,' it hisses.\n";
    std::cout << "Your wealth: " << player.getMoney() << ". Enter your bet: ";

    int bet;
    std::cin >> bet;
    std::cin.ignore(1000, '\n');
    if (bet < minBet || bet > player.getMoney()) {
        std::cout << "You dare offer what you do not have, or offer too little? The shadows laugh at you.\n";
        return false;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> d6(1, 6);

    int playerRoll = d6(gen);
    int enemyRoll = d6(gen);

    std::cout << "You roll the bone dice: [" << playerRoll << "]\n";
    std::cout << "The entity rolls: [" << enemyRoll << "]\n";

    if (playerRoll > enemyRoll) {
        std::cout << "You survive... You claim " << bet << " gold and step forward.\n";
        player.addMoney(bet);
        return true;
    }
    else if (playerRoll == enemyRoll) {
        std::cout << "A tie. The abyss is unsatisfied. You must roll again.\n";
        return false;
    }
    else {
        std::cout << "The darkness consumes your bet of " << bet << " gold. You are trapped here.\n";
        player.spendMoney(bet);
        return false;
    }
}

std::string GamblingEvent::getTitle() const {
    return title;
}