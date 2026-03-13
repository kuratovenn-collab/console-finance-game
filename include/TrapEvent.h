//
// Created by MT Air on 07.03.2026.
//

#ifndef CONSOLE_FINANCE_GAME_TRAPEVENT_H
#define CONSOLE_FINANCE_GAME_TRAPEVENT_H
#include "Event.h"
#include "Player.h"
#include <string>

class TrapEvent : public Event {
private:
    std::string title;
public:
    explicit TrapEvent(std::string t);
    bool play(Player& player) override;
    std::string getTitle() const override;
};
#endif //CONSOLE_FINANCE_GAME_TRAPEVENT_H