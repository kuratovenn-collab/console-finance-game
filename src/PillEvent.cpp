//
// Created by MT Air on 09.03.2026.
//

#include "PillEvent.h"
#include "Event.h"
#include <iostream>
#include <variant>

PillEvent::PillEvent(std::string t) : title(std::move(t)) {}

bool PillEvent::play(Player& player) {
    std::cout << "\n=== " << title << " ===\n";

    int currentMoney = player.getMoney();
    int redPrice = currentMoney / 6;
    int blueReward = currentMoney / 4;

    std::cout << "You meet a traveler. Choice:\n";
    std::cout << "1. Red Pill: Recover 1 life, cost " << redPrice << " gold.\n";
    std::cout << "2. Blue Pill: Get " << blueReward << " gold, lose 1 life.\n";
    std::cin >> choice;

    std::variant<int, std::string> eventResult;

    if (choice == 1) {
        player.spendMoney(redPrice);
        player.loseLives(-1);
        eventResult = "You feel much better.";
    } else {
        player.addMoney(blueReward);
        player.loseLives(1);
        eventResult = "You found some gold, but it hurt.";
    }

    std::visit([](auto&& arg) {
        std::cout << arg << std::endl;
    }, eventResult);

    if (player.getLives() <= 0) {
        std::cout << "Game over.\n";
        return false;
    }
    return true;
}