#include <utility>

#include "../headers/StudentNew.h"

using namespace std;

StudentNew::StudentNew(int number, string name) {
    this->name = std::move(name);
    this->number = number;
    this->classes = set<string>();
    this->courses = set<string>();
}

int StudentNew::getNumber() const {
    return number;
}

string StudentNew::getName() const {
    return name;
}

set<string> StudentNew::getClasses() const {
    return classes;
}

set<string> StudentNew::getCourses() const {
    return courses;
}

Schedule StudentNew::getSchedule() const {
    return schedule;
}

bool StudentNew::addClass(string const& classcode) {
    if (classes.find(classcode) != classes.end()) return false;
    classes.insert(classcode);
    return true;
}

bool StudentNew::removeClass(string const& classcode) {
    if (classes.find(classcode) == classes.end()) return false;
    classes.erase(classcode);
    return true;
}

bool StudentNew::addSlot(Slot *slot) {
    return schedule.addSlot(slot);
}

void StudentNew::printSchedule(ostream& out){
    out << "Schedule for " << name << " (" << number << "):" << endl;
    Schedule s = this->getSchedule();

    for (Slot* slot : s.getSchedule()){
        out << slot->getDay() << ": " << slot->getCourseCode() << " " << slot->getStartHour() << " " << slot->getEndHour() << endl;
    }
}

void StudentNew::printSchedule(const string &filename) {
    ofstream out(filename);
    printSchedule(out);
    out.close();
}

