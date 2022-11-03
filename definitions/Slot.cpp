#include <utility>

#include "../headers/Slot.h"

using namespace std;

Slot::Slot(string day, float startHour, float endHour, string type, string coursecode, string classcode) {
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

float Slot::getStartHour() const {
    return startHour;
}

float Slot::getEndHour() const {
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

bool Slot::operator<(const Slot& s) const{
    map<string, int> days = { {"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5} };
    if (days[this->getDay()] == days[s.getDay()])
        return this->getStartHour() < s.getStartHour();
    return days[this->getDay()] < days[s.getDay()];
}