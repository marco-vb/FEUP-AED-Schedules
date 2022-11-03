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

bool Schedule::addSlot(const Slot& slot) {
    schedule[weekDayToNum(slot.getDay())].insert(slot);
    return true;
}

bool Schedule::checkForCollision(const Slot& slot){
    if(slot.getType() == "T") return false;
    for(const Slot& cs : schedule[weekDayToNum(slot.getDay())]){
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


set<Slot>& Schedule::operator[] (const string& day){
    return schedule[weekDayToNum(day)];
}

set<Slot>::iterator Schedule::begin(){
    return schedule[0].begin();
}

set<Slot>::iterator Schedule::end(){
    return schedule[5].end();
}