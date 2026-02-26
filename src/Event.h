//
// Created by Максим Богини on 26.02.2026.
//

#ifndef VISUALNOVELDICE_EVENT_H
#define VISUALNOVELDICE_EVENT_H

#pragma once
#include <string>
#include <memory>
#include <variant>
using Reward = std::variant<int, std::string>;

class Event {
public:
    virtual ~Event() = default;
    virtual bool play(class Player& player) = 0;
    virtual std::string getTitle() const = 0;
};


#endif //VISUALNOVELDICE_EVENT_H