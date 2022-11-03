/**
 * @file IndependentFunctions.h
 * @brief Ficheiro que contém as funções independentes de outras classes
 *
 * Este ficheiro foi criado para evitar dependências circulares.
 */

#ifndef SCHEDULE_INDEPENDENTFUNCTIONS_H
#define SCHEDULE_INDEPENDENTFUNCTIONS_H

#include <string>
#include <map>

using namespace std;

/**
 * @brief Inteiro para dia da semana
 *
 * Função que retorna uma string com o dia da semana correspondente ao inteiro dado.\n
 * Isto é feito usando o map numToWeekDay_.\n
 * Complexidade Temporal: O(1)
 *
 * @param n
 * @return String com o dia da semana
 */
static string numToWeekDay(int n);

/**
 * @brief Dia da semana para inteiro
 *
 * Função que retorna um inteiro com o dia da semana correspondente à string dada.\n
 * Isto é feito usando o map weekDayToNum_,\n
 * Complexidade Temporal: O(1)
 *
 * @param day
 * @return Inteiro que representa o dia da semana
 */
static int weekDayToNum(const string& day);

/**
 * @brief Função que retorna uma string com a hora e minutos num formato que estamos mais habituados
 *
 * Exemplo: 12.5 -> 12:30.\n
 * Complexidade Temporal: O(1)
 */
string floatToMinutes(float hour);

#endif //SCHEDULE_INDEPENDENTFUNCTIONS_H