//
// Created by Максим Богини on 26.02.2026.
//

#ifndef CONSOLE_FINANCE_GAME_PLAYER_H
#define CONSOLE_FINANCE_GAME_PLAYER_H


#include <string>

    class Player {
    private:
        std::string name;
        int money;
        int position;
        int lives;

    public:
        Player(std::string n, int startMoney = 100,int startLives = 3);
        int getMoney() const;
        void addMoney(int amount);
        bool spendMoney(int amount);
        int getPosition() const;
        int getLives() const;
        int loseLives(int quanitiy);
        void move(int steps);
    };


#endif //CONSOLE_FINANCE_GAME_PLAYER_H