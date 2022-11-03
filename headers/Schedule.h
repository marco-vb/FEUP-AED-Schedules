#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <bits/stdc++.h>
#include "Slot.h"

using namespace std;

/**
 * @brief A classe Schedule
 * Esta classe é usada para representar um horariode uma semana
 * Este armazena um conjunto de slots
 * Um slot corresponde a uma aula
 * Pode ser usada para representar um horario de um aluno, de uma turma, de uma unidade curricular, etc.
 */
class Schedule {
    private:
    
        /**
         * @brief O vetor de sets de slots
         * Este vetor é usado para armazenar os slots do horario
         * É aqui que está armazenada a informação sobre o horario
         * O vetor terá 6 posições, uma para cada dia da semana, exceto para o domingo
         * Cada dia da semana é representado por um set de slots
         * O tamanho vetor terá que ser constante e igual a 6
         */
        vector<set<Slot>> schedule;
        
        /// Map que associa um inteiro a um dia da semana
        static const map<int, string> numToWeekDay_;
        
        /// Map que associa um dia da semana a um inteiro
        static const map<string, int> weekDayToNum_;

    public:
    
        /**
         * @brief Construtor da classe Schedule
         * Este construtor cria um horario vazio
         * Complexidade Temporal: O(1)
         */
        Schedule();
        
        /**
         * @brief Retorna o vetor
         * Função que retorna o vetor de sets de slots onde está armazenada a informação sobre o horario
         * @return O vetor de sets de slots
         * Complexidade Temporal: O(1)
         */
        vector<set<Slot>> getSchedule() const;
        
        /**
         * @brief Limpa o horario
         * Função que limpa o horario, ou seja, usa a função clear() em cada set do vetor
         * O(N) onde N é o número de aulas no horario
         */
        void clearSchedule();
        
        /**
         * @brief Adiciona um slot ao horario
         * Função que adiciona um slot ao horario, adicionando-o ao set correspondente ao dia da semana, representado por uma posição no vetor
         * @param Slot O slot a adicionar
         * @return true se o slot foi adicionado, false caso contrário
         * Complexidade Temporal: O(logN) onde N é o número máximo de aulas de um dia
         */
        bool addSlot(Slot slot);
        
        /**
         * @brief Verifica se existe colisão entre o slot dado e os slots do horario
         * Função que verifica se existe colisão entre um slot e os slots já existentes no horario
         * Para isso percorre todas as aulas do dia da semana e verifica se existe colisão
         * @param Slot O slot a verificar
         * @return true se existe colisão, false caso contrário
         * Complexidade Temporal: O(N) onde N é o número máximo de aulas de um dia
         */
        bool checkForCollision(Slot slot);
        
        /**
         * @brief Operador []
         * Função que retorna o set de slots correspondente ao dia da semana dado
         * @param n O dia da semana em formato de inteiro
         * @return O set de slots correspondente ao dia da semana dado
         * Complexidade Temporal: O(1)
         */
        set<Slot>& operator[] (int n);
        
        /**
         * @brief Operador []
         * Função que retorna o set de slots correspondente ao dia da semana dado
         * @param n O dia da semana em formato de string
         * @return O set de slots correspondente ao dia da semana dado
         * Complexidade Temporal: O(1)
         */
        set<Slot>& operator[] (string day);
        
        /**
         * @brief Begin do horario
         * @return  O iterador para o primeiro slot do horario, ou seja, o primeiro slot do primeiro dia da semana
         * Complexidade Temporal: O(1)
         */
        set<Slot>::iterator begin();
        
        /**
         * @brief End do horario
         * @return O iterador para o último slot do horario, ou seja, o último slot do último dia da semana
         * Complexidade Temporal: O(1)
         */
        set<Slot>::iterator end();
        
        /**
         * @brief Inteiro para dia da semana
         * Função que retorna uma string com o dia da semana correspondente ao inteiro dado
         * Isto é feito usando o map numToWeekDay_
         * @param n 
         * @return String com o dia da semana
         */
        static string numToWeekDay(int n);
        
        /**
         * @brief Dia da semana para inteiro
         * Função que retorna um inteiro com o dia da semana correspondente à string dada
         * Isto é feito usando o map weekDayToNum_
         * @param day
         * @return Inteiro que representa o dia da semana
         */
        static int weekDayToNum(string day);
};

#endif
