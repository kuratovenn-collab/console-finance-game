//
// Created by Air MT on 12.03.2026.
//

#ifndef VISUALNOVELDICE_BOSSMARIAEVENT_H
#define VISUALNOVELDICE_BOSSMARIAEVENT_H

#include "Event.h"
#include "Player.h"
#include <string>

class BossMariaEvent : public Event {
private:
    std::string title;
public:
    explicit BossMariaEvent(std::string t);
    bool play(Player& player) override;
    std::string getTitle() const override;
};

#endif //VISUALNOVELDICE_BOSSMARIAEVENT_H