#include <utility>

#include "../headers/Schedule.h"

Schedule::Schedule() {
    schedule = vector<set<Slot>>(6);
}

vector<set<Slot>> Schedule::getSchedule() const {
    return schedule;
}

void Schedule::clearSchedule() {
    for(int i = 0; i < 6; i++){
        schedule[i].clear();
    }
}

bool Schedule::addSlot(const Slot slot) {
    schedule[weekDayToNum(slot.getDay())].insert(slot);
    return true;
}

bool Schedule::checkForCollision(Slot slot){
    if(slot.getType() == "T") return false;
    for(Slot cs : schedule[weekDayToNum(slot.getDay())]){
        if(cs.getType() != "T") {
            return (cs.getStartHour() < slot.getStartHour() && cs.getEndHour() > slot.getStartHour()) ||
                   (slot.getStartHour() < cs.getStartHour() && slot.getEndHour() > cs.getStartHour());
        }
    }
    return false;
}

set<Slot>& Schedule::operator[] (int n){
    return schedule[n];
}

set<Slot>& Schedule::operator[] (string day){
    return schedule[weekDayToNum(day)];
}

set<Slot>::iterator Schedule::begin(){
    return schedule[0].begin();
}

set<Slot>::iterator Schedule::end(){
    return schedule[5].end();
}

const map<int, string> Schedule::numToWeekDay_ = {{0, "Monday"}, {1, "Tuesday"}, {2, "Wednesday"},
                                                        {3, "Thursday"}, {4, "Friday"}, {5, "Saturday"}};

const map<string, int> Schedule::weekDayToNum_ = {{"Monday", 0}, {"Tuesday", 1}, {"Wednesday", 2},
                                                        {"Thursday", 3}, {"Friday", 4}, {"Saturday", 5}};

string Schedule::numToWeekDay(int n){
    return numToWeekDay_.at(n);
}
int Schedule::weekDayToNum(string day){
    return weekDayToNum_.at(day);
}