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

//comparing structs
struct studentCompare {
    bool operator()(StudentNew* a, StudentNew* b) const {
        return a->getNumber() < b->getNumber();
    }
};

struct classCompare {
    bool operator()(Class* a, Class* b) const {
        return a->getCode() < b->getCode();
    }
};

struct courseCompare {
    bool operator()(Course* a, Course* b) const {
        return a->getCode() < b->getCode();
    }
};

//define sets
typedef set<StudentNew*, studentCompare> studentSet;
typedef set<Class*, classCompare> classSet;
typedef set<Course*, courseCompare> courseSet;


//functions
void readAll(studentSet* students, classSet* classes, courseSet* courses);
void readClasses(classSet* classes, courseSet* courses);
void readStudents(studentSet* students, classSet* classes);
void readSlots(classSet* classes, courseSet* courses);
void menu_full_lists(studentSet* students, classSet* classes, courseSet* courses);
void menu_partial_lists(studentSet* students, classSet* classes, courseSet* courses);
void listAllStudents(studentSet* students);
void listAllClasses(classSet* classes);
void listAllCourses(courseSet* courses);
void listAllSlots(courseSet* courses);
void listStudentsInClass(studentSet* students, classSet* classes);
void listClassesOfStudent(studentSet* students);
void listSlotsOfClass(classSet* classes);
void listSlotsOfCourse(courseSet* courses);
bool compareLessons(Slot* a, Slot* b);
void clear();
void wait();



int main() {
    studentSet students;
    classSet classes;
    courseSet courses;

    // Read data from files
    readAll(&students, &classes, &courses);
    cout << fixed << setprecision(1); // print lesson times correctly
    wait();
    int choice;
    do {
        clear();
        cout << "-----------------------------------" << endl;
        cout << "| 1. Full listings                 |" << endl;
        cout << "| 2. Partial listings              |" << endl;
        cout << "| 0. Exit                          |" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Your choice: ";
        cin >> choice;
        if (choice != 0) {
            switch (choice) {
                case 1: menu_full_lists(&students, &classes, &courses); break;
                case 2: menu_partial_lists(&students, &classes, &courses); break;
                default: cout << "Invalid choice!" << endl;
            }
        }
    } while (choice != 0);
    return 0;
}

void readAll(studentSet* students, classSet* classes, courseSet* courses) {
    readClasses(classes, courses);
    readStudents(students, classes);
    readSlots(classes, courses);
}

void readClasses(classSet* classes, courseSet* courses) {
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

void readStudents(studentSet* students, classSet* classes) {
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

void readSlots(classSet* classes, courseSet* courses) {
    ifstream slotsFile(classesSlots);
    string line;
    getline(slotsFile, line); // skip first line
    while (getline(slotsFile, line)) {
        stringstream ss(line);
        string classcode, coursecode, day, type;
        float start, end;
        getline(ss, classcode, ',');
        getline(ss, coursecode, ',');
        getline(ss, day, ',');
        ss >> start;
        ss.ignore();
        ss >> end; end += start;
        ss.ignore();
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

void menu_full_lists(studentSet* students, classSet* classes, courseSet* courses) {
    int choice;
    do {
        clear();
        cout << "-----------------------------------" << endl;
        cout << "| 1. List all students             |" << endl;
        cout << "| 2. List all classes              |" << endl;
        cout << "| 3. List all courses              |" << endl;
        cout << "| 4. List all lessons              |" << endl;
        cout << "| 0. Back                          |" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Your choice: ";
        cin >> choice;
        if (choice != 0) {
            switch (choice) {
                case 1: listAllStudents(students); wait(); break;
                case 2: listAllClasses(classes); wait(); break;
                case 3: listAllCourses(courses); wait(); break;
                case 4: listAllSlots(courses); wait(); break;
                default: cout << "Invalid choice!" << endl;
            }
        }
    } while (choice != 0);
}

void menu_partial_lists(studentSet* students, classSet* classes, courseSet* courses) {
    int choice;
    do {
        clear();
        cout << "-----------------------------------" << endl;
        cout << "| 1. List all students in a class  |" << endl;
        cout << "| 2. List all classes of a student |" << endl;
        cout << "| 3. List all lessons of a class   |" << endl;
        cout << "| 4. List all lessons of a course  |" << endl;
        cout << "| 0. Back                          |" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Your choice: ";
        cin >> choice;
        if (choice != 0) {
            switch (choice) {
                case 1: listStudentsInClass(students, classes); wait(); break;
                case 2: listClassesOfStudent(students); wait(); break;
                case 3: listSlotsOfClass(classes); wait(); break;
                case 4: listSlotsOfCourse(courses); wait(); break;
                default: cout << "Invalid choice!" << endl;
            }
        }
    } while (choice != 0);
}

void listAllStudents(studentSet* students) {
    for (auto s : *students)
        cout << s->getNumber() << " " << s->getName() << endl;
}

void listAllClasses(classSet* classes) {
    for (auto c : *classes)
        cout << c->getCode() << endl;
}

void listAllCourses(courseSet* courses) {
    for (auto c : *courses)
        cout << c->getCode() << " year: " << c->getYear() << endl;
}

void listAllSlots(courseSet* courses) {
    for (auto c : *courses) {
        Schedule courseSchedule = c->getSchedule();
        auto v = courseSchedule.getSchedule();
        sort(v.begin(), v.end(), compareLessons);
        for (auto s : courseSchedule.getSchedule())
            cout << c->getCode() << " " << s->getDay() << " " << s->getStartHour() << " " << s->getEndHour() << " " << s->getType() << endl;
    }
}

void listStudentsInClass(studentSet* students, classSet* classes) {
    string classCode;
    cout << "Enter class code: ";
    cin >> classCode;
    for (auto c : *classes) {
        if (c->getCode() == classCode) {
            //(*it)->listStudents();
        }
    }
}

void listClassesOfStudent(studentSet* students) {
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

void listSlotsOfClass(classSet* classes) {
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

void listSlotsOfCourse(courseSet* courses) {
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

void clear() {
    for (int i = 0; i < 50; i++) cout << endl;
}

void wait() {
    int c; do c = getchar(); while ((c != '\n') && (c != EOF));
    cout << "Press ENTER to continue...";
    do c = getchar(); while ((c != '\n') && (c != EOF));
}