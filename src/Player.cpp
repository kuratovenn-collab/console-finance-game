#include "Player.h"

Player::Player(std::string n, int startMoney, int startLives)
    : name(std::move(n)), money(startMoney), position(0),lives(startLives) {}

int Player::getMoney() const { return money; }
int Player::getLives() const{return lives;}
void Player::loseLives(int quantity) {
    lives -= quantity;
}



void Player::addMoney(int amount) { money += amount; }

bool Player::spendMoney(int amount) {
    if (amount > money) return false;
    money -= amount;
    return true;
}

int Player::getPosition() const { return position; }

void Player::move(int steps) { position += steps; }