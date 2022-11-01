#ifndef STUDENTNEW_H_
#define STUDENTNEW_H_

#include <bits/stdc++.h>

#include "Class.h"
#include "Course.h"
#include "Slot.h"
#include "Schedule.h"

using namespace std;

class StudentNew {
    private:
        int number;
        string name;
        set<Class*> classes;
        Schedule schedule;

    public:
        StudentNew(int number, string name);
        int getNumber() const;
        string getName() const;
        set<Class*> getClasses() const;
        Schedule getSchedule() const;
        bool addClass(Class* newClass);
        bool removeClass(Class* classToRemove);
        bool addSlot(Slot* slot);
        void printSchedule(ostream& out = cout);
        void printSchedule(string const& filename);
};


#endif