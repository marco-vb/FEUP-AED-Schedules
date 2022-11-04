/**
 * @file Functions.h
 * @brief Ficheiro que contém as funções auxiliares a main.cpp
 *
 * Este ficheiro foi criada para que ficheiro main.cpp não fique muito confuso.
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Types.h"
#include "IndependentFunctions.h"


//files
string const& classesCourses = "../files/classes_per_uc.csv";
string const& classesStudents = "../files/students_classes.csv";
string const& classesSlots = "../files/classes.csv";

//functions
void menu_full_lists(studentSet*, classSet*, courseSet*);
void menu_partial_lists(studentSet*, classSet*, courseSet*, classCoursesSet*, slotSet*);
void printStudentSchedule(Student*, slotSet*, ostream& = cout);
void menu_schedules(studentSet*, classSet*, courseSet*, classCoursesSet*, slotSet*);
void menu_requests(studentSet*, classSet*, courseSet*, classCoursesSet*, slotSet*);
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
        if (courses->find(newCourse) == courses->end())
            courses->insert(newCourse);

        if (classes->find(newClass) == classes->end())
            classes->insert(newClass);

        auto newClassCourse = new classCourse {classcode, coursecode, 0};
        classCourses->insert(newClassCourse);
    }
    cout << "Read Classes Successfully!" << endl;
    cout << "Number of classes: " << classes->size() << endl;
}

void readStudents(studentSet* students, classSet* classes, courseSet* courses, classCoursesSet* classCourses) {
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
        (*student_it)->addClassCourse(classcode, coursecode, courses, classes);

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

        for (auto classCourse : *classCourses) {
            if (classCourse->class_ == classcode && classCourse->course == coursecode) {
                classCourse->students++;
                break;
            }
        }
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


void readAll(studentSet* students, classSet* classes, courseSet* courses, classCoursesSet* classCourses, slotSet* slots) {
    readClasses(classes, courses, classCourses);
    readStudents(students, classes, courses, classCourses);
    readSlots(students, classes, courses, slots);
}


void listAllStudents(studentSet* students) {
    cout << "Ordenação (1) por número de aluno ou (2) por nome? ";
    int choice;
    cin >> choice;
    if (choice != 1 && choice != 2) {
        cout << "Opção inválida!" << endl;
        return;
    }
    if (choice == 1) {
        for (auto student: *students)
            cout << student->getNumber() << " - " << student->getName() << endl;
        return;
    }
    vector<Student*> studentsVector(students->begin(), students->end());
    sort(studentsVector.begin(), studentsVector.end(), [](Student* a, Student* b) { return a->getName() < b->getName(); });
    for (const auto& s : studentsVector) {
        cout << s->getNumber() << " " << s->getName() << endl;
    }
}



void listAllClasses(classSet* classes) {
    auto it = classes->begin();
    while (it != classes->end()) {
        int year = (*it)->getCode()[0] - '0';
        cout << "Ano " << year << endl;
        cout << "----------------" << endl;
        while (it != classes->end() && (*it)->getCode()[0] - '0' == year) {
            cout << (*it)->getCode() << endl;
            it++;
        }
        cout << endl;
    }
}

void listAllCourses(courseSet* courses) {
    auto it = courses->begin();
    while (it != courses->end()) {
        int year = (*it)->getYear();
        cout << "Ano " << year << endl;
        cout << "----------------" << endl;
        while (it != courses->end() && (*it)->getYear() == year) {
            cout << (*it)->getCode() << endl;
            it++;
        }
        cout << endl;
    }
}

void listAllSlots(courseSet* courses) {
    for (const auto& c : *courses) {
        auto courseSchedule = c->getSchedule().getSchedule();
        cout << c->getCode() << endl;
        cout << "----------------" << endl;
        for (const auto& s : courseSchedule) {
            for (const auto& slot : s) {
                cout << slot.getDay() << " " << slot.getClassCode() << " " << slot.getStartHour() << " " << slot.getEndHour() << " " << slot.getType() << endl;
            }
        }
        cout << endl;
    }
}

void listClassCourseOccupation(classCoursesSet* classCourses) {
    auto it = classCourses->begin();
    while (it != classCourses->end()) {
        string coursecode = (*it)->course;
        cout << coursecode << endl;
        cout << "----------------" << endl;
        while (it != classCourses->end() && (*it)->course == coursecode) {
            cout << (*it)->class_ << " " << (*it)->students << endl;
            it++;
        }
        cout << endl;
    }
}

void listStudentsInClassCourse(studentSet* students, classSet* classes, courseSet* courses) {
    cout << "Turma: ";
    string classcode;
    cin >> classcode;
    cout << "Unidade Curricular: ";
    string coursecode;
    cin >> coursecode;
    auto class_it = classes->find(new Class(classcode));
    if (class_it == classes->end()) {
        cout << "Turma não encontrada!" << endl;
        return;
    }
    auto course_it = courses->find(new Course(coursecode));
    if (course_it == courses->end()) {
        cout << "Unidade Curricular não encontrada!" << endl;
        return;
    }
    auto classStudents = (*class_it)->getStudents();
    auto courseStudents = (*course_it)->getStudents();
    vector<int> s;
    set_intersection(classStudents.begin(), classStudents.end(), courseStudents.begin(), courseStudents.end(), back_inserter(s));
    for (const auto& n : s) {
        auto student_it = students->find(new Student(n));
        cout << (*student_it)->getNumber() << " " << (*student_it)->getName() << endl;
    }
}

void listStudentsInCourse(studentSet* students, courseSet* courses) {
    cout << "Unidade Curricular: ";
    string coursecode;
    cin >> coursecode;
    auto course_it = courses->find(new Course(coursecode));
    if (course_it == courses->end()) {
        cout << "Unidade Curricular não encontrada!" << endl;
        return;
    }
    auto courseStudents = (*course_it)->getStudents();
    for (const auto& n : courseStudents) {
        auto student_it = students->find(new Student(n));
        cout << (*student_it)->getNumber() << " " << (*student_it)->getName() << endl;
    }
}


void listStudentsInClass(studentSet* students, classSet* classes) {
    string classCode;
    cout << "Turma: ";
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
    cout << "Número de estudante: ";
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
    cout << "Turma: ";
    cin >> classCode;
    auto it = classes->find(new Class(classCode));
    if (it != classes->end()) {
        auto slotVector = (*it)->getSchedule().getSchedule();
        cout << (*it)->getCode() << endl;
        cout << "----------------" << endl;
        for (const auto& s : slotVector) {
            for (const auto& slot : s) {
                cout << slot.getDay() << " " << slot.getStartHour() << " " << slot.getEndHour() << " " << slot.getType() << endl;
            }
        }
        cout << endl;
    }
}

void listSlotsOfCourse(courseSet* courses) {
    string courseCode;
    cout << "Unidade Curricular: ";
    cin >> courseCode;
    auto it = courses->find(new Course(courseCode));
    if (it != courses->end()) {
        courseSet aux = {*it};
        listAllSlots(&aux);
    }
}

void getScheduleOfStudent(studentSet* students, slotSet* slots) {
    int studentNumber;
    cout << "Número de estudante: ";
    cin >> studentNumber;
    auto student_it = students->find(new Student(studentNumber));
    printStudentSchedule(*student_it, slots);
}

Schedule getStudentSchedule(Student* student, slotSet* slots){
    Schedule schedule;
    for (const auto& p: student->getClassesPerCourse()) {
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
            out << numToWeekDay(i) << ": " << endl;
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
