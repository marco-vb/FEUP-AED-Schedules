#ifndef CLASSSCHEDULE_H_
#define CLASSSCHEDULE_H_

#include "WeeklySchedule.h"
#include "ClassCourse.h"
#include "Slot.h"

using namespace std;

class ClassSchedule {

private:
    ClassCourse* classCourse;
    int weekDay;
    float startHour;
    float duration;
    string type;
    string floatToMinutes(float hour) const;

public:
    ClassSchedule(ClassCourse* classCourse, int weekDay, float startHour, float duration, string type);
    ClassSchedule(ClassCourse* classCourse, string weekDay, float startHour, float duration, string type);

    ClassCourse* getClassCourse() const;
    int getWeekDay() const;
    string getWeekDayString() const;
    float getStartHour() const;
    string getStartHourString() const;
    float getDuration() const;
    string getDurationString() const;
    string getType() const;

    void setWeekDay(int day);
    void setWeekDay(string day);
    void setStartHour(float hour);
    void setDuration(float time);
    void setType(string initials);

    bool operator<(ClassSchedule hour) const;

};

#endif