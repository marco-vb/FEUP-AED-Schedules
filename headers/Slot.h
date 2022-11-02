#ifndef SLOT_H_
#define SLOT_H_

#include <bits/stdc++.h>

using namespace std;

class Slot {
    private:
        string day;         // day of the week (e.g. "Monday")
        float startHour;
        float endHour;
        string type;        // type ("T", "TP", "PL")
        string coursecode;  // class code (e.g. "L.EIC001")
        string classcode;   // class code (e.g. "1LEIC01")

    public:
        Slot(string day, float startHour, float endHour, string type, string coursecode, string classcode);
        string getDay() const;
        float getStartHour() const;
        float getEndHour() const;
        string getType() const;
        string getCourseCode() const;
        string getClassCode() const;
        void print(std::ostream &out) const;
        bool operator<(Slot slot) const;
};

#endif