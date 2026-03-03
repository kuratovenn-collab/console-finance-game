//
// Created by ASUS on 27.02.2026.
//

#ifndef GIT_BOARD_H
#define GIT_BOARD_H

#pragma once
#include <vector>
#include <memory>
#include "Event.h"

class Board {
private:
    std::vector<std::unique_ptr<Event>> events;
	int lastEventID = -1;
public:
    Board() = default;

    void addEvent(std::unique_ptr<Event> event);
    Event& getRandomEvent();
    int size() const;
};


#endif //GIT_BOARD_H