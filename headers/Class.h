#ifndef CLASS_H_
#define CLASS_H_

#include "Schedule.h"
#include <bits/stdc++.h>
using namespace std;

class Class {
    private:
        string code;
        unsigned short numStudents;
        static unsigned short  maxStudents;
        Schedule schedule;
        set<int> students;  // set of student by id number

    public:
        explicit Class(string code);
        string getCode() const;
        Schedule getSchedule() const;
        bool addSlot(Slot slot);
        set<int> getStudents() const;
        void clearSchedule();
        bool addStudent(int studentNumber);
        bool removeStudent(int studentNumber);
};

struct classCompare {
    bool operator()(const Class* a, const Class* b) const {
        return a->getCode() < b->getCode();
    }
};

typedef set<Class*, classCompare> classSet;

#endif