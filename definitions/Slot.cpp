#include <utility>

#include "../headers/Slot.h"

using namespace std;

Slot::Slot() {
    this->day = string();
    this->startHour = 0;
    this->endHour = 0;
    this->type = string();
    this->coursecode = string();
    this->classcode = string();
}

Slot::Slot(const Slot& slot) {
    this->day = slot.day;
    this->startHour = slot.startHour;
    this->endHour = slot.endHour;
    this->type = slot.type;
    this->coursecode = slot.coursecode;
    this->classcode = slot.classcode;
}

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
    if (days[this->getDay()] == days[s.getDay()]) {
        if (this->getStartHour() == s.getStartHour()) {
            return this->getClassCode() < s.getClassCode() ||
                   (this->getClassCode() == s.getClassCode() && this->getCourseCode() < s.getCourseCode());
        } else
            return this->getStartHour() < s.getStartHour();
    }
    return days[this->getDay()] < days[s.getDay()];
}