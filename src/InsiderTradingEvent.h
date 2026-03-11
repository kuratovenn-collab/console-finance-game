//
// Created by Air MT on 12.03.2026.
//

#ifndef VISUALNOVELDICE_INSIDERTRADINGEVENT_H
#define VISUALNOVELDICE_INSIDERTRADINGEVENT_H

#pragma once
#include "Event.h"
#include "Player.h"
#include <string>
#include <optional>

class InsiderTradingEvent : public Event {
private:
    std::string title;
    static constexpr int INFO_COST = 35;
    static constexpr int WIN_CHANCE = 60;
    std::optional<int> getInsiderProfit();
public:
    explicit InsiderTradingEvent(std::string t);
    bool play(Player &player) override;
    std::string getTitle() const override;
};
#endif //VISUALNOVELDICE_INSIDERTRADINGEVENT_H
