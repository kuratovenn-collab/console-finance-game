#pragma once
#include "Event.h"
#include "Player.h"
#include "Exceptions.h"
#include <optional>
#include <string>

class CorpseEvent : public Event {
private:
    std::string title;

    static constexpr int LOOT_CHANCE = 60;
    std::optional<int> searchCorpse(); 

public:
    explicit CorpseEvent(std::string t);
    bool play(Player& player) override;
    std::string getTitle() const override;
};