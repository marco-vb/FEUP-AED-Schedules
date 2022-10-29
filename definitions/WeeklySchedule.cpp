#include "../headers/WeeklySchedule.h"

set<ClassSchedule*, comp>& WeeklySchedule::operator[] (int n){
    return schedule[n];
}

set<ClassSchedule*, comp>& WeeklySchedule::operator[] (string day){
    return schedule[weekDayToNum(day)];
}

set<ClassSchedule*, comp>* WeeklySchedule::begin(){
    return schedule;
}

set<ClassSchedule*, comp>* WeeklySchedule::end(){
    return schedule + 6;
}

void WeeklySchedule::merge(WeeklySchedule ws){
    // N*log(M), onde N e numero maximo de aulas de um dia de ws
    // e M numero maximo de aulas de um dia do Weekly Schedule atual

    for(int i = 0; i < 6; i++){
        for(ClassSchedule* cs: ws[i]){
            schedule[i].insert(cs);
        }
    }
}

const map<int, string> WeeklySchedule::numToWeekDay_ = {{0, "Monday"}, {1, "Tuesday"}, {2, "Wednesday"},
                                                        {3, "Thursday"}, {4, "Friday"}, {5, "Saturday"}};

const map<string, int> WeeklySchedule::weekDayToNum_ = {{"Monday", 0}, {"Tuesday", 1}, {"Wednesday", 2},
                                                        {"Thursday", 3}, {"Friday", 4}, {"Saturday", 5}};

const string WeeklySchedule::numToWeekDay(int n){
    return numToWeekDay_.at(n);
}
const int WeeklySchedule::weekDayToNum(string day){
    return weekDayToNum_.at(day);
}
