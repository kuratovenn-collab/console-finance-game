#include "Player.h"
#include "Exceptions.h"
Player::Player(std::string n, int startMoney, int startLives)
    : name(std::move(n)), money(startMoney), position(0),lives(startLives) {}

int Player::getMoney() const { return money; }
int Player::getLives() const{return lives;}
void Player::loseLives(int quantity) {
    lives -= quantity;
    if (lives <= 0) {
        throw GameOverException("Your soul belongs to the Abyss now. GAME OVER.");
    }
}



void Player::addMoney(int amount) { money += amount; }

void Player::spendMoney(int amount) {
    if (amount > money) {
        throw InsufficientFundsException("Not enough gold to pay the toll.");
    }
    money -= amount;
}

int Player::getPosition() const { return position; }

void Player::move(int steps) { position += steps; }