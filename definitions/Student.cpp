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

bool Student::addClassCourse(string const& classcode, string const& coursecode, courseSet* courses, classSet* classes) {
    auto course = courses->find(new Course(coursecode));
    auto courseStudents = (*course)->getStudents();
    if (this->getClassesPerCourse().find({classcode, coursecode}) != this->getClassesPerCourse().end()) return false;

    auto courseSchedule = (*course)->getSchedule();
    auto courseSlots = courseSchedule.getSchedule();
    Slot slot;
    for (const auto& slotSet : courseSlots) {
        bool found = false;
        for (const auto &s: slotSet)
            if (s.getClassCode() == classcode) {
                slot = s;
                found = true;
                break;
            }
        if (found) break;
    }
    if (courseSchedule.checkForCollision(slot)) return false;

    this->classesPerCourse.insert(make_pair(classcode, coursecode));
    (*course)->addStudent(this->getNumber());
    auto class1 = classes->find(new Class(classcode));
    (*class1)->addStudent(this->getNumber());
    return true;
}

bool Student::removeClassCourse(string const& classcode, string const& coursecode, courseSet* courses){
    pair<string, string> pair = {classcode, coursecode};
    if (classesPerCourse.find(pair) == classesPerCourse.end()) return false;
    classesPerCourse.erase(pair);
    return true;
}

