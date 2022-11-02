#include <bits/stdc++.h>
#include "headers/Course.h"
#include "headers/Slot.h"
#include "headers/Class.h"
#include "headers/Schedule.h"
#include "headers/Student.h"

using namespace std;

//files
string const& classesCourses = "../files/classes_per_uc.csv";
string const& classesStudents = "../files/students_classes.csv";
string const& classesSlots = "../files/classes.csv";

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

//define sets
typedef set<Student*, studentCompare> studentSet;
typedef set<Class*, classCompare> classSet;
typedef set<Course*, courseCompare> courseSet;


//functions
void readAll(studentSet* students, classSet* classes, courseSet* courses);
void readClasses(classSet* classes, courseSet* courses);
void readStudents(studentSet* students, classSet* classes, courseSet* courses);
void readSlots(studentSet* students, classSet* classes, courseSet* courses);
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
bool compareLessons(Slot& s1, Slot& s2);
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
    readStudents(students, classes, courses);
    readSlots(students, classes, courses);
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
        auto newCourse = new Course(coursecode);
        newCourse->setYear(year);
        auto newClass = new Class(classcode);
        if (courses->find(newCourse) == courses->end())
            courses->insert(newCourse);
        else delete newCourse;

        if (classes->find(newClass) == classes->end())
            classes->insert(newClass);
        else delete newClass;
    }
    cout << "Read Classes Successfully!" << endl;
    cout << "Number of classes: " << classes->size() << endl;
}

void readStudents(studentSet* students, classSet* classes, courseSet* courses) {
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
        ss.ignore();
        getline(ss, name, ',');
        getline(ss, coursecode, ',');
        ss >> classcode;
        auto student = new Student(studentNumber);
        auto student_it = students->find(student);
        if (student_it == students->end()){
            students->insert(student);
            student_it = students->find(student);
        }
        (*student_it)->setName(name);
        (*student_it)->addCourse(coursecode);
        (*student_it)->addClass(classcode);

        for (auto c: *classes) {
            if (c->getCode() == classcode) {
                c->addStudent(studentNumber);
                break;
            }
        }
        for (auto c: *courses) {
            if (c->getCode() == coursecode) {
                c->addStudent(studentNumber);
                break;
            }
        }
    }
    cout << "Read Students Successfully!" << endl;
    cout << "Number of students: " << students->size() << endl;
}

void readSlots(studentSet* students, classSet* classes, courseSet* courses) {
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
        auto class_it = classes->find(new Class(classcode));
        if (class_it != classes->end()) {
            (*class_it)->addSlot(*slot);
            auto students_in_class = (*class_it)->getStudents();
            for (auto s: students_in_class) {
                auto student_it = students->find(new Student(s));
                if (student_it != students->end())
                    (*student_it)->addSlot(*slot);
            }
        }

        auto course_it = courses->find(new Course(coursecode));
        if (course_it != courses->end()) {
            (*course_it)->addSlot(*slot);
            auto students_in_course = (*course_it)->getStudents();
            for (auto s: students_in_course) {
                auto student_it = students->find(new Student(s));
                if (student_it != students->end())
                    (*student_it)->addSlot(*slot);
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
    for (const auto& s : *students)
        cout << s->getNumber() << " " << s->getName() << endl;
}

void listAllClasses(classSet* classes) {
    for (const auto& c : *classes)
        cout << c->getCode() << endl;
}

void listAllCourses(courseSet* courses) {
    for (const auto& c : *courses)
        cout << c->getCode() << " year: " << c->getYear() << endl;
}

void listAllSlots(courseSet* courses) {
    int i1 = 0;
    for (const auto& c : *courses) {
        Schedule courseSchedule = c->getSchedule();
        int i = 0;
        for (auto it = courseSchedule.begin();; it++) {
            cout << i1++ << endl;
            while(it == courseSchedule[i].end() && it != courseSchedule.end()){ i++; it = courseSchedule[i].begin(); }
            if(it == courseSchedule.end()) break;
            Slot s = *it;
            cout << s.getCourseCode() << " " << s.getDay() << " " << s.getStartHour() << " " << s.getEndHour() << " " << s.getType() << endl;
        }
    }
}

void listStudentsInClass(studentSet* students, classSet* classes) {
    string classCode;
    cout << "Enter class code: ";
    cin >> classCode;
    for (const auto& c : *classes) {
        if (c->getCode() == classCode) {
            for (const auto& s : c->getStudents())
                for (const auto& st : *students)
                    if (st->getNumber() == s)
                        cout << st->getNumber() << " " << st->getName() << endl;
        }
    }
}

void listClassesOfStudent(studentSet* students) {
    int studentNumber;
    cout << "Enter student number: ";
    cin >> studentNumber;
    for (const auto& s : *students) {
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
    for (const auto &c: *classes) {
        if (c->getCode() == classCode) {
            auto classSchedule = c->getSchedule();
            int i = 0;
            for (auto it = classSchedule.begin(); it != classSchedule.end(); it++) {
                if (it == classSchedule[i].end()){ i++; it = classSchedule[i].begin(); }
                Slot s = *it;
                cout << s.getDay() << " " << s.getCourseCode() << " " << s.getStartHour() << " " << s.getEndHour()
                     << " " << s.getType() << endl;
            }
        }
    }
}

void listSlotsOfCourse(courseSet* courses) {
    string courseCode;
    cout << "Enter course code: ";
    cin >> courseCode;
    for (const auto &c: *courses) {
        if (c->getCode() == courseCode) {
            auto courseSchedule = c->getSchedule();
            int i = 0;
            for (auto it = courseSchedule.begin(); it != courseSchedule.end(); it++) {
                if (it == courseSchedule[i].end()) {
                    i++;
                    it = courseSchedule[i].begin();
                }
                Slot s = *it;
                cout << s.getDay() << " " << s.getClassCode() << " " << s.getStartHour() << " " << s.getEndHour() << " "
                     << s.getType() << endl;
            }
        }
    }
}



//helpers
bool compareLessons(Slot& s1, Slot& s2) {
    map<string, int> days = { {"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5} };
    if (days[s1.getDay()] == days[s2.getDay()])
        return s1.getStartHour() < s2.getStartHour();
    return days[s1.getDay()] < days[s2.getDay()];
}

void clear() {
    for (int i = 0; i < 50; i++) cout << endl;
}

void wait() {
    int c; do c = getchar(); while ((c != '\n') && (c != EOF));
    cout << "Press ENTER to continue...";
    do{ c = getchar(); }while ((c != '\n') && (c != EOF));
}