#include <utility>

#include "../headers/Course.h"
using namespace std;

Course::Course(string code) : code(std::move(code)) {
    this->year = 0;
}

string Course::getCode() const {
    return code;
}

int Course::getYear() const {
    return year;
}

void Course::setYear(int y) {
    this->year = y;
}

Schedule Course::getSchedule() const {
    return schedule;
}

void Course::clearSchedule() {
    schedule.clearSchedule();
}

bool Course::addSlot(Slot slot) {
    return schedule.addSlot(slot);
}

set<int> Course::getStudents() const {
    return students;
}

bool Course::addStudent(int studentNumber) {
    return students.insert(studentNumber).second;
}

bool Course::removeStudent(int studentNumber) {
    return students.erase(studentNumber);
}
