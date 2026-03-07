//
// Created by Maria Tumasova on 07.03.2026.
//

#ifndef CONSOLE_FINANCE_GAME_TRAPEVENT_H
#define CONSOLE_FINANCE_GAME_TRAPEVENT_H
#pragma once

#include "Event.h"
#include "Player.h"
#include <string>

class TrapEvent : public Event {
private:
    std::string title_;
    static constexpr float PENALTY_RATIO = 0.2f;

public:
    explicit TrapEvent(std::string title);

    bool play(Player& player) override;
    std::string getTitle() const override;
};
#endif //CONSOLE_FINANCE_GAME_TRAPEVENT_H