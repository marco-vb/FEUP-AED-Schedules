#ifndef SLOT_H_
#define SLOT_H_

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Classe Slot
 *
 * Esta classe representa um slot no horário, ou seja uma aula.\n
 * Ela armazena o dia da semana, a hora de inicio, a hora de fim, o tipo, o nome da turma e o nome da unidade curricular.\n
 */
class Slot {
    private:

        /// String com o dia da semana
        string day;

        /// Float com a hora de inicio
        float startHour;

        /// Float com a hora de fim
        float endHour;

        /// String com o tipo ("T", "TP", "PL")
        string type;

        /// String com o nome da unidade curricular (exempplo "LEIC001")
        string coursecode;

        /// String com o nome da turma (exemplo "1LEIC01")
        string classcode;

    public:

        /**
         * @brief Construtor da classe Slot
         *
         * Este construtor cria um slot vazio.\n
         * Complexidade Temporal: O(1)
         */
        Slot();

        /**
         * @brief Construtor de cópia da classe Slot
         *
         * Este construtor cria um slot com os mesmos atributos do slot passado por argumento.\n
         * Complexidade Temporal: O(1)
         * @param slot
         */
        Slot(const Slot& slot);

        /**
         * @brief Construtor da classe Slot
         *
         * Este construtor cria um slot com os atributos passados por argumento.\n
         * Complexidade Temporal: O(1)
         *
         * @param day String com o dia da semana
         * @param startHour Float com a hora de inicio
         * @param endHour Float com a hora de fim
         * @param type String com o tipo ("T", "TP", "PL")
         * @param coursecode String com o nome da unidade curricular (exempplo "LEIC001")
         * @param classcode String com o nome da turma (exemplo "1LEIC01")
         */
        Slot(string day, float startHour, float endHour, string type, string coursecode, string classcode);

        /**
         * @brief Retorna o dia da semana
         *
         * Função que retorna o dia da semana do slot.\n
         * Complexidade Temporal: O(1)
         *
         * @return String com o dia da semana
         */
        string getDay() const;

        /**
         * @brief Retorna a hora de inicio
         *
         * Função que retorna a hora de inicio do slot.\n
         * Complexidade Temporal: O(1)
         *
         * @return Float com a hora de inicio
         */
        float getStartHour() const;

        /**
         * @brief Retorna a hora de fim
         *
         * Função que retorna a hora de fim do slot.\n
         * Complexidade Temporal: O(1)
         *
         * @return Float com a hora de fim
         */
        float getEndHour() const;

        /**
         * @brief Retorna o tipo
         *
         * Função que retorna o tipo do slot.\n
         * Complexidade Temporal: O(1)
         *
         * @return String com o tipo
         */
        string getType() const;

        /**
         * @brief Retorna o nome da unidade curricular
         *
         * Função que retorna o nome da unidade curricular do slot.\n
         * Complexidade Temporal: O(1)
         *
         * @return String com o nome da unidade curricular
         */
        string getCourseCode() const;

        /**
         * @brief Retorna o nome da turma
         *
         * Função que retorna o nome da turma do slot.\n
         * Complexidade Temporal: O(1)
         *
         * @return String com o nome da turma
         */
        string getClassCode() const;

        /**
         * @brief Operador <
         *
         * Função que determina se .\n
         * @param slot
         * @return
         */
        bool operator<(const Slot& slot) const;
};

#endif