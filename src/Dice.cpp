//
// Created by ASUS on 27.02.2026.
//

#include "Dice.h"
#include <random>

int Dice::roll() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(1,6);
    return dist(gen);
}