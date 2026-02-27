//
// Created by ASUS on 27.02.2026.
//

#include "Dice.h"
#include <cstdlib>
#include <ctime>

int Dice::roll() {
    std::srand(std::time(nullptr));
    return std::rand() % 6 + 1;
}