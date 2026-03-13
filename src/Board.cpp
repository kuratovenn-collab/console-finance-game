//
// Created by ASUS on 27.02.2026.
//

#include "../include/Board.h"
#include <memory>
#include <stdexcept>

void Board::addEvent(std::unique_ptr<Event> event) {
    events.push_back(std::move(event));
}
Event& Board::getEventAt(int index) {
	if (index >= events.size()) {
		return *events.back();
	}
	return *events[index];
}

int Board::size() const {
    return static_cast<int>(events.size());
}
