#ifndef STUDENT_H_
#define STUDENT_H_

#include <bits/stdc++.h>

#include "ClassCourse.h"
#include "ClassSchedule.h"
#include "Request.h"

using namespace std;

class Student {

private:
    int number;
    string name;
    set<ClassCourse*> enrolledClasses;

public:
    Student(int number, string name);

    int getNumber() const;
    string getName() const;
    set<ClassCourse*> getEnrolledClasses() const;

    void addClass(ClassCourse* newClass);
    void removeClass(ClassCourse* classToRemove);
    void clearClasses();
    WeeklySchedule getSchedule();
    void printSchedule(ostream& out = cout);
    void printSchedule(string filename);

};


#endif