//
// Created by Lenovo on 27/10/2022.
//

#ifndef WEEKLYSCHEDULE_H
#define WEEKLYSCHEDULE_H

#include <set>
#include <map>
#include <vector>
#include <string>
#include <list>
#include <queue>

using namespace std;

class ClassSchedule;
class comp {
public:
    bool operator() (ClassSchedule*, ClassSchedule*);
};

class WeeklySchedule {
private:
    set<ClassSchedule*, comp> schedule[6];
    static const map<int, string> numToWeekDay_;
    static const map<string, int> weekDayToNum_;

public:
    set<ClassSchedule*, comp>& operator[] (int n);
    set<ClassSchedule*, comp>& operator[] (string day);
    set<ClassSchedule*, comp>* begin();
    set<ClassSchedule*, comp>* end();
    void merge(WeeklySchedule ws);

    static const string numToWeekDay(int n);
    static const int weekDayToNum(string day);
};

#endif