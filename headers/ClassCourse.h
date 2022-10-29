#ifndef CLASSCOURSE_H_
#define CLASSCOURSE_H_

#include "WeeklySchedule.h"

class ClassCourse {
private:
    string classCode;
    string courseCode;
    WeeklySchedule schedule;

public:
    ClassCourse(string courseCode, string classCode);
//    void addSchedule(ClassSchedule* schedule);
//    void removeSchedule(ClassSchedule* schedule);
//    void clearSchedule();

    string getClassCode() const;
    string getCourseCode() const;
    WeeklySchedule& getSchedules();

    bool operator<(ClassCourse uc) const;


};

#endif