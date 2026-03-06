//
// Created by Максим Богини on 06.03.2026.
//

#ifndef VISUALNOVELDICE_GAMBLINGEVENT_H
#define VISUALNOVELDICE_GAMBLINGEVENT_H
#pragma once
#include "Event.h"
#include "Player.h"
#include <random>

class GamblingEvent : public Event {
private:
    std::string title;
    int minBet;

public:
    explicit GamblingEvent(std::string t, int bet = 10);
    bool play(Player& player) override;
    std::string getTitle() const override;
};



#endif //VISUALNOVELDICE_GAMBLINGEVENT_H