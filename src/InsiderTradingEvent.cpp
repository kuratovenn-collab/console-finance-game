//
// Created by Air MT on 12.03.2026.
//

#include "../include/InsiderTradingEvent.h"
#include <iostream>
#include <random>
#include <variant>

InsiderTradingEvent::InsiderTradingEvent(std::string t) : title(std::move(t)) {}
std::string InsiderTradingEvent::getTitle() const {
    return title;
}

std::optional<int> InsiderTradingEvent::getInsiderProfit() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> d100(1, 100);

    if (d100(gen) <= winChance) {
        return infoCost * 2.5;
    }
    return std::nullopt;
}
bool InsiderTradingEvent::play(Player& player) {
    std::cout << "\n=== " << title << " ===\n";

    int choice;
    while (true) {
        std::cout << "A masked figure emerges from the shadows: 'The Heart Diamond will soon change hands.\n";
        std::cout << "For " << infoCost << " gold, I will show you the right safe. It's not magic, it's a sleight of hand.'\n";
        std::cout << "1. Buy the information"<<"\n";
        std::cout << "2. Walk away"<<"\n";
        std::cout<< "Your choice (1 or 2): "<< "\n";
        if (std::cin >> choice) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            if (choice == 1) {
                if (player.getMoney() < infoCost) {
                    std::cout << "You don't even have enough for a common pebble. Begone" <<"\n";
                    return true;
                }
                player.spendMoney(infoCost);
                std::cout << "You hand over the coins. The figure whispers a combination and vanishes instantly"<<"\n";
                break;
            } else if (choice == 2) {
                std::cout << "You don't believe in fairy tales about diamonds and leave"<<"\n";
                return true;
            }
        }
        std::cout << "[ERROR]: Please enter 1 or 2!"<<"\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    std::optional<int> result = getInsiderProfit();
    Reward eventResult;

    if (result.has_value()) {
        int profit = result.value();
        player.addMoney(profit);
        std::cout << "The trick worked! You found the diamond and sold it to a fence for a high price"<<"\n";
        std::cout << "Your share is: " << profit << " gold"<<"\n";
        eventResult = "The first rule of magic: always be the smartest person in the room";
    } else {
        eventResult = "The safe only contained a note: 'Look closer'. You've been played.";
    }

    std::visit([](auto&& arg) {
        std::cout<< arg << std::endl;
    }, eventResult);

    return true;
}