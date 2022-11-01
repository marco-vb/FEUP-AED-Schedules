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
    public:
        Course(string code, int year);
        string getCode() const;
        int getYear() const;
        Schedule getSchedule() const;
        void clearSchedule();
        bool addSlot(Slot* slot);
};

#endif