#include "Game.h"
#include <iostream>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    Game game(name);
    game.run();
    return 0;
}