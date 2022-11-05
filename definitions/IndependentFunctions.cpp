
#include "../headers/IndependentFunctions.h"

/// Map que associa um inteiro a um dia da semana
const map<int, string> numToWeekDay_ = {{0, "Monday"}, {1, "Tuesday"}, {2, "Wednesday"},
                                                  {3, "Thursday"}, {4, "Friday"}, {5, "Saturday"}};

/// Map que associa um dia da semana a um inteiro
const map<string, int> weekDayToNum_ = {{"Monday", 0}, {"Tuesday", 1}, {"Wednesday", 2},
                                                  {"Thursday", 3}, {"Friday", 4}, {"Saturday", 5}};

string numToWeekDay(int n){
    return numToWeekDay_.at(n);
}

int weekDayToNum(const string& day){
    return weekDayToNum_.at(day);
}

string floatToMinutes(float hour) {
    float lessThanOne = hour - ((int) hour);
    int minutes = lessThanOne * 60;
    string min = to_string(minutes);
    if (min.size() == 1)
        min = "0" + min;
    return to_string((int) hour) + ':' + min;
}