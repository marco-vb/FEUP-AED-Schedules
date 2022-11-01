#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <bits/stdc++.h>
#include "Slot.h"

using namespace std;

class Schedule {
    private:
        vector<Slot*> schedule;
    public:
        Schedule();
        vector<Slot*> getSchedule() const;
        void clearSchedule();
        bool addSlot(Slot* slot);
};

#endif
