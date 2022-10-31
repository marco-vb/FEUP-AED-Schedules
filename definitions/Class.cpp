#include <utility>

#include "../headers/Class.h"

unsigned short Class::maxStudents = 30;

Class::Class(string code) {
    this->code = std::move(code);
    this->numStudents = 0;
    this->schedule = vector<vector<Slot*>>(6, vector<Slot*>());
    this->students = set<Student*>();
}

string Class::getCode() const {
    return code;
}

vector<vector<Slot*>> Class::getSchedule() const {
    return schedule;
}

set<Student*> Class::getStudents() const {
    return students;
}

void Class::clearSchedule() {
    schedule.clear();
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
