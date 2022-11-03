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
    Schedule schedule = getSchedule();
    for(int i = 0; i < 6; i++){
        if(!schedule[i].empty()) out << Schedule::numToWeekDay(i) << ": " << endl;
        for(Slot class_: schedule[i])
            out << "    Class: " << class_.getClassCode() << " - Course: " << class_.getCourseCode() << " - "
            << class_.getType() << " - " << class_.getStartHour() << "-" << class_.getEndHour() << endl;
        out << endl;
    }
}

void Student::printSchedule(const string &filename) const{
    ofstream out(filename);
    printSchedule(out);
    out.close();
}

