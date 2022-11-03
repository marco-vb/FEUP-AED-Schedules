/**
 * @file Functions.h
 * @brief Ficheiro que contém as funções auxiliares a main.cpp
 *
 * Este ficheiro foi criada para que ficheiro main.cpp não fique muito confuso.
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Types.h"
#include "IndependentFunctions.h


//files
string const& classesCourses = "../files/classes_per_uc.csv";
string const& classesStudents = "../files/students_classes.csv";
string const& classesSlots = "../files/classes.csv";

//functions
void menu_full_lists(studentSet*, classSet*, courseSet*);
void menu_partial_lists(studentSet*, classSet*, courseSet*);
void printStudentSchedule(Student*, slotSet*, ostream& = cout);

//functions defined
void readClasses(classSet* classes, courseSet* courses, classCoursesSet* classCourses) {
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
        auto newClassCourse = make_pair(newClass, newCourse);
        classCourses->insert(newClassCourse);
        if (courses->find(newCourse) == courses->end())
            courses->insert(newCourse);

        if (classes->find(newClass) == classes->end())
            classes->insert(newClass);
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
        (*student_it)->addClassCourse(classcode, coursecode);

        auto course = new Course(coursecode);
        auto course_it = courses->find(course);
        if (course_it == courses->end()){
            courses->insert(course);
            course_it = courses->find(course);
        }
        (*course_it)->addStudent(studentNumber);

        auto class_ = new Class(classcode);
        auto class_it = classes->find(class_);
        if (class_it == classes->end()){
            classes->insert(class_);
            class_it = classes->find(class_);
        }
        (*class_it)->addStudent(studentNumber);
    }
    cout << "Read Students Successfully!" << endl;
    cout << "Number of students: " << students->size() << endl;
}

void readSlots(studentSet* students, classSet* classes, courseSet* courses, slotSet* slots) {
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
        slots->insert(slot);
        auto class_it = classes->find(new Class(classcode));
        if (class_it != classes->end()) {
            (*class_it)->addSlot(*slot);
        }

        auto course_it = courses->find(new Course(coursecode));
        if (course_it != courses->end()) {
            (*course_it)->addSlot(*slot);
        }
    }
    cout << "Read Slots Successfully!" << endl;
}

void listAllStudents(studentSet* students) {
    for (const auto& s : *students)
        cout << s->getNumber() << " " << s->getName() << endl;
}

void readAll(studentSet* students, classSet* classes, courseSet* courses, classCoursesSet* classCourses, slotSet* slots) {
    readClasses(classes, courses, classCourses);
    readStudents(students, classes, courses);
    readSlots(students, classes, courses, slots);
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
    for (const auto& c : *courses) {
        Schedule courseSchedule = c->getSchedule();
        //courseSchedule.printSchedule();
        int i = 0;
        for (auto it = courseSchedule.begin();; it++) {
            while(it == courseSchedule[i].end() && it != courseSchedule.end()){
                i++; it = courseSchedule[i].begin();
            }
            if(it == courseSchedule.end()) break;
            Slot s = *it;
            cout << "Course: " << s.getCourseCode() << " - Class: " << s.getClassCode() << " - " << s.getDay() << " " << floatToMinutes(s.getStartHour()) << "-" << floatToMinutes(s.getEndHour()) << " " << s.getType() << endl;
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
            auto studentclasses = s->getClassesPerCourse();
            for (const auto& c : studentclasses)
                cout << c.first << " - " << c.second << endl;
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
            //classSchedule.printSchedule();
            int i = 0;
            for (auto it = classSchedule.begin();; it++) {
                while(it == classSchedule[i].end() && it != classSchedule.end()){ i++; it = classSchedule[i].begin(); }
                if(it == classSchedule.end()) break;
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
            //courseSchedule.printSchedule();
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

void getScheduleOfStudent(studentSet* students, slotSet* slots) {
    int studentNumber;
    cout << "Enter student number: ";
    cin >> studentNumber;
    auto student_it = students->find(new Student(studentNumber));
    printStudentSchedule(*student_it, slots);
}

Schedule getStudentSchedule(Student* student, slotSet* slots){
    Schedule schedule;
    for (auto p: student->getClassesPerCourse()) {
        auto range = slots->equal_range(new Slot("", 0, 0, "", p.second, p.first));
        for(auto it = range.first; it != range.second; it++){
            schedule.addSlot(**it);
        }
    }
    return schedule;
}

void printStudentSchedule(Student* student, slotSet* slots, ostream& out){
    Schedule schedule = getStudentSchedule(student, slots);
    for(int i = 0; i < 6; i++){
        if(!schedule[i].empty())
            out << Schedule::numToWeekDay(i) << ": " << endl;
        for(const Slot& class_: schedule[i])
            out << "    Class: " << class_.getClassCode() << " - Course: " << class_.getCourseCode() << " - "
                << class_.getType() << " - " << class_.getStartHour() << "-" << class_.getEndHour() << endl;
        out << endl;
    }
}

void clear() {
    for (int i = 0; i < 50; i++) cout << endl;
}

void wait() {
    int c; do c = getchar(); while ((c != '\n') && (c != EOF));
    cout << "Press ENTER to continue...";
    do{ c = getchar(); }while ((c != '\n') && (c != EOF));
}

#endif
