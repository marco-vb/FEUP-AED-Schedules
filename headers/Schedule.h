#include <bits/stdc++.h>
#include "Slot.h"

using namespace std;

#ifndef SCHEDULE_H
#define SCHEDULE_H

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
