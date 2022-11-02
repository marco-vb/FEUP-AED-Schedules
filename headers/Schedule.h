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
        bool addSlot(const Slot slot);
        set<Slot>& operator[] (int n);
        set<Slot>& operator[] (string day);
        set<Slot>::iterator begin();
        set<Slot>::iterator end();

        static string numToWeekDay(int n);
        static int weekDayToNum(string day);
};

//class ScheduleIterator{
//    private:
//        Schedule schedule;
//        int day;
//        set<Slot>::iterator it;
//    public:
//        ScheduleIterator(set<Slot>::iterator it, Schedule schedule, int day);
//        ScheduleIterator& operator++();
//        ScheduleIterator operator++(int);
//        bool operator==(const ScheduleIterator& other) const;
//        bool operator!=(const ScheduleIterator& other) const;
//        set<Slot>& operator*();
//};

#endif
