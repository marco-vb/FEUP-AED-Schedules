#include "../headers/ClassCourse.h"

ClassCourse::ClassCourse(string courseCode, string classCode){
    this->courseCode = courseCode;
    this->classCode = classCode;
}

string ClassCourse::getClassCode() const{
    return classCode;
}

string ClassCourse::getCourseCode() const{
    return courseCode;
}

WeeklySchedule& ClassCourse::getSchedules(){
    return schedule;
}

bool ClassCourse::operator<(ClassCourse uc) const{
    return classCode < uc.classCode;
}