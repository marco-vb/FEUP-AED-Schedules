#ifndef SCHEMANAGEMENT_H_
#define SCHEMANAGEMENT_H_

#include <set>
#include <vector>
#include "Student.h"
#include "ClassSchedule.h"

using namespace std;

class ScheduleManagement {
private:
    set<Student> students;
    vector<ClassSchedule> schedules;

public:
    ScheduleManagement();

};

#endif