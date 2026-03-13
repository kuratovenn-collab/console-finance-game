//
// Created by MT Air on 09.03.2026.
//

#include "PillEvent.h"
#include "Event.h"
#include <iostream>
#include <variant>

PillEvent::PillEvent(std::string t) : title(std::move(t)){}
std::string PillEvent::getTitle() const {
    return title;
}
bool PillEvent::play(Player& player) {
    std::cout << "\n=== " << title << " ===\n";
    int choice;
    int redPrice = player.getMoney() / 6;
    int blueReward = player.getMoney() / 4;


    Reward eventResult;

    while (true) {
        std::cout << "You meet a traveler... Choice:\n";
        std::cout << "1. Red Pill: Recover 1 life, cost " << redPrice << " gold.\n";
        std::cout << "2. Blue Pill: Get " << blueReward << " gold, lose 1 life.\n";
        std::cout << "Your choice (1 or 2): ";

        if (std::cin >> choice) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            if (choice == 1) {
                player.spendMoney(redPrice);
                player.loseLives(-1);
                eventResult = "You feel much better.";
                break;
            }
            else if (choice == 2) {
                player.addMoney(blueReward);
                player.loseLives(1);
                eventResult = "You found some gold, but it hurt.";
                break;
            }
        }
        std::cout << "\n[ERROR]: You don't have paths except 1 and 2. Try again!\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    std::visit([](auto&& arg) {
        std::cout << "\n" << arg << std::endl;
    }, eventResult);

    if (player.getLives() <= 0) {
        std::cout << "The wrong pill... You should have considered your choice better"<<"\n";
        std::cout << "=== GAME OVER ==="<<"\n";
        return false;
    }
    return true;
}