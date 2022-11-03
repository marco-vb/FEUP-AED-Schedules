#include <utility>

#include "../headers/Student.h"

using namespace std;

Student::Student(int number) {
    this->name = string();
    this->number = number;
    this->classesPerCourse = set<pair<string, string>>();
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

set<pair<string, string>> Student::getClassesPerCourse() const {
    return classesPerCourse;
}

Schedule Student::getSchedule() const {
    return schedule;
}

bool Student::addClassCourse(string const& classcode, string const& coursecode){
    pair<string, string> pair = {classcode, coursecode};
    if (classesPerCourse.find(pair) != classesPerCourse.end()) return false;
    classesPerCourse.insert(pair);
    return true;
}

bool Student::removeClassCourse(string const& classcode, string const& coursecode){
    pair<string, string> pair = {classcode, coursecode};
    if (classesPerCourse.find(pair) == classesPerCourse.end()) return false;
    classesPerCourse.erase(pair);
    return true;
}

bool Student::addSlot(Slot slot) {
    return schedule.addSlot(std::move(slot));
}

void Student::printSchedule(ostream& out) const{
    out << "Schedule for " << name << " (" << number << "):" << endl;
    Schedule s = getSchedule();
    s.printSchedule(out);
}

void Student::printSchedule(const string &filename) const{
    ofstream out(filename);
    printSchedule(out);
    out.close();
}

