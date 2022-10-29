#include "../headers/ClassSchedule.h"

ClassSchedule::ClassSchedule(ClassCourse* classCourse, int weekDay, float startHour, float duration, std::string type) {
    this->classCourse = classCourse;
    this->weekDay = weekDay;
    this->startHour = startHour;
    this->duration = duration;
    this->type = type;

    (classCourse -> getSchedules())[weekDay].insert(this);
}

ClassSchedule::ClassSchedule(ClassCourse* classCourse, std::string weekDay, float startHour, float duration, std::string type) :
        ClassSchedule(classCourse, WeeklySchedule::weekDayToNum(weekDay), startHour, duration, type){}

string ClassSchedule::floatToMinutes(float hour) const {
    float lessThanOne = hour - ((int) hour);
    int minutes = lessThanOne * 60;
    return to_string((int) hour) + ':' + to_string(minutes);
}

ClassCourse* ClassSchedule::getClassCourse() const{
    return classCourse;
}

int ClassSchedule::getWeekDay() const{
    return weekDay;
}

string ClassSchedule::getWeekDayString() const{
    return WeeklySchedule::numToWeekDay(weekDay);
}

float ClassSchedule::getStartHour() const{
    return startHour;
}

string ClassSchedule::getStartHourString() const{
    return floatToMinutes(startHour);
}

float ClassSchedule::getDuration() const{
    return duration;
}

string ClassSchedule::getDurationString() const{
    return floatToMinutes(duration);
}

string ClassSchedule::getType() const{
    return type;
}

void ClassSchedule::setWeekDay(int day){
    weekDay = day;
}

void ClassSchedule::setWeekDay(string day){
    weekDay = WeeklySchedule::weekDayToNum(day);
}

void ClassSchedule::setStartHour(float hour){
    startHour = hour;
}

void ClassSchedule::setDuration(float time){
    duration = time;
}

void ClassSchedule::setType(string initials){
    type = initials;
}

bool ClassSchedule::operator<(ClassSchedule hour) const {
    return (weekDay < hour.weekDay) || (weekDay == hour.weekDay && startHour < hour.startHour);
}

bool comp::operator() (ClassSchedule* cs1, ClassSchedule* cs2){
    return *cs1 < *cs2;
}