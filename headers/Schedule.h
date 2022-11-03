#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <bits/stdc++.h>
#include "Slot.h"

using namespace std;

class Schedule {
    private:
        vector<set<Slot>> schedule;
        static const map<int, string> numToWeekDay_;
        static const map<string, int> weekDayToNum_;

    public:
        Schedule();
        vector<set<Slot>> getSchedule() const;
        void clearSchedule();
        bool addSlot(const Slot& slot);
        bool checkForCollision(const Slot& slot);
        set<Slot>& operator[] (int n);
        set<Slot>& operator[] (const string& day);
        set<Slot>::iterator begin();
        set<Slot>::iterator end();
        void printSchedule(ostream& out = cout) const;
        void printSchedule(string const& filename) const;

        static string numToWeekDay(int n);
        static int weekDayToNum(const string& day);
};

#endif
