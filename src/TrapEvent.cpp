//
// Created by MT Air on 07.03.2026.
//
#include "TrapEvent.h"
#include <iostream>

TrapEvent::TrapEvent(std::string t) : title(std::move(t)) {}

bool TrapEvent::play(Player& player) {
    std::cout << "\n=== " << title << " ===\n";
    std::cout << "Out of the thick fog, several silhouettes emerge. You are surrounded before you can reach for your weapon.\n";

    int lostGold = player.getMoney() / 5;
    player.spendMoney(lostGold);
    player.loseLives(1);

    std::cout << "A heavy blow knocks you to the ground. While you are dazed, the bandits quickly ransack your belongings.\n";
    std::cout<< "They seize" << lostGold << " gold coins and disappear into the darkness, leaving you bruised and weakened.\n";
    std::cout << "Current health: " << player.getLives() << " hearts. Current wealth: "<< player.getMoney() << " gold.\n";

    return true;
}

std::string TrapEvent::getTitle() const {
    return title;
}