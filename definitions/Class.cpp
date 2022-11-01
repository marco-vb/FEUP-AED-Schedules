#include <utility>

#include "../headers/Class.h"

unsigned short Class::maxStudents = 30;

Class::Class(string code) {
    this->code = std::move(code);
    this->numStudents = 0;
    this->schedule = Schedule();
    this->students = set<int>();
}

string Class::getCode() const {
    return code;
}

Schedule Class::getSchedule() const {
    return schedule;
}

bool Class::addSlot(Slot* slot) {
    return schedule.addSlot(slot);
}

set<int> Class::getStudents() const {
    return students;
}

void Class::clearSchedule() {
    schedule.clearSchedule();
}

bool Class::addStudent(int studentNumber) {
    if (numStudents < maxStudents && students.find(studentNumber) == students.end()) {
        students.insert(studentNumber);
        numStudents++;
        return true;
    }
    return false;
}

bool Class::removeStudent(int studentNumber) {
    if (students.find(studentNumber) != students.end()) {
        students.erase(studentNumber);
        numStudents--;
        return true;
    }
    return false;
}

