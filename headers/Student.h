#ifndef STUDENTNEW_H_
#define STUDENTNEW_H_

#include <bits/stdc++.h>
#include "Schedule.h"

using namespace std;


class Student {
    private:
        int number;
        string name;
        set<pair<string, string>> classesPerCourse;
        Schedule schedule;

    public:
        explicit Student(int number);
        int getNumber() const;
        string getName() const;
        void setName(string name);
        set<pair<string, string>> getClassesPerCourse() const;
        bool addSlot(Slot slot);
        Schedule getSchedule() const;
        bool addClassCourse(string const& classcode, string const& coursecode);
        bool removeClassCourse(string const& classcode, string const& coursecode);
        void printSchedule(ostream& out = cout) const;    //prints through Schedule
        void printSchedule(string const& filename) const;
};


#endif