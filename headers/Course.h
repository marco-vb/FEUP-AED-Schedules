#ifndef COURSE_H_
#define COURSE_H_

#include "Slot.h"
#include "Schedule.h"

#include <bits/stdc++.h>
using namespace std;


class Course {
    private:
        string code;            // Course code (e.g. "L.EIC001")
        int year;               // 1st, 2nd, 3rd, 4th, 5th
        Schedule schedule;      // schedule of this course
        set<int> students;      // set of student by id number
    public:
        explicit Course(string code);
        string getCode() const;
        int getYear() const;
        void setYear(int year);
        Schedule getSchedule() const;
        void clearSchedule();
        bool addSlot(Slot slot);
        set<int> getStudents() const;
        bool addStudent(int studentNumber);
        bool removeStudent(int studentNumber);
};

struct comp {
    bool operator()(const Course* a, const Course* b) const {
        return a->getCode() < b->getCode();
    }
};
typedef set<Course*, comp> courseSet;
#endif