//
// Created by ASUS on 27.02.2026.
//

#include "Board.h"
#include <stdexcept>

void Board::addEvent(std::unique_ptr<Event> event) {
    cells.push_back(std::move(event));
}

Event& Board::getRandomEvent() {
	if (events.empty()) {
		throw std::runtime_error("No events on board");
	}
	int newID;
	do {
		newID = std::rand() % events.size();
	} while (newID == lastEventID);
	lastEventID = newID;
	return *events[newID];
}
int Board::size() const {
    return static_cast<int>(events.size());
}