//
// Created by Максим Богини on 10.03.2026.
//

#include "../include/CorpseEvent.h"
#include <iostream>
#include <random>

CorpseEvent::CorpseEvent(std::string t) : title(std::move(t)) {}

std::optional<int> CorpseEvent::searchCorpse() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> d100(1, 100);

    int roll = d100(gen);
    if (roll <= 10) {
        throw CursedException("The corpse was a trap of the Abyss!");
    }
    if (roll > 10 && roll <= 10 + LOOT_CHANCE) {
        std::uniform_int_distribution<> lootGen(5, 30);
        return lootGen(gen);
    }
    return std::nullopt;
}

bool CorpseEvent::play(Player& player) {
    std::cout << "\n>>> " << title << " <<<\n";
    std::cout << "A mangled corpse leans against the dungeon wall. It might hold valuables...\n";
    std::cout << "Do you search it? (1 - Yes, 2 - Leave it): ";

    int choice;
    if (!(std::cin >> choice) || choice == 2) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "You wisely step over the body and move on.\n";
        return true;
    }

    try {
        std::cout << "You plunge your hands into the cold rags...\n";
        std::optional<int> foundLoot = searchCorpse();
        if (foundLoot.has_value()) {
            int gold = foundLoot.value();
            std::cout << "Fortune! You found " << gold << " gold pieces hidden in a boot.\n";
            player.addMoney(gold);
        } else {
            std::cout << "Nothing but rot and maggots. The corpse is empty.\n";
        }
    }
    catch (const CursedException& e) {
        std::cout << "ERROR: " << e.what() << "\n";
        std::cout << "Dark magic sears your flesh! You lose 1 life.\n";
        player.loseLives(1);
        std::cout << "Remaining life essence: " << player.getLives() << "\n";
    }

    return true;
}

std::string CorpseEvent::getTitle() const {
    return title;
}