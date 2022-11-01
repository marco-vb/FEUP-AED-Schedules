#include <utility>

#include "../headers/Class.h"

unsigned short Class::maxStudents = 30;

Class::Class(string code) {
    this->code = std::move(code);
    this->numStudents = 0;
    this->schedule = vector<Slot*>();
    this->students = set<Student*>();
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

set<Student*> Class::getStudents() const {
    return students;
}

void Class::clearSchedule() {
    schedule.clearSchedule();
}

bool Class::addStudent(Student* student) {
    if (numStudents < maxStudents && student != nullptr &&
    students.find(student) == students.end()) {
        students.insert(student);
        return true;
    }
    return false;
}

bool Class::removeStudent(Student* student) {
    if (student != nullptr && students.find(student) != students.end()) {
        students.erase(student);
        return true;
    }
    return false;
}
