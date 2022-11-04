#ifndef TYPES_H
#define TYPES_H

#include <bits/stdc++.h>
#include "Student.h"
#include "Course.h"
#include "Class.h"

using namespace std;

//comparing structs

//order students by number
/// Compara dois estudantes por ordem crescente de numero de estudante
struct studentCompare {
    /**
     * @brief Função que compara dois estudantes por ordem crescente de numero de estudante
     *
     * Complexidade Temporal: O(1)
     *
     * @param a Primeira estudante a comparar
     * @param b Segunda estudante a comparar
     * @return true se o numero de estudante do primeiro estudante for menor que o do segundo
     */
    bool operator()(const Student* a, const Student* b) const {
        return a->getNumber() < b->getNumber();
    }
};

//order courses by code
///struct classCourse que guarda um par de apontadores para uma classe e um curso e o respetivo número de estudantes
struct classCourse {
    string class_;
    string course;
    int students;
    /**
     * @brief Função que compara dois classCourse por ordem alfabética de codigo da turma, e em caso de empate por ordem alfabética de codigo da unidade curricular
     *
     * Complexidade Temporal: O(1)
     *
     * @param a Primeiro classCourse a comparar
     * @param b Segundo classCourse a comparar
     * @return true se o codigo da UC do primeiro for menor que o do segundo, ou se os codigos da UC forem iguais e o codigo da turma do primeiro for menor que o do segundo, e falso caso contrario
     */
    bool operator()(const classCourse& a, const classCourse& b) const {
        return (a.course < b.course) ||
               (a.course == b.course && a.class_ < b.class_);
    }

    bool operator<(const classCourse& b) const {
        return (course < b.course) ||
               (course == b.course && class_ < b.class_);
    }
};

/// Compara dois slots por ordem alfabética de codigo da turma, e em caso de empate por ordem alfabética de codigo da unidade curricular
struct slotCompare{
    /**
     * @brief Função que compara dois slots por ordem alfabética de codigo da turma, e em caso de empate por ordem alfabética de codigo da unidade curricular
     *
     * Complexidade Temporal: O(1)
     *
     * @param a Primeiro slot a comparar
     * @param b Segundo slot a comparar
     * @return true se o codigo da turma do primeiro slot for menor que o do segundo, ou se os codigos da turma forem iguais e o codigo da unidade curricular do primeiro slot for menor que o do segundo, e falso caso contrario
     */
    bool operator()(const Slot* a, const Slot* b) const {
        return a->getClassCode() < b->getClassCode() ||
               (a->getClassCode() == b->getClassCode() && a->getCourseCode() < b->getCourseCode());
    }
};

//define sets
typedef set<Student*, studentCompare> studentSet;
typedef set<classCourse*> classCoursesSet;
typedef set<Slot*, slotCompare> slotSet;

#endif
