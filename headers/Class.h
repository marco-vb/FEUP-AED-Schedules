#ifndef CLASS_H_
#define CLASS_H_

#include "Slot.h"
#include "Student.h"
#include "Schedule.h"

#include <bits/stdc++.h>
using namespace std;

class Class {
    private:
        string code;
        unsigned short numStudents;
        static unsigned short  maxStudents;
        Schedule schedule;
        set<Student*> students;

    public:
        explicit Class(string code);
        string getCode() const;
        Schedule getSchedule() const;
        bool addSlot(Slot* slot);
        set<Student*> getStudents() const;
        void clearSchedule();
        bool addStudent(Student* student);
        bool removeStudent(Student* student);
};

#endif