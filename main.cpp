#include "headers/Functions.h"

int main() {
    studentSet students;
    classSet classes;
    courseSet courses;
    classCoursesSet classCourses;
    slotSet slots;

    // Read data from files
    readAll(&students, &classes, &courses, &classCourses, &slots);
    cout << fixed << setprecision(1); // print lesson times correctly
    wait();
    int choice;
    do {
        clear();
        cout << "------------------------------------" << endl;
        cout << "| 1. Full listings                 |" << endl;
        cout << "| 2. Partial listings              |" << endl;
        cout << "| 3. Make request                  |" << endl;
        cout << "| 4. Student Schedule              |" << endl;
        cout << "| 0. Exit                          |" << endl;
        cout << "------------------------------------" << endl;
        cout << "Your choice: ";
        cin >> choice;
        if (choice != 0) {
            switch (choice) {
                case 1: menu_full_lists(&students, &classes, &courses); break;
                case 2: menu_partial_lists(&students, &classes, &courses); break;
//                case 4: menu_schedule(&students, &classes, &courses, &classCourses, &slots); break;
                default: cout << "Invalid choice!" << endl;
            }
        }
    } while (choice != 0);
    return 0;
}


void menu_full_lists(studentSet* students, classSet* classes, courseSet* courses) {
    int choice;
    do {
        clear();
        cout << "------------------------------------" << endl;
        cout << "| 1. List all students             |" << endl;
        cout << "| 2. List all classes              |" << endl;
        cout << "| 3. List all courses              |" << endl;
        cout << "| 4. List all lessons              |" << endl;
        cout << "| 0. Back                          |" << endl;
        cout << "------------------------------------" << endl;
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
        cout << "------------------------------------" << endl;
        /* Printing a line of text to the console. */
        cout << "| 1. List all students in a class  |" << endl;
        cout << "| 2. List all classes of a student |" << endl;
        cout << "| 3. List all lessons of a class   |" << endl;
        cout << "| 4. List all lessons of a course  |" << endl;
        cout << "| 0. Back                          |" << endl;
        cout << "------------------------------------" << endl;
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

//void menu_schedule(&students, &classes, &courses, &classCourses, &slots);