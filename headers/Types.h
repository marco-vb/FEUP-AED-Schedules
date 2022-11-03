#ifndef TYPES_H
#define TYPES_H

#include <bits/stdc++.h>
#include "Student.h"
#include "Course.h"
#include "Class.h"

using namespace std;
//comparing structs
//order students by number
struct studentCompare {
    bool operator()(const Student* a, const Student* b) const {
        return a->getNumber() < b->getNumber();
    }
};
//order classes by code
struct classCompare {
    bool operator()(const Class* a, const Class* b) const {
        return a->getCode() < b->getCode();
    }
};
//order courses by code
struct courseCompare {
    bool operator()(const Course* a, const Course* b) const {
        return a->getCode() < b->getCode();
    }
};
//order courses by code
struct classCourseCompare {
    bool operator()(const pair<Class *, Course *> a, const pair<Class *, Course *> b) const {
        return (a.first->getCode() < b.first->getCode()) ||
               (a.first->getCode() == b.first->getCode() && a.second->getCode() < b.second->getCode());
    }
};

struct slotCompare{
    bool operator()(const Slot* a, const Slot* b) const {
        return a->getClassCode() < b->getClassCode() ||
               (a->getClassCode() == b->getClassCode() && a->getCourseCode() < b->getCourseCode());
    }
};

//define sets
typedef set<Student*, studentCompare> studentSet;
typedef set<Class*, classCompare> classSet;
typedef set<Course*, courseCompare> courseSet;
typedef set<pair<Class*, Course*>, classCourseCompare > classCoursesSet;
typedef multiset<Slot*, slotCompare> slotSet;

#endif
