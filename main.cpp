#include <iostream>
#include "headers/ClassSchedule.h"
#include "headers/ClassCourse.h"
#include "headers/Student.h"
using namespace std;

int main() {
    ClassCourse fisica("L.EIC011", "1LEIC01");
    ClassSchedule turma2(&fisica, "Tuesday", 12, 1.5, "TP");
    ClassSchedule turma1(&fisica, "Tuesday", 11.5, 1.5, "TP");
    ClassSchedule turma4(&fisica, "Tuesday", 11.5, 1.5, "TP");
    ClassSchedule turma3(&fisica, "Tuesday", 16.5, 1.5, "TP");

    WeeklySchedule horarioDeUmaSemana = fisica.getSchedules();
    set<ClassSchedule*, comp> horarioDeTerca = horarioDeUmaSemana[1];
    ClassSchedule* primeiraAula = *(horarioDeTerca.begin());
    string duracaoDaPrimiraAula = primeiraAula -> getDurationString();

    cout << duracaoDaPrimiraAula << endl;

    Student pedro(202108806, "Pedro");
    pedro.addClass(&fisica);
    cout << (*(pedro.getEnrolledClasses().begin()) == &fisica) << endl;

    for(auto day: pedro.getSchedule()) {
        cout << "-- ";
        for (ClassSchedule *classPtr: day)
            cout << classPtr->getStartHour() << ", ";
        cout << endl;
    }

    return 0;
}