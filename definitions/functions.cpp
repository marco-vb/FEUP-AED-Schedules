#include "../headers/functions.h"

string floatToMinutes(float hour) {
    float lessThanOne = hour - ((int) hour);
    int minutes = lessThanOne * 60;
    string min = to_string(minutes);
    if (min.size() == 1)
        min = "0" + min;
    return to_string((int) hour) + ':' + min;
}


