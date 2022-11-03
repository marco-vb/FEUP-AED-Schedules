#ifndef STUDENTNEW_H_
#define STUDENTNEW_H_

#include <bits/stdc++.h>
#include "Course.h"
struct comp {
    bool operator()(const Course* a, const Course* b) const {
        return a->getCode() < b->getCode();
    }
};
typedef set<Course*, comp> CourseSet;
using namespace std;

class Student {
    private:
        int number;
        string name;
        set<pair<string, string>> classesPerCourse;

    public:
        explicit Student(int number);
        int getNumber() const;
        string getName() const;
        void setName(string name);
        set<pair<string, string>> getClassesPerCourse() const;
        bool addClassCourse(string const&, string const&, CourseSet*);
        bool removeClassCourse(string const&, string const&, CourseSet*);
};


#endif