#include <bits/stdc++.h>
#include "headers/Course.h"
#include "headers/Slot.h"
#include "headers/Class.h"
#include "headers/Schedule.h"
#include "headers/StudentNew.h"

using namespace std;

//files
string const& classesCourses = "../files/classes_per_uc.csv";
string const& classesStudents = "../files/students_classes.csv";
string const& classesSlots = "../files/classes.csv";

//functions
void readAll(set<StudentNew*>* students, set<Class*>* classes, set<Course*>* courses);
void readClasses(set<Class*>* classes, set<Course*>* courses);
void readStudents(set<StudentNew*>* students, set<Class*>* classes);
void readSlots(set<Class*>* classes, set<Course*>* courses);
void listAllStudents(set<StudentNew*>* students);
void listAllClasses(set<Class*>* classes);
void listAllCourses(set<Course*>* courses);
void listAllSlots(set<Class*>* classes);
void listStudentsInClass(set<StudentNew*>* students, set<Class*>* classes);
void listClassesOfStudent(set<StudentNew*>* students);
void listSlotsOfClass(set<Class*>* classes);
void listSlotsOfCourse(set<Course*>* courses);
void clear() {cout << "\x1B[2J\x1B[H";}



int main() {
    set<StudentNew*> students; auto students_ptr = &students;
    set<Class*> classes; auto classes_ptr = &classes;
    set<Course*> courses; auto courses_ptr = &courses;

    // Read data from files
    readAll(students_ptr, classes_ptr, courses_ptr);

    int choice;
    do {
        clear();
        cout << "-----------------------------------" << endl;
        cout << "| 1. List all students             |" << endl;
        cout << "| 2. List all classes              |" << endl;
        cout << "| 3. List all courses              |" << endl;
        cout << "| 4. List all slots                |" << endl;
        cout << "| 5. List all students in a class  |" << endl;
        cout << "| 6. List all classes of a student |" << endl;
        cout << "| 7. List all slots of a class     |" << endl;
        cout << "| 8. List all slots of a course    |" << endl;
        cout << "| 0. Exit                          |" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Your choice: ";
        cin >> choice;
        if (choice != 0) {
            switch (choice) {
                case 1: listAllStudents(&students); break;
                case 2: listAllClasses(&classes); break;
                case 3: listAllCourses(&courses); break;
                case 4: listAllSlots(&classes); break;
                case 5: listStudentsInClass(&students, &classes); break;
                case 6: listClassesOfStudent(&students); break;
                case 7: listSlotsOfClass(&classes); break;
                case 8: listSlotsOfCourse(&courses); break;
                default: cout << "Invalid choice!" << endl;
            }
        }
    } while (choice != 0);
    return 0;
}

void readAll(set<StudentNew*>* students, set<Class*>* classes, set<Course*>* courses) {
    readClasses(classes, courses);
    readStudents(students, classes);
    readSlots(classes, courses);
}

void readClasses(set<Class*>* classes, set<Course*>* courses) {
    ifstream classesFile(classesCourses);
    string line;
    getline(classesFile, line); // skip first line
    while (getline(classesFile, line)) {
        stringstream ss(line);
        string coursecode;
        string classcode;
        int year;
        getline(ss, coursecode, ',');
        ss >> classcode;
        year = classcode[0] - '0';
        auto newCourse = new Course(coursecode, year);
        auto newClass = new Class(classcode);
        courses->insert(newCourse);
        classes->insert(newClass);
    }
    cout << "Read Classes Successfully!" << endl;
    cout << "Number of classes: " << classes->size() << endl;
}

void readStudents(set<StudentNew*>* students, set<Class*>* classes) {
    ifstream studentsFile(classesStudents);
    string line;
    getline(studentsFile, line); // skip first line
    while (getline(studentsFile, line)) {
        stringstream ss(line);
        int studentNumber;
        string name;
        string coursecode;
        string classcode;
        ss >> studentNumber;
        getline(ss, name, ',');
        getline(ss, coursecode, ',');
        ss >> classcode;
        auto newStudent = new StudentNew(studentNumber, name);
        if (students->find(newStudent) == students->end()) {
            newStudent->addClass(classcode);
            students->insert(newStudent);
        } else delete newStudent;
    }
    cout << "Read Students Successfully!" << endl;
    cout << "Number of students: " << students->size() << endl;
}

void readSlots(set<Class*>* classes, set<Course*>* courses) {
    ifstream slotsFile(classesSlots);
    string line;
    getline(slotsFile, line); // skip first line
    while (getline(slotsFile, line)) {
        stringstream ss(line);
        string classcode, coursecode, day, type;
        int start, end;
        getline(ss, classcode, ',');
        getline(ss, coursecode, ',');
        getline(ss, day, ',');
        ss >> start;
        ss.ignore();
        ss >> end;
        ss >> type;

        auto slot = new Slot(day, start, end, type, coursecode, classcode);
        for (auto c : *classes) {
            if (c->getCode() == classcode) {
                c->addSlot(slot);
            }
        }
        for (auto c : *courses) {
            if (c->getCode() == coursecode) {
                c->addSlot(slot);
            }
        }
    }
    cout << "Read Slots Successfully!" << endl;
}

void listAllStudents(set<StudentNew*>* students) {
    for (auto s : *students)
        cout << s->getNumber() << " " << s->getName() << endl;
}

void listAllClasses(set<Class*>* classes) {
    for (auto c : *classes)
        cout << c->getCode() << endl;
}

void listAllCourses(set<Course*>* courses) {
    for (auto c : *courses)
        cout << c->getCode() << " " << c->getYear() << endl;
}

void listAllSlots(set<Class*>* classes) {
    for (auto c : *classes) {
        cout << c->getCode() << endl;
        //c->listSlots();
    }
}

void listStudentsInClass(set<StudentNew*>* students, set<Class*>* classes) {
    string classCode;
    cout << "Enter class code: ";
    cin >> classCode;
    for (auto c : *classes) {
        if (c->getCode() == classCode) {
            //(*it)->listStudents();
        }
    }
}

void listClassesOfStudent(set<StudentNew*>* students) {
    int studentNumber;
    cout << "Enter student number: ";
    cin >> studentNumber;
    for (auto s : *students) {
        if (s->getNumber() == studentNumber) {
            auto studentclasses = s->getClasses();
            for (const auto& c : studentclasses)
                cout << c << endl;
        }
    }
}

void listSlotsOfClass(set<Class*>* classes) {
    string classCode;
    cout << "Enter class code: ";
    cin >> classCode;
    for (auto c : *classes) {
        if (c->getCode() == classCode) {
            auto classSchedule = c->getSchedule();
            for (auto s : classSchedule.getSchedule())
                cout << s->getDay() << " " << s->getCourseCode() << " " << s->getStartHour() << " " << s->getEndHour() << " " << s->getType() << endl;
        }
    }
}

void listSlotsOfCourse(set<Course*>* courses) {
    string courseCode;
    cout << "Enter course code: ";
    cin >> courseCode;
    for (auto c : *courses) {
        if (c->getCode() == courseCode) {
            auto courseSchedule = c->getSchedule();
            for (auto s : courseSchedule.getSchedule())
                cout << s->getDay() << " " << s->getClassCode() << " " << s->getStartHour()<< " " << s->getEndHour() << " " << s->getType() << endl;
        }
    }
}