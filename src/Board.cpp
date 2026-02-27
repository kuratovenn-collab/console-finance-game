//
// Created by ASUS on 27.02.2026.
//

#include "Board.h"
#include <stdexcept>

void Board::addEvent(std::unique_ptr<Event> event) {
    cells.push_back(std::move(event));
}

Event& Board::getEvent(int position) {
    if (position < 0 || position >= cells.size()) {
        throw std::out_of_range("Position is out of board range");
    }

    return *cells[position];
}

int Board::size() const {
    return static_cast<int>(cells.size());
}