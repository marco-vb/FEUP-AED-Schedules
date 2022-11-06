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
 * Alem disso cria um vetor de pedidos por processar (requests).\n
 * Depois lê os arquivos de entrada (readPendingRequests e readAll).\n
 * A seguir imprime as opções do menu e processa a opção escolhida.\n
 */
int main() {
    studentSet students;
    classSet classes;
    courseSet courses;
    classCoursesSet classCourses;
    slotSet slots;
    queue<Request*> requests;

    // Read data from files
    readPendingRequests(&requests);
    readAll(&students, &classes, &courses, &classCourses, &slots);

    cout << fixed << setprecision(1); // print lesson times correctly
    wait();
    int choice;
    do {
        clear();
        cout << "------------------------------------------" << endl;
        cout << "| 1. Listagens totais                    |" << endl;
        cout << "| 2. Listagens parciais                  |" << endl;
        cout << "| 3. Horarios                            |" << endl;
        cout << "| 4. Realizar pedido                     |" << endl;
        cout << "| 5. Processar pedidos                   |" << endl;
        cout << "| 0. Sair                                |" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Escolha: ";
        cin >> choice;
        if (choice != 0) {
            switch (choice) {
                case 1: menu_full_lists(&students, &classes, &courses, &slots); break;
                case 2: menu_partial_lists(&students, &classes, &courses, &classCourses, &slots); break;
                case 3: menu_schedules(&students, &classes, &courses, &classCourses, &slots); break;
                case 4: menu_requests(&students, &classes, &courses, &classCourses, &slots, &requests); break;
                case 5: processAllRequests(&students, &classes, &courses, &classCourses, &requests); wait(); break;
                default: cout << "Opcao invalida!" << endl;
            }
        }
    } while (choice != 0);

    clear();
    cout << "A guardar os dados..." << endl;
    savePendingRequests(&requests);
    saveAll(&students, &classes, &courses, &classCourses, &slots);
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
                case 4: menu_lesson_order(slots); break;
                default: cout << "Opcao invalida!" << endl;
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
        cout << "| 1. Ocupacao de turmas/UC               |" << endl;
        cout << "| 2. Estudantes numa turma/UC            |" << endl;
        cout << "| 3. Estudantes inscritos numa UC        |" << endl;
        cout << "| 4. Turmas/UC de um estudante           |" << endl;
        cout << "| 5. Estudante em mais de N UCs          |" << endl;
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
                case 5: listStudentsInMoreThanNCourses(students); wait(); break;
                default: cout << "Opcao invalida!" << endl;
            }
        }
    } while (choice != 0);
}

/**
 * @brief Função que imprime menu com as opções de horários.
 *
 * Imprime o menu com as opções de horários e processa a opção escolhida.\n
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
        cout << "| 1. Horario de uma turma                |" << endl;
        cout << "| 2. Horario de uma UC                   |" << endl;
        cout << "| 3. Horario de um estudante             |" << endl;
        cout << "| 0. Voltar                              |" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Escolha: ";
        cin >> choice;
        if (choice != 0) {
            switch (choice) {
                case 1: listSlotsOfClass(classes); wait(); break;
                case 2: listSlotsOfCourse(courses); wait(); break;
                case 3: listSlotsOfStudent(students, slots); wait(); break;
                default: cout << "Opcao invalida!" << endl;
            }
        }
    } while (choice != 0);
}


/**
 * @brief Função que imprime o menu de pedidos
 *
 * Imprime o menu de pedidos e processa a opção escolhida.\n
 *
 * @param students Set com todos os alunos
 * @param classes Set com todas as turmas
 * @param courses Set com todas as unidades curriculares
 * @param classCourses Set com todos os pares turma e unidade curricular
 * @param slots Set com todas as aulas
 * @param requests Fila de pedidos
 */
void menu_requests(studentSet* students, classSet* classes, courseSet* courses, classCoursesSet* classCourses, slotSet* slots, queue<Request*>* requests) {
    int choice;
    do {
        clear();
        cout << "------------------------------------------" << endl;
        cout << "| 1. Remover estudante de turma/UC       |" << endl;
        cout << "| 2. Adicionar estudante a turma/UC      |" << endl;
        cout << "| 3. Trocar um estudante de turma        |" << endl;
        cout << "| 0. Voltar                              |" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Escolha: ";
        cin >> choice;
        if (choice != 0) {
            switch (choice) {
                case 1: removeStudent(classes, students, courses, requests); wait(); break;
                case 2: addStudent(classes, students, courses, requests); wait(); break;
                case 3: changeStudent(classes, students, courses, requests); wait(); break;
                default: cout << "Opcao invalida!" << endl;
            }
        }
    } while (choice != 0);
}

/**
 * @brief Função que imprime o menu de da escolha da ordem das aulas
 *
 * Imprime o menu com as ordens possiveis em que se pode imprimir todas as aulas e processa a opção escolhida.\n
 *
 * @param slots Set com todas as aulas
 */
void menu_lesson_order(slotSet* slots){
    int choice;
    do {
        clear();
        cout << "------------------------------------------" << endl;
        cout << "| Ordenado por:                          |" << endl;
        cout << "| 1. Turma                               |" << endl;
        cout << "| 2. UC                                  |" << endl;
        cout << "| 3. Hora de Inicio                      |" << endl;
        cout << "| 4. Hora de Fim                         |" << endl;
        cout << "| 5. Dia da Semana                       |" << endl;
        cout << "| 0. Voltar                              |" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Escolha: ";
        cin >> choice;
        if (choice != 0) {
            switch (choice) {
                case 1: listAllSlots(slots); wait(); break;
                case 2: listAllSlotsOrder(slots, slotCompareByCourse()); wait(); break;
                case 3: listAllSlotsOrder(slots, slotCompareByStartHour()); wait(); break;
                case 4: listAllSlotsOrder(slots, slotCompareByEndHour()); wait(); break;
                case 5: listAllSlotsOrder(slots, slotCompareByDay()); wait(); break;
                default: cout << "Opcao invalida!" << endl;
            }
        }
    } while (choice != 0);
}