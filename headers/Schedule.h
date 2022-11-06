#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <bits/stdc++.h>
#include "Slot.h"
#include "IndependentFunctions.h"

using namespace std;

/**
 * @brief Classe que guarda um horario
 *
 * Esta classe é usada para representar um horario de uma semana.\n
 * Este armazena um conjunto de slots.\n
 * Um slot corresponde a uma aula.\n
 * Pode ser usada para representar um horario de um aluno, de uma turma, de uma unidade curricular, etc.
 */
class Schedule {
    private:
    
        /**
         * @brief O vetor de sets de slots
         *
         * Este vetor é usado para armazenar os slots do horario.\n
         * É aqui que está armazenada a informação sobre o horario.\n
         * O vetor terá 6 posições, uma para cada dia da semana, exceto para o domingo.\n
         * Cada dia da semana é representado por um set de slots.\n
         * O tamanho vetor terá que ser constante e igual a 6.\n
         */
        vector<set<Slot>> schedule;

    public:
    
        /**
         * @brief Construtor da classe Schedule
         *
         * Este construtor cria um horario vazio.\n
         * Complexidade Temporal: O(1)
         */
        Schedule();
        
        /**
         * @brief Retorna o vetor
         *
         * Função que retorna o vetor de sets de slots onde está armazenada a informação sobre o horario.\n
         * Complexidade Temporal: O(1)
         *
         * @return O vetor de sets de slots
         */
        vector<set<Slot>> getSchedule() const;
        
        /**
         * @brief Limpa o horario
         *
         * Função que limpa o horario, ou seja, usa a função clear() em cada set do vetor.\n
         * Complexidade Temporal: O(N) onde N é o número de aulas no horario
         */
        void clearSchedule();
        
        /**
         * @brief Adiciona um slot ao horario
         *
         * Função que adiciona um slot ao horario, adicionando-o ao set correspondente ao dia da semana, representado por uma posição no vetor.\n
         * Complexidade Temporal: O(logN) onde N é o número máximo de aulas de um dia
         *
         * @param Slot O slot a adicionar
         * @return true se o slot foi adicionado, false caso contrário
         */
        bool addSlot(const Slot& slot);
        
        /**
         * @brief Verifica se existe colisão entre o slot dado e os slots do horario
         *
         * Função que verifica se existe colisão entre um slot e os slots já existentes no horario.\n
         * Para isso percorre todas as aulas do dia da semana e verifica se existe colisão.\n
         * Complexidade Temporal: O(N) onde N é o número máximo de aulas de um dia
         *
         * @param Slot O slot a verificar
         * @return true se existe colisão, false caso contrário
         */
        bool checkForCollision(const Slot& slot);
        
        /**
         * @brief Operador []
         *
         * Função que retorna o set de slots correspondente ao dia da semana dado.\n
         * Complexidade Temporal: O(1)
         *
         * @param n O dia da semana em formato de inteiro
         * @return O set de slots correspondente ao dia da semana dado
         */
        set<Slot>& operator[] (int n);
        
        /**
         * @brief Operador []
         *
         * Função que retorna o set de slots correspondente ao dia da semana dado.\n
         * Complexidade Temporal: O(1)
         *
         * @param n O dia da semana em formato de string
         * @return O set de slots correspondente ao dia da semana dado
         */
        set<Slot>& operator[] (const string& day);
        
        /**
         * @brief Begin do horario
         *
         * Complexidade Temporal: O(1)
         *
         * @return  O iterador para o primeiro slot do horario, ou seja, o primeiro slot do primeiro dia da semana
         */
        set<Slot>::iterator begin();
        
        /**
         * @brief End do horario
         *
         * Complexidade Temporal: O(1)
         *
         * @return O iterador para o último slot do horario, ou seja, o último slot do último dia da semana
         */
        set<Slot>::iterator end();

};

#endif
