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


