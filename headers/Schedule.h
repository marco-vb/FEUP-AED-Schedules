#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <bits/stdc++.h>
#include "Slot.h"

using namespace std;

class Schedule {
    private:
        vector<multiset<Slot>> schedule;
        static const map<int, string> numToWeekDay_;
        static const map<string, int> weekDayToNum_;

    public:
        Schedule();
        vector<multiset<Slot>> getSchedule() const;
        void clearSchedule();
        bool addSlot(const Slot slot);
        bool checkForCollision(Slot slot);
        multiset<Slot>& operator[] (int n);
        multiset<Slot>& operator[] (string day);
        multiset<Slot>::iterator begin();
        multiset<Slot>::iterator end();

        static string numToWeekDay(int n);
        static int weekDayToNum(string day);
};

#endif
