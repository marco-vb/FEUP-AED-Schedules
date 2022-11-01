#include <utility>

#include "../headers/Slot.h"

using namespace std;

Slot::Slot(string day, int startHour, int endHour, string type, string coursecode, string classcode) {
    this->day = std::move(day);
    this->startHour = startHour;
    this->endHour = endHour;
    this->type = std::move(type);
    this->coursecode = std::move(coursecode);
    this->classcode = std::move(classcode);
}

string Slot::getDay() const {
    return day;
}

int Slot::getStartHour() const {
    return startHour;
}

int Slot::getEndHour() const {
    return endHour;
}

string Slot::getType() const {
    return type;
}

string Slot::getCourseCode() const {
    return coursecode;
}

string Slot::getClassCode() const {
    return classcode;
}
