/**
 * @file main.cpp
 * @brief Main file do projeto, é a partir daqui que o programa começa a ser executado.
 */

#include "headers/Functions.h"

/**
 * @brief Main function
 * 
 * Começa a execução do programa.\n
 * Primeiro cria os sets com todos os alunos(students), todas as turmas(classes), todas as unidades curriculares(courses), todos os pares turma e unidade curricular(classCourse) e todas as aulas (slots).\n
 * Depois lê os arquivos de entrada (readAll).\n
 * A seguir imprime as opções do menu e processa a opção escolhida.\n
 */
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
        cout << "------------------------------------------" << endl;
        cout << "| 1. Listagens totais                    |" << endl;
        cout << "| 2. Listagens parciais                  |" << endl;
        cout << "| 3. Horários                            |" << endl;
        cout << "| 4. Realizar pedido                     |" << endl;
        cout << "| 0. Sair                                |" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Escolha: ";
        cin >> choice;
        if (choice != 0) {
            switch (choice) {
                case 1: menu_full_lists(&students, &classes, &courses, &slots); break;
                case 2: menu_partial_lists(&students, &classes, &courses, &classCourses, &slots); break;
                case 3: menu_schedules(&students, &classes, &courses, &classCourses, &slots); break;
                case 4: menu_requests(&students, &classes, &courses, &classCourses, &slots); break;
                default: cout << "Invalid choice!" << endl;
            }
        }
    } while (choice != 0);
    return 0;
}

/**
 * @brief Função que imprime o menu de listagens completas
 * 
 * Imprime o menu de listagens completas e processa a opção escolhida.\n
 * 
 * @param students Set com todos os alunos
 * @param classes Set com todas as turmas
 * @param courses Set com todas as unidades curriculares
 * @param slots Set com todas as aulas
 */
void menu_full_lists(studentSet* students, classSet* classes, courseSet* courses, slotSet* slots) {
    int choice;
    do {
        clear();
        cout << "------------------------------------------" << endl;
        cout << "| 1. Listar todos os estudantes          |" << endl;
        cout << "| 2. Listar todas as turmas              |" << endl;
        cout << "| 3. Listar todas as UCs                 |" << endl;
        cout << "| 4. Listar todas as aulas               |" << endl;
        cout << "| 0. Voltar                              |" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Escolha: ";
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

/**
 * @brief Função que imprime o menu de listagens parciais
 *
 * Imprime o menu com as opções de listagens parciais e processa a opção escolhida.\n
 * 
 * @param students Set com todos os alunos
 * @param classes  Set com todas as turmas
 * @param courses Set com todas as unidades curriculares
 */
void menu_partial_lists(studentSet* students, classSet* classes, courseSet* courses, classCoursesSet* classCourses, slotSet* slots) {
    int choice;
    do {
        clear();
        cout << "------------------------------------------" << endl;
        cout << "| 1. Ocupação de turmas/UC               |" << endl;
        cout << "| 2. Estudantes numa turma/UC            |" << endl;
        cout << "| 3. Estudantes inscritos numa UC        |" << endl;
        cout << "| 4. Turmas/UC de um estudante           |" << endl;
        cout << "| 0. Voltar                              |" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Escolha: ";
        cin >> choice;
        if (choice != 0) {
            switch (choice) {
                case 1: listClassCourseOccupation(classCourses); wait(); break;
                case 2: listStudentsInClassCourse(students, classes, courses); wait(); break;
                case 3: listStudentsInCourse(students, courses); wait(); break;
                case 4: listClassesOfStudent(students); wait(); break;
                default: cout << "Invalid choice!" << endl;
            }
        }
    } while (choice != 0);
}

/**
 * @brief Função que imprime o menu de da escolha da ordem das aulas
 *
 * Imprime o menu com as ordens possiveis em que se pode imprimir todas as aulas e processa a opção escolhida.\n
 *
 * @param students Set com todos os alunos
 * @param classes Set com todas as turmas
 * @param courses Set com todas as unidades curriculares
 * @param classCourses Set com todos os pares turma e unidade curricular
 * @param slots Set com todas as aulas
 */
void menu_schedules(studentSet* students, classSet* classes, courseSet* courses, classCoursesSet* classCourses, slotSet* slots) {
    int choice;
    do {
        clear();
        cout << "------------------------------------------" << endl;
        cout << "| 1. Horário de uma turma                |" << endl;
        cout << "| 2. Horário de uma UC                   |" << endl;
        cout << "| 3. Horário de um estudante             |" << endl;
        cout << "| 0. Voltar                              |" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Escolha: ";
        cin >> choice;
        if (choice != 0) {
            switch (choice) {
                case 1: listSlotsOfClass(classes); wait(); break;
                case 2: listSlotsOfCourse(courses); wait(); break;
                case 3: printAnyStudentSchedule(students, slots); wait(); break;
                default: cout << "Invalid choice!" << endl;
            }
        }
    } while (choice != 0);
}


void menu_requests(studentSet* students, classSet* classes, courseSet* courses, classCoursesSet* classCourses, slotSet* slots) {
    int choice;
    do {
        clear();
        cout << "------------------------------------------" << endl;
        cout << "| 1. Alterar horário de uma turma        |" << endl;
        cout << "| 2. Alterar horário de uma UC           |" << endl;
        cout << "| 3. Alterar horário de um estudante     |" << endl;
        cout << "| 0. Voltar                              |" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Escolha: ";
        cin >> choice;
        if (choice != 0) {
            switch (choice) {
                /*case 1: changeClassSchedule(classes, slots); wait(); break;
                case 2: changeCourseSchedule(courses, slots); wait(); break;
                case 3: changeStudentSchedule(students, classes, classCourses, slots); wait(); break;
                */default: cout << "Invalid choice!" << endl;
            }
        }
    } while (choice != 0);
}
