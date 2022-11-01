#include <utility>

#include "../headers/StudentNew.h"

using namespace std;

StudentNew::StudentNew(int number, string name) {
    this->name = std::move(name);
    this->number = number;
    this->classes = set<Class*>();
}

int StudentNew::getNumber() const {
    return number;
}

string StudentNew::getName() const {
    return name;
}

set<Class*> StudentNew::getClasses() const {
    return classes;
}

Schedule StudentNew::getSchedule() const {
    return schedule;
}

bool StudentNew::addClass(Class *newClass) {
    if (classes.find(newClass) != classes.end()) return false;
    classes.insert(newClass);
    return true;
}

bool StudentNew::removeClass(Class *classToRemove) {
    if (classes.find(classToRemove) == classes.end()) return false;
    classes.erase(classToRemove);
    return true;
}

bool StudentNew::addSlot(Slot *slot) {
    return schedule.addSlot(slot);
}

void StudentNew::printSchedule(ostream& out){
    out << "Schedule for " << name << " (" << number << "):" << endl;
    Schedule s = this->getSchedule();

    for (Slot* slot : s.getSchedule()){
        out << slot->getDay() << ": " << slot->getCourse().getCode() << " " << slot->getStartHour() << " " << slot->getEndHour() << endl;
    }
}

void StudentNew::printSchedule(const string &filename) {
    ofstream out(filename);
    printSchedule(out);
    out.close();
}

