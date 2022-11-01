#ifndef STUDENTNEW_H_
#define STUDENTNEW_H_

#include <bits/stdc++.h>
#include "Schedule.h"

using namespace std;


class StudentNew {
    private:
        int number;
        string name;
        set<string> classes;       // set of class codes
        set<string> courses;       // set of course codes
        Schedule schedule;

    public:
        StudentNew(int number, string name);
        int getNumber() const;
        string getName() const;
        set<string> getClasses() const;
        set<string> getCourses() const;
        Schedule getSchedule() const;
        bool addClass(string const& classcode);
        bool removeClass(string const& classcode);
        bool addSlot(Slot* slot);
        void printSchedule(ostream& out = cout);
        void printSchedule(string const& filename);
};


#endif