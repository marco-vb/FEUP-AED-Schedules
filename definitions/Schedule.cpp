#include <utility>

#include "../headers/Schedule.h"

Schedule::Schedule() {
    schedule = vector<Slot*>();
}

vector<Slot*> Schedule::getSchedule() const {
    return schedule;
}

void Schedule::clearSchedule() {
    schedule.clear();
}

bool Schedule::addSlot(Slot* slot) {
    if (slot == nullptr) return false;
    schedule.push_back(slot);
    return true;
}