#ifndef SLOT_H_
#define SLOT_H_

#include <bits/stdc++.h>

#include "Class.h"
#include "Course.h"

using namespace std;

class Slot {
    private:
        string day;         // day of the week (e.g. "Monday")
        int startHour;
        int endHour;
        string type;        // type ("T", "TP", "PL")
        string coursecode;  // class code (e.g. "L.EIC001")
        string classcode;   // class code (e.g. "1LEIC01")

    public:
        Slot(string day, int startHour, int endHour, string type, string coursecode, string classcode);
        string getDay() const;
        int getStartHour() const;
        int getEndHour() const;
        string getType() const;
        string getCourseCode() const;
        string getClassCode() const;
};

#endif