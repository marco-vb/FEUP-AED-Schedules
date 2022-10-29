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
 * 1º for loop que itera sobre todos as cadeiras do estudante: Nº de cadeiras
 * 2º for loop que itera sobre todos os dias da semana: Dias/Semana
 * 3º for loop que itera sobre todas as aulas de um dia: (Aulas/Cadeira)/Dia
 * Logo, o tempo de execução é O(Nº de cadeiras * Dias/Semana * (Aulas/Cadeira)/Dia) = O(Aulas/Semana)
 *
 * Complexidade: Nlog(M), onde N é o numero total de aulas de uma semana e M o numero maximo de aulas de um dia
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

void Student::printSchedule(ostream& out){
    out << "Schedule for " << name << " (" << number << "):" << endl;
    WeeklySchedule schedule = getSchedule();
    for(int i = 0; i < 6; i++){
        if(!schedule[i].empty()) out << WeeklySchedule::numToWeekDay(i) << ": " << endl;
        for(ClassSchedule* class_: schedule[i])
            class_ -> print(out);
        out << endl;
    }
}
void Student::printSchedule(string filename) {
    ofstream out(filename);
    printSchedule(out);
    out.close();
}
