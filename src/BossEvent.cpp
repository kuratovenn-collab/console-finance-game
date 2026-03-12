//
// Created by Air MT on 12.03.2026.
//
#include "BossEvent.h"
#include <iostream>
#include <cmath>

BossEvent::BossEvent(std::string t) : title(std::move(t)) {}

std::string BossEvent::getTitle() const {
    return title;
}

bool BossEvent::play(Player& player) {
    std::cout << "\n<<< " << title << " >>>\n";
    std::cout << "C++ Mafia Boss suddenly appears before you. It seems he is not in the mood." << "\n";
    std::cout << "'Unscheduled capital audit'" << "\n";

    int currentMoney = player.getMoney();
    int tax = static_cast<int>(std::floor(currentMoney * 0.25f));

    if (tax > 0) {
        player.spendMoney(tax);
        std::cout << "You lose " << tax << " gold!" << "\n";
        std::cout << currentMoney << " -> " << player.getMoney() << "\n";
        std::cout << "'But you have a chance to recover your gold and save yourself, if you answer the question'" << "\n";
    } else {
        std::cout << "He looks at your empty pockets with disappointment" << "\n";
        std::cout << "'No money, but the knowledge check is still mandatory. Answer my question or you will pay with your life essence'" << "\n";
    }

    int choice;

    while (true) {
        std::cout << "QUESTION: Which keyword ensures that a function or variable can be evaluated at compile time?" << "\n";
        std::cout << "1. const" << "\n";
        std::cout << "2. constexpr" << "\n";
        std::cout << "3. inline" << "\n";
        std::cout << "Your choice (1, 2 or 3): ";

        if (std::cin >> choice) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');

            if (choice == 2) {
                std::cout << "'Correct. I see you haven't forgotten the basics. You may go.'" << "\n";
                if (tax > 0) {
                    player.addMoney(tax);
                    std::cout << "You recovered your " << tax << " gold for the correct answer!" << "\n";
                }
                break;
            }
            else if (choice == 1 or choice == 3) {
                std::cout << "'A gross mistake! You must pay with your life essence'" << "\n";
                player.loseLives(1);
                std::cout << "C++ Mafia Boss takes 1 life. Lives left: " << player.getLives() << "\n";

                if (tax > 0) {
                    std::cout << "Your gold remains in the department's fund forever" << "\n";
                }
                break;
            }
        }
        std::cout << "\n[ERROR]: You don't have paths except 1, 2 and 3. Try again!"<<"\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    if (player.getLives() <= 0) {
        std::cout << "You have fallen victim to academic rigor" << "\n";
        std::cout << "=== GAME OVER ===";
        return false;
    }

    return true;
}