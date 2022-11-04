#ifndef CLASS_H_
#define CLASS_H_

#include "Schedule.h"
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Classe que representa uma turma
 *
 */
class Class {
    private:
        /// Código da turma (exemplo: "LEIC001")
        string code;

        /// Numero de estudantes da turma
        unsigned short numStudents;

        /// Numero Maximo de estudantes da turma
        static unsigned short  maxStudents;

        /// Horario da turma
        Schedule schedule;

        /// Conjunto de estudantes da turma, ordenados por ordem crescenete de numero de estudante
        set<int> students;  // set of student by id number

    public:

        /**
         * @brief Construtor da classe
         *
         * Complexidade Temporal: O(1)
         *
         * @param code Código da turma
         */
        explicit Class(string code);

        /**
         * @brief Retorna o código da turma
         *
         * Complexidade Temporal: O(1)
         *
         * @return O código da turma
         */
        string getCode() const;

        /**
         * @brief Retorna o horario da turma
         *
         * Complexidade Temporal: O(1)
         *
         * @return O horario da turma
         */
        Schedule getSchedule() const;

        /**
         * @brief Adiciona uma aula ao horario da turma
         *
         * Função que adiciona um slot ao horario da turma através da função addSlot() da classe Schedule.\n
         * Complexidade Temporal: O(logN) onde N é o número máximo de aulas de um dia
         *
         * @param slot
         * @return true se a aula foi adicionada com sucesso e false caso contrário
         */
        bool addSlot(Slot slot);

        /**
         * @brief retorna o set com todos os estudantes da turma
         *
         * Complexidade Temporal: O(1)
         *
         * @return Set de estudantes
         */
        set<int> getStudents() const;

        /**
        * @brief Limpa o horario da turma
        *
        * Função que limpa o horario da turma atraves da do metodo clearSchedule da classe Schedule.\n
        * Complexidade Temporal: O(N) onde N é o número de aulas no horario
        */
        void clearSchedule();

        /**
         * @brief Adiciona um estudante à turma
         *
         * Função que adiciona um estudante à turma, verificando se o número de estudantes não excede o máximo.\n
         * Complexidade Temporal: O(logN) onde N é o número de estudantes na turma
         *
         * @param studentNumber O id do estudante a adicionar
         * @return true se o estudante foi adicionado com sucesso e false caso contrário
         */
        bool addStudent(int studentNumber);

        /**
         * @brief Remove um estudante da turma
         *
         * Função que remove um estudante da turma, verificando se o estudante existe.\n
         * Complexidade Temporal: O(logN) onde N é o número de estudantes na turma
         *
         * @param studentNumber O id do estudante a remover
         * @return true se o estudante foi removido com sucesso e false caso contrário
         */
        bool removeStudent(int studentNumber);
};

/// Compara duas turmas pelo seu código
struct classCompare {
    /**
     * @brief Função que compara duas turmas
     *
     * Função que compara duas turmas através do código da turma.\n
     * Complexidade Temporal: O(1)
     *
     * @param a Primeira turma a comparar
     * @param b Segunda turma a comparar
     * @return true se o código da primeira turma for menor que o código da segunda e false caso contrário
     */
    bool operator()(const Class* a, const Class* b) const {
        return a->getCode() < b->getCode();
    }
};

/// renomeia o tipo set<Class*, classCompare> para classSet, para melhor legibilidade
typedef set<Class*, classCompare> classSet;

#endif