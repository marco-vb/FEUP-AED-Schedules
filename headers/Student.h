#ifndef STUDENTNEW_H_
#define STUDENTNEW_H_

#include <bits/stdc++.h>
#include "Course.h"
#include "Class.h"

using namespace std;

/**
 * @brief Classe Student
 *
 * Esta classe é usada para representar um aluno.\n
 * Ela armazena o nome, o número e o horario do aluno.\n
 * Além disso armazena um conjunto de pares de strings.\n
 * Cada par de strings corresponde a uma turma e a uma unidade curricular.\n
 * Este conjunto é usado para armazenar as turmass por unidade curricular que o aluno está inscrito.
 */
class Student {
    private:

        /// O numero interno do aluno
        int number;

        /// O nome do aluno
        string name;

        /**
         * @brief O conjunto de pares de strings (class, course)
         *
         * Este set é usado para armazenar as turmas por unidade curricular que o aluno está inscrito.\n
         * Cada par de strings contem a uma turma(class) e a uma unidade curricular(course).
         */
        set<pair<string, string>> classesPerCourse;

    public:

        /**
         * @brief Construtor da classe Student
         *
         * Este construtor cria um aluno com o número dado.\n
         * Complexidade Temporal: O(1)
         *
         * @param number O número do aluno.\n
         */
        explicit Student(int number);

        /**
         * @brief Retorna o número do aluno
         *
         * Complexidade Temporal: O(1)
         *
         * @return O número do aluno.\n
         */
        int getNumber() const;

        /**
         * @brief Retorna o nome do aluno
         *
         * Complexidade Temporal: O(1)
         *
         * @return O nome do aluno.\n
         */
        string getName() const;

        /**
         * @brief Muda o nome do aluno
         *
         * Complexidade Temporal: O(1)
         *
         * @param name.\n
         */
        void setName(string name);

        /**
         * @brief Retorna o conjunto de pares de strings (class, course)
         *
         * Complexidade Temporal: O(1)
         *
         * @return O conjunto de pares de strings (class, course)
         */
        set<pair<string, string>> getClassesPerCourse() const;

        /**
         * @brief Adiciona um par de strings ao conjunto de pares de strings (class, course)
         *
         * Complexidade Temporal: O(log(N)) onde N é o número de pares de strings no conjunto
         *
         * @param class_ A turma
         * @param course A unidade curricular
         * @param courses O conjunto de todas unidades curriculares
         * @param classes O conjunto de todas turmas
         */
        bool addClassCourse(string const&, string const&, courseSet*, classSet*);

        /**
         * @brief Remove um par de strings do conjunto de pares de strings (class, course)
         *
         * Complexidade Temporal: O(log(N)) onde N é o número de pares de strings no conjunto
         *
         * @param class_ A turma
         * @param course A unidade curricular
         * @param courses O conjunto de todas unidades curriculares
         */
        bool removeClassCourse(string const&, string const&, courseSet*);
};


#endif