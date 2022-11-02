#include <utility>

#include "../headers/Student.h"

using namespace std;

Student::Student(int number) {
    this->name = string();
    this->number = number;
    this->classes = set<string>();
    this->courses = set<string>();
}

int Student::getNumber() const {
    return number;
}

string Student::getName() const {
    return name;
}

void Student::setName(string n) {
    this->name = std::move(n);
}

set<string> Student::getClasses() const {
    return classes;
}

set<string> Student::getCourses() const {
    return courses;
}

Schedule Student::getSchedule() const {
    return schedule;
}

bool Student::addClass(string const& classcode) {
    if (classes.find(classcode) != classes.end()) return false;
    classes.insert(classcode);
    return true;
}

bool Student::addCourse(string const& coursecode) {
    if (courses.find(coursecode) != courses.end()) return false;
    courses.insert(coursecode);
    return true;
}

bool Student::removeClass(string const& classcode) {
    if (classes.find(classcode) == classes.end()) return false;
    classes.erase(classcode);
    return true;
}

bool Student::addSlot(Slot slot) {
    return schedule.addSlot(std::move(slot));
}

void Student::printSchedule(ostream& out){
    out << "Schedule for " << name << " (" << number << "):" << endl;
    Schedule s = this->getSchedule();

    for (const Slot& slot : s.getSchedule()){
        out << slot.getDay() << ": " << slot.getCourseCode() << " " << slot.getStartHour() << " " << slot.getEndHour() << endl;
    }
}

void Student::printSchedule(const string &filename) {
    ofstream out(filename);
    printSchedule(out);
    out.close();
}

