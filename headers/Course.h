#ifndef COURSE_H_
#define COURSE_H_

#include "Slot.h"
#include "Schedule.h"

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Classe que representa uma unidade curricular
 *
 */
class Course {
    private:
        /// Código da unidade currricular (exemplo: "LEIC001")
        string code;

        /// Ano da unidade curricular
        int year;

        /// Horario da unidade curricular
        Schedule schedule;

        /// Conjunto de alunos inscritos na unidade curricular, ordenados por ordem crescente de numero de estudante
        set<int> students;
    public:

        /**
         * @brief Construtor da classe
         *
         * Complexidade Temporal: O(1)
         *
         * @param code Código da unidade curricular
         */
        explicit Course(string code);

        /**
         * @brief Retorna o código da unidade curricular
         *
         * Complexidade Temporal: O(1)
         *
         * @return O código da unidade curricular
         */
        string getCode() const;

        /**
         * @brief Retorna o ano da unidade curricular
         *
         * Complexidade Temporal: O(1)
         *
         * @return Inteiro do ano da unidade curricular
         */
        int getYear() const;

        /**
         * @brief Muda o ano da unidade curricular
         *
         * Complexidade Temporal: O(1)
         *
         * @param year Novo ano da unidade curricular
         */
        void setYear(int year);

        /**
         * @brief Retorna o horario da unidade curricular
         *
         * Complexidade Temporal: O(1)
         *
         * @return O horario da unidade curricular
         */
        Schedule getSchedule() const;

        /**
        * @brief Limpa o horario da turma
        *
        * Função que limpa o horario da unidade curricular atraves da do metodo clearSchedule da classe Schedule.\n
        * Complexidade Temporal: O(N) onde N é o número de aulas no horario
        */
        void clearSchedule();

        /**
         * @brief Adiciona uma aula ao horario da unidade curricular
         *
         * Função que adiciona uma aula ao horario da unidade curricular atraves da do metodo addSlot da classe Schedule.\n
         * Complexidade Temporal: O(logN) onde N é o número máximo de aulas de um dia
         *
         * @param slot Aula a adicionar
         */
        bool addSlot(Slot slot);

        /**
         * @brief Retorna o set de estudantes inscritos na unidade curricular
         *
         * Complexidade Temporal: O(1)
         *
         * @return O set de estudantes inscritos na unidade curricular
         */
        set<int> getStudents() const;

        /**
         * @brief Adiciona um estudante ao set de estudantes inscritos na unidade curricular
         *
         * Complexidade Temporal: O(logN) onde N é o número de estudantes inscritos na unidade curricular
         *
         * @param studentNumber Numero de estudante a adicionar
         */
        bool addStudent(int studentNumber);

        /**
         * @brief Remove um estudante do set de estudantes inscritos na unidade curricular
         *
         * Complexidade Temporal: O(logN) onde N é o número de estudantes inscritos na unidade curricular
         *
         * @param studentNumber Numero de estudante a remover
         */
        bool removeStudent(int studentNumber);
};

/// Compara duas unidades curriculares
struct comp {
    /**
     * @brief Função que compara duas unidades curriculares
     *
     * Função que compara duas unidades curriculares atraves do seu codigo.\n
     * Complexidade Temporal: O(1)
     *
     * @param a Primeira unidade curricular a comparar
     * @param b Segunda unidade curricular a comparar
     * @return True se a primeira unidade curricular for menor que a segunda, False caso contrario
     */
    bool operator()(const Course* a, const Course* b) const {
        return a->getCode() < b->getCode();
    }
};

/// renomeia o tipo set<Course*, comp> para courseSet, para melhor legibilidade
typedef set<Course*, comp> courseSet;
#endif