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

void Slot::print(std::ostream &out = cout) const {
    out << classcode << " - " << coursecode << " - " << type << " - "
        << startHour << "-" << endHour << endl;
}

bool Slot::operator<(Slot slot) const{
    return this -> startHour < slot.getStartHour();
}