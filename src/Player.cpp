#include "Player.h"

Player::Player(std::string n, int startMoney)
    : name(std::move(n)), money(startMoney), position(0) {}

int Player::getMoney() const { return money; }

void Player::addMoney(int amount) { money += amount; }

bool Player::spendMoney(int amount) {
    if (amount > money) return false;
    money -= amount;
    return true;
}

int Player::getPosition() const { return position; }

void Player::move(int steps) { position += steps; }