//
// Created by MT Air on 09.03.2026.
//

#ifndef CONSOLE_FINANCE_GAME_PILLEVENT_H
#define CONSOLE_FINANCE_GAME_PILLEVENT_H

#include "Event.h"
#include "Player.h"
#include <string>

class PillEvent : public Event {
private:
    std::string title;
public:
    explicit PillEvent(std::string t);
    bool play(Player& player) override;
    std::string getTitle() const override;
};
#endif //CONSOLE_FINANCE_GAME_PILLEVENT_H