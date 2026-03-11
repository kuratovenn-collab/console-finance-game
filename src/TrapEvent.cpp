//
// Created by Maria Tumasova on 07.03.2026.
//

#include "TrapEvent.h"
#include <iostream>
#include <cmath>

TrapEvent::TrapEvent(std::string title)
    : title(std::move(title)) {}

bool TrapEvent::play(Player& player) {
    std::cout << title ;
    std::cout << " You've fallen into a trap!\n";
    std::cout << "Bandits jump out from the shadows and beat you bloody...\n\n";

    int currentLives = player.getLives();
    player.loseLives(1);
    std::cout << "You lose 1 life! (" << currentLives << " -> " << player.getLives() << " )\n";

    int currentMoney = player.getMoney();
    int stolen = static_cast<int>(std::floor(currentMoney * 0.2f));

    if (stolen > 0) {
        player.spendMoney(stolen);
        std::cout << "They steal " << stolen << " gold from you! (";
        std::cout << currentMoney << " -> " << player.getMoney() << " \n";
    } else {
        std::cout << "You have no gold, so they just kick you and leave.\n";
    }
    return true;
}
std::string TrapEvent::getTitle() const {
    return title;
}