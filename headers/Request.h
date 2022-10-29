#ifndef REQUEST_H_
#define REQUEST_H_

#include <set>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include "ClassCourse.h"

using namespace std;

class Request {
private:
    ClassCourse classCourse;
    unsigned int studentNumber;
    string type;

public:
    Request();

};

#endif