#include "../headers/ClassSchedule.h"

// Checks if any class in the schedule is in conflict with the current class
bool checkForCollision(ClassCourse* classCourse, int weekDay, float startHour, float duration, std::string type){
    for (ClassSchedule* cs : classCourse -> getSchedules()[weekDay]){
        if(!(cs -> getType() == "T")) {
            if (cs->getStartHour() <= startHour && cs->getStartHour() + cs->getDuration() > startHour) {
                return true;
            }
            if (cs->getStartHour() < startHour + duration &&
                cs->getStartHour() + cs->getDuration() >= startHour + duration) {
                return true;
            }
        }
    }
    return false;
}

/**
 * Constructor for ClassSchedule
 * @param classCourse
 * @param weekDay
 * @param startHour
 * @param duration
 * @param type
 * Complexidade: Se aula for T ou TP, O(N), se aula for T, O(log(N))
 */
ClassSchedule::ClassSchedule(ClassCourse* classCourse, int weekDay, float startHour, float duration, std::string type) {
    if(!(type == "T") && checkForCollision(classCourse, weekDay, startHour, duration, type)){
        cout << "Colisao detetada! Nao coseguimos adicionar esta aula" << endl;
        return;
    }

    this->classCourse = classCourse;
    this->weekDay = weekDay;
    this->startHour = startHour;
    this->duration = duration;
    this->type = type;

    (classCourse -> getSchedules())[weekDay].insert(this);
}

ClassSchedule::ClassSchedule(ClassCourse* classCourse, std::string weekDay, float startHour, float duration, std::string type) :
        ClassSchedule(classCourse, WeeklySchedule::weekDayToNum(weekDay), startHour, duration, type){}

string ClassSchedule::floatToMinutes(float hour) {
    float lessThanOne = hour - ((int) hour);
    int minutes = lessThanOne * 60;
    string min = to_string(minutes);
    if (min.size() == 1)
        min = "0" + min;
    return to_string((int) hour) + ':' + min;
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

void ClassSchedule::print(std::ostream &out) const {
    out << classCourse -> getClassCode() << " - " << type << " - "
        << getStartHourString() << "-" << ClassSchedule::floatToMinutes(startHour + duration)
        << endl;
}