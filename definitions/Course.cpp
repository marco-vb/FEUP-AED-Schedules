#include <utility>

#include "../headers/Course.h"
using namespace std;

Course::Course(string code, int year) : code(std::move(code)), year(year) {}

string Course::getCode() const {
    return code;
}

int Course::getYear() const {
    return year;
}

Schedule Course::getSchedule() const {
    return schedule;
}

void Course::clearSchedule() {
    schedule.clearSchedule();
}

bool Course::addSlot(Slot* slot) {
    return schedule.addSlot(slot);
}
