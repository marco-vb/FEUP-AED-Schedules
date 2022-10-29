#include "../headers/Student.h"

Student::Student(int number, std::string name) {
    this->number = number;
    this->name = name;
}

int Student::getNumber() const{
    return number;
}

string Student::getName() const{
    return name;
}

set<ClassCourse*> Student::getEnrolledClasses() const{
    return enrolledClasses;
}

void Student::addClass(ClassCourse* newClass){
    // O(logN)
    enrolledClasses.insert(newClass);
}

void Student::removeClass(ClassCourse* classToRemove){
    // O(logN): erase -> O(1) && find -> O(logN)
    enrolledClasses.erase(enrolledClasses.find(classToRemove));
}

void Student::clearClasses(){
    // O(N)
    enrolledClasses.clear();
}

/*
 * Embora os 3 for loops sejam assutadores, eles apenas servem para descompactar aulas da semana toda
 * na realidade equivalem a 1 for loop que itera sobre todas as aulas da semana
 *
 * Complexidade Nlog(M), onde N é o numero total de aulas de uma semana e M o numero maximo de aulas de um dia
 */
WeeklySchedule Student::getSchedule(){
    WeeklySchedule ret;
    for(ClassCourse* class_: enrolledClasses){
        for(auto week: class_->getSchedules()){
            for(ClassSchedule* schedule: week)
                ret[schedule -> getWeekDay()].insert(schedule);
        }
    }
    return ret;
}