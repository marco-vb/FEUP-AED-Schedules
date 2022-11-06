/**
 * @file Functions.h
 * @brief Ficheiro que contém as funções auxiliares a main.cpp
 *
 * Este ficheiro foi criada para que ficheiro main.cpp não fique muito confuso.
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Types.h"
#include "Request.h"
#include "IndependentFunctions.h"


//files
string const& classesCourses = "../aux_files/classes_per_uc.csv";
string const& classesStudents = "../aux_files/students_classes.csv";
string const& classesSlots = "../aux_files/classes.csv";

//functions
void menu_full_lists(studentSet* students, classSet* classes, courseSet* courses, slotSet* slots);
void menu_partial_lists(studentSet*, classSet*, courseSet*, classCoursesSet*, slotSet*);
void menu_schedules(studentSet*, classSet*, courseSet*, classCoursesSet*, slotSet*);
void menu_requests(studentSet*, classSet*, courseSet*, classCoursesSet*, slotSet*, queue<Request*>*);
void menu_lesson_order(slotSet* slots);
void readClasses(classSet* classes, courseSet* courses, classCoursesSet* classCourses);
void readStudents(studentSet* students, classSet* classes, courseSet* courses, classCoursesSet* classCourses);
void readSlots(studentSet* students, classSet* classes, courseSet* courses, slotSet* slots);


/**
 * @brief Função lê os ficheiros classes.csv, classes_per_uc.csv e students_classes.csv e guarda a informação.
 *
 * Esta lê os três ficheiros fornecidos e guarda a informação nos respetivos sets, cujos pointers são passados como arumentos.\n
 * Faz-lo recorrendo a funções auxiliares que lêem cada um dos ficheiros, readClasses, readStudents e readSlots.
 *
 * @param students Set de todos os alunos
 * @param classes Set de todas as turmas
 * @param courses Set de todas unidades curriculares
 * @param classCourses Set de todos os pares de turma e unidade curricular
 * @param slots Set de todas as aulas
 */
void readAll(studentSet* students, classSet* classes, courseSet* courses, classCoursesSet* classCourses, slotSet* slots) {
    readClasses(classes, courses, classCourses);
    readSlots(students, classes, courses, slots);
    readStudents(students, classes, courses, classCourses);
}

//functions defined
/**
 * @brief Função lê o ficheiro classes_per_uc.csv e guarda a informação.
 *
 * Esta lê o ficheiro classes_per_uc.csv e guarda a informação nos respetivos sets, cujos pointers são passados como arumentos.\n
 *
 * @param classes Set de todas as turmas
 * @param courses Set de todas unidades curriculares
 * @param classCourses Set de todos os pares de turma e unidade curricular
 */
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

/**
 * @brief Função lê o ficheiro students_classes.csv e guarda a informação.
 *
 * Esta lê o ficheiro students_classes.csv e guarda a informação nos respetivos sets, cujos pointers são passados como arumentos.\n
 *
 * @param students Set de todos os alunos
 * @param classes Set de todas as turmas
 * @param courses Set de todas unidades curriculares
 * @param classCourses Set de todos os pares de turma e unidade curricular
 */
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

/**
 * @brief Função lê o ficheiro classes.csv e guarda a informação.
 *
 * Esta lê o ficheiro classes.csv e guarda a informação nos respetivos sets, cujos pointers são passados como arumentos.\n
 *
 * @param students Set de todos os alunos
 * @param classes Set de todas as turmas
 * @param slots Set de todas as aulas
 */
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

/**
 * @brief Imprime uma lista de todos os alunos, por ordem do número de estudante ou por ordem alfabética.
 *
 * Complexidade Temporal: O(N) onde N é o número de alunos.
 * @param students Set de todos os alunos
 */
void listAllStudents(studentSet* students) {
    cout << "Ordenacao (1) por numero de aluno ou (2) por nome? ";
    int choice;
    cin >> choice;
    if (choice != 1 && choice != 2) {
        cout << "Opcao invalida!" << endl;
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
        cout << s->getNumber() << " - " << s->getName() << endl;
    }
}

/**
 * @brief Imprime uma lista de todas as turmas, por ordem alfabética do código da turma.
 *
 * Complexidade Temporal: O(N) onde N é o número de turmas.
 * @param classes Set de todas as turmas
 */
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

/**
 * @brief Imprime uma lista de todas as unidades curriculares, por ordem alfabética do código da unidade curricular.
 *
 * Complexidade Temporal: O(N) onde N é o número de unidades curriculares.
 * @param courses Set de todas as unidades curriculares
 */
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

/**
 * @brief Imprime uma lista de todas as aulas, por Unidade Curricular, por ordem alfabética do código da turma.
 *
 * Complexidade Temporal: O(N) onde N é o número de aulas.
 * @param courses Set de todas as unidades curriculares
 */
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

/**
 * @brief Imprime uma listo número de estudantes em cada par (turma, unidade curricular).
 *
 * Complexidade Temporal: O(N) onde N é o número de pares (turma, unidade curricular).
 * @param classCourses Set de todos os pares de turma e unidade curricular
 */
void listClassCourseOccupation(classCoursesSet* classCourses) {
    auto it = classCourses->begin();
    while (it != classCourses->end()) {
        string coursecode = (*it)->course;
        cout << coursecode << endl;
        cout << "----------------" << endl;
        while (it != classCourses->end() && (*it)->course == coursecode) {
            cout << (*it)->class_ << " - Number of students: " << (*it)->students << endl;
            it++;
        }
        cout << endl;
    }
}


/**
 * @brief Imprime uma lista de todos os estudantes num par (turma, unidade curricular).
 *
 * Complexidade Temporal: O(log(T) + log(U) + N) onde T é o número de turmas, U é o número de unidades curriculares e N é o número de estudantes por par (turma, unidade curricular).
 *
 * @param students Set de todos os alunos
 * @param classes Set de todas as turmas
 * @param courses Set de todas as unidades curriculares
 */
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
        cout << (*student_it)->getNumber() << " - " << (*student_it)->getName() << endl;
    }
}

/**
 * @brief Imprime uma lista de todos os estudantes numa Unidade Curricular.
 *
 * Complexidade Temporal: O(log(U) + N) onde U é o número de unidades curriculares e N é o número de estudantes por unidade curricular.
 *
 * @param students Set de todos os alunos
 * @param courses Set de todas as unidades curriculares
 */
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
        cout << (*student_it)->getNumber() << " - " << (*student_it)->getName() << endl;
    }
}


/**
 * @brief Imprime uma lista de todas as aulas, por ordem alfabética de codigo da turma, e em caso de empate por ordem alfabética de codigo da unidade curricular
 *
 * Complexidade Temporal: O(N) onde N é o número total de aulas.
 *
 * @param slots Set de todas as aulas
 */
void listAllSlots(slotSet* slots) {
    for (const auto& sp : *slots) {
        Slot s = *sp;
        cout << "UC: " << s.getCourseCode() << " - Turma: " << s.getClassCode() << " - " << s.getDay() << " " << floatToMinutes(s.getStartHour()) << "-" << floatToMinutes(s.getEndHour()) << " " << s.getType() << endl;
    }
}

/**
 * @brief Imprime uma lista de todas as aulas, por uma ordem definida pelo utilizador, através do parâmetro comp
 *
 * Complexidade Temporal: O(N*log(N)) onde N é o número de aulas.
 *
 * @param slots Set de todas as aulas
 * @param comp Comparator usada na ordenação
 */
template<typename Compare>
void listAllSlotsOrder(slotSet* slots, Compare comp){
    vector<Slot> slotsVector;
    slotsVector.reserve(slots->size());
    for (const auto& sp : *slots) {
        slotsVector.push_back(*sp);
    }
    sort(slotsVector.begin(), slotsVector.end(), comp);
    for (const auto& s : slotsVector) {
        cout << "Course: " << s.getCourseCode() << " - Class: " << s.getClassCode() << " - " << s.getDay() << " " << floatToMinutes(s.getStartHour()) << "-" << floatToMinutes(s.getEndHour()) << " " << s.getType() << endl;
    }
}

/**
 * @brief Imprime todas as turmas por unidade curricular em que um aluno está inscrito, por ordem alfabética do código da turma
 *
 * A função primeiro pede ao utilizador o numero do estudante, depois procura o estudante no set de estudantes usando o metodo find(), e por fim imprime todas as turmas por unidade curricular em que o estudante está inscrito.\n
 * Complexidade Temporal: O(T + log(N)) onde N é o número de estudantes e T é o número de turmas em que o estudante está inscrito.
 *
 * @param students Set de todos os alunos
 */
void listClassesOfStudent(studentSet* students) {
    int studentNumber;
    cout << "Número de estudante: ";
    cin >> studentNumber;
    auto s = students -> find(new Student(studentNumber));
    if (s == students->end()) {
        cout << "Student not found!" << endl; return;
    }
    auto studentclasses = (*s) -> getClassesPerCourse();
    cout << (*s) -> getName() << endl;
    cout << "---------------------------------" << endl;
    for (const auto& c : studentclasses) {
        cout << c.first << " - " << c.second << endl;
    }
}

/**
 * @brief Imprime todas as as aulas de uma turma
 *
 * A função primeiro pede-se ao utilizador o código da turma, e depois procura essa turma no set de turmas utilizando o metodo find().\n
 * A seguir itera sobre o horario da turma e imprime todas as aulas.\n
 * Complexidade Temporal: O(A + log(T)) onde A é o número de aulas da turma e T é o número total de turmas.
 *
 *
 * @param classes Set de todas as turmas
 */
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
    else {
        cout << "Class not found!" << endl;
    }
}

/**
 * @brief Imprime todas as as aulas de uma unidade curricular
 *
 * A função primeiro pede-se ao utilizador o código da unidade curricular, e depois procura essa unidade curricular no set de unidades curriculares utilizando o metodo find().\n
 * A seguir itera sobre o horario da unidade curricular e imprime todas as aulas.\n
 * Complexidade Temporal: O(A + log(U)) onde A é o número de aulas da unidade curricular e U é o número de unidades curriculares.
 *
 *
 * @param courses Set de todas as unidades curriculares
 */
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

/**
 * @brief Imprime o horário do estudante cujo numero foi intruduzido pelo utilizador no terminal
 *
 * A função primeiro pede ao utilizador o numero do estudante com a stream cin.\n
 * Depois procura o estudante no set de estudantes utilizando o metodo find().\n
 * A função itera sobre o o set de pares ClassesPerCourse do estudante e procura as respetivas aulas no set slots utilizando o metodo equal_range(), uma vez que os estudante terá varias aulas do mesmo par turma e unidade curricular.\n
 * A seguir adiciona as aulas encontradas ao vetor schedule.\n
 * Por fim ordena o vetor schedule e imprime todas as aulas.\n
 * Complexidade Temporal: O(log(S) + C*log(N) + A*log(A)) onde S é o numero total de estudantes, C é numero de unidades curriculares em que o estudante está instrito, N é o tamanho do set slots, A é o número de aulas do estudante por semana.\n
 * Complexidade Temporal é igual a complexidade de students->find() + printStudentSchedule().\n
 *
 * @param students Set de todos os estudantes
 * @param slots Set de todas as aulas
 */
void listSlotsOfStudent(studentSet* students, slotSet* slots) {
    int studentNumber;
    cout << "Número de estudante: ";
    cin >> studentNumber;
    auto s = students->find(new Student(studentNumber));
    if (s == students->end()) {
        cout << "Student not found!" << endl;
        return;
    }
    auto studentclasses = (*s)->getClassesPerCourse();
    vector<Slot> schedule;
    cout << (*s) -> getName() << endl;
    cout << "---------------------------------" << endl;
    for (const auto& p: studentclasses) {
        auto range = slots->equal_range(new Slot("", 0, 0, "", p.second, p.first));
        for(auto it = range.first; it != range.second; it++){
            schedule.push_back(**it);
        }
    }

    sort(schedule.begin(), schedule.end());
    for (const auto& slot : schedule) {
        cout << slot.getDay() << " " << slot.getStartHour() << " " << slot.getEndHour() << " " << slot.getType() << endl;
    }
}

/**
 * @brief Imprime todos os estudantes inscritos em mais de N unidades curriculares
 *
 * Itera sobre o set de estudantes e imprime todos os estudantes que estão inscritos em mais de N unidades curriculares.\n
 * Complexidade Temporal: O(N) onde N é o número total de estudantes.
 *
 * @param students Set de todos os estudantes
 */
void listStudentsInMoreThanNCourses(studentSet* students){
    int n;
    cout << "Introduza o número de unidades curriculares: ";
    cin >> n;
    for (const auto& s : *students) {
        if (s->getClassesPerCourse().size() > n) {
            cout << s->getNumber() << " - " << s->getName() << endl;
        }
    }
}

/**
 * @brief Adiciona um pedido de desinscrição de um estudante numa turma/unidade curricular
 *
 * Complexidade temporal: O(log(N) + log(T) + log(U)) onde N é o número de estudantes, T é o número de turmas e U é o número de unidades curriculares.
 *
 * @param classes Set de todas as turmas
 * @param students Set de todos os estudantes
 * @param courses Set de todas as unidades curriculares
 * @param requests Fila de pedidos
 */
void removeStudent(classSet* classes, studentSet* students, courseSet* courses, queue<Request*>* requests) {
    int studentNumber;
    cout << "Número de estudante: ";
    cin >> studentNumber;
    auto s = students->find(new Student(studentNumber));
    if (s == students->end()) {
        cout << "Student not found!" << endl;
        return;
    }
    string courseCode;
    cout << "Unidade Curricular: ";
    cin >> courseCode;
    auto course = courses->find(new Course(courseCode));
    if ((*course)->getCode() != courseCode) {
        cout << "UC não encontrada!" << endl;
        return;
    }
    string classCode;
    cout << "Turma da qual pretende sair: ";
    cin >> classCode;
    auto class_ = classes->find(new Class(classCode));
    if (class_ == classes->end()) {
        cout << "Turma não encontrada!" << endl;
        return;
    }

    (*class_)->removeStudent(studentNumber);
    (*course)->removeStudent(studentNumber);
    auto r = new Request(studentNumber, courseCode, classCode, "remove");
    requests->push(r);
}

/**
 * @brief Adiciona um pedido de inscrição de um estudante numa turma/unidade curricular
 *
 * Complexidade temporal: O(log(N) + log(T) + log(U)) onde N é o número de estudantes, T é o número de turmas e U é o número de unidades curriculares.
 *
 * @param classes Set de todas as turmas
 * @param students Set de todos os estudantes
 * @param courses Set de todas as unidades curriculares
 * @param requests Fila de pedidos
 */
void addStudent(classSet* classes, studentSet* students, courseSet* courses, queue<Request*>* requests) {
    int studentNumber;
    cout << "Número de estudante: ";
    cin >> studentNumber;
    auto s = students->find(new Student(studentNumber));
    if (s == students->end()) {
        cout << "Student not found!" << endl;
        return;
    }
    string courseCode;
    cout << "Unidade Curricular: ";
    cin >> courseCode;
    auto course = courses->find(new Course(courseCode));
    if ((*course)->getCode() != courseCode) {
        cout << "UC não encontrada!" << endl;
        return;
    }

    string classCode;
    cout << "Turma na qual pretende entrar: ";
    cin >> classCode;
    auto class_ = classes->find(new Class(classCode));
    if (class_ == classes->end()) {
        cout << "Turma não encontrada!" << endl;
        return;
    }

    (*class_)->removeStudent(studentNumber);
    (*course)->removeStudent(studentNumber);
    auto r = new Request(studentNumber, courseCode, classCode, "add");
    requests->push(r);
}

/**
 * @brief Adiciona um pedido de mudança de uma turma/unidade curricular de um estudante.
 *
 * Complexidade temporal: O(log(N) + log(T) + log(U)) onde N é o número de estudantes, T é o número de turmas e U é o número de unidades curriculares.
 *
 * @param classes Set de todas as turmas
 * @param students Set de todos os estudantes
 * @param courses Set de todas as unidades curriculares
 * @param requests Fila de pedidos
 */
void changeStudent(classSet* classes, studentSet* students, courseSet* courses, queue<Request*>* requests) {
    int studentNumber;
    cout << "Número de estudante: ";
    cin >> studentNumber;
    auto s = students->find(new Student(studentNumber));
    if (s == students->end()) {
        cout << "Student not found!" << endl;
        return;
    }
    string courseCode;
    cout << "Unidade Curricular: ";
    cin >> courseCode;
    auto course = courses->find(new Course(courseCode));
    if ((*course)->getCode() != courseCode) {
        cout << "UC não encontrada!" << endl;
        return;
    }
    string classCode;
    cout << "Turma para a qual pretende mudar: ";
    cin >> classCode;
    auto class_ = classes->find(new Class(classCode));
    if (class_ == classes -> end()) {
        cout << "Turma não encontrada!" << endl;
        return;
    }

    auto r = new Request(studentNumber, courseCode, classCode, "change");
    requests->push(r);
}

/**
 * @brief Processa, se possivel, todos os pedidos de inscrição, desinscrição e mudança de turma.
 *
 * @param students Set de todos os estudantes
 * @param classes Set de todas as turmas
 * @param courses Set de todas as unidades curriculares
 * @param classCourses Set de todas pares de turmas e unidades curriculares
 * @param requests Fila de pedidos
 */
void processAllRequests(studentSet* students, classSet* classes, courseSet* courses, classCoursesSet* classCourses, queue<Request*>* requests) {
    queue<Request*> aux;
    while (!requests->empty()) {
        Request* r = requests->front();
        requests->pop();
        if (r->handleRequest(students, courses, classes, classCourses)) {
            cout << "Request processed successfully!" << endl;
        }
        else {
            cout << "Request failed!" << endl;
            aux.push(r);
        }
    }
    while (!aux.empty()) {
        requests->push(aux.front());
        aux.pop();
    }
}

/**
 * @brief Lê os pedidos pendentes do ficheiro pending_requests.txt.
 * @param requests Fila de pedidos
 */
void readPendingRequests(queue<Request*>* requests) {
    ifstream file("../aux_files/pending_requests.txt");
    if (!file.is_open()) {
        cout << "Erro ao abrir o ficheiro!" << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string studentNumber, courseCode, classCode, type;
        ss >> studentNumber >> courseCode >> classCode >> type;
        auto r = new Request(stoi(studentNumber), courseCode, classCode, type);
        requests->push(r);
    }
    cout << "Pending requests read successfully!" << endl;
    file.close();
}

/**
 * @brief Escreve todos os pedidos pendentes para o ficheiro pending_requests.txt.
 * @param requests Fila de pedidos
 */
void savePendingRequests(queue<Request*>* requests) {
    ofstream file("../aux_files/pending_requests.txt");
    if (!file.is_open()) {
        cout << "Erro ao abrir o ficheiro!" << endl;
        return;
    }
    file.clear();
    while (!requests->empty()) {
        Request* r = requests->front();
        requests->pop();
        file << r->getStudentNumber() << " " << r->getCourseCode() << " " << r->getClassCode() << " " << r->getRequestType() << endl;
    }
    cout << "Pedidos pendentes guardados com sucesso!" << endl;
    file.close();
}

/**
 * @brief Atualiza o ficheiro classes.csv com as turmas atuais.
 * @param classes Set de todas as turmas
 */
void saveClasses(slotSet* slots) {
    ofstream file("../aux_files/classes.csv");
    if (!file.is_open()) {
        cout << "Erro ao abrir o ficheiro!" << endl;
        return;
    }
    file.clear();
    file << "ClassCode,UcCode,Weekday,StartHour,Duration,Type" << endl;
    for (auto s : *slots) {
        file << s->getClassCode() << ',' << s->getCourseCode() << ',' << s->getDay() << ',' << s->getStartHour() << ',' << s->getEndHour() - s->getStartHour() << ',' << s->getType() << endl;
    }
    cout << "classes.csv atualizado com sucesso!" << endl;
    file.close();
}

/**
 * @brief Atualiza o ficheiro classes_per_uc.csv com os pares de turmas e unidades curriculares atuais.
 * @param classCourses Set de todas as unidades curriculares
 */
void saveClassesPerUC(classCoursesSet* classCourses) {
    ofstream file("../aux_files/classes_per_uc.csv");
    if (!file.is_open()) {
        cout << "Erro ao abrir o ficheiro!" << endl;
        return;
    }
    file.clear();
    file << "UcCode,ClassCode" << endl;
    for (auto classCourse : *classCourses) {
        file << classCourse->course << ',' << classCourse->class_ << endl;
    }
    cout << "classes_per_uc.csv atualizado com sucesso!" << endl;
    file.close();
}

/**
 * @brief Atualiza o ficheiro students_per_class.csv com os estudantes e suas turmas atuais.
 * @param students Set de todos os estudantes
 */
void saveStudentsClasses(studentSet* students) {
    ofstream file("../aux_files/students_classes.csv");
    if (!file.is_open()) {
        cout << "Erro ao abrir o ficheiro!" << endl;
        return;
    }
    file.clear();
    file << "StudentCode,StudentName,UcCode,ClassCode" << endl;
    for (auto student : *students) {
        for (auto p: student->getClassesPerCourse()) {
            file << student->getNumber() << ',' << student->getName() << ',' << p.second << ',' << p.first << endl;
        }
    }
    cout << "students_classes.csv atualizado com sucesso!" << endl;
    file.close();
}

/**
 * @brief Atualiza todos os ficheiros com as informações atuais.
 * @param students Set de todos os estudantes
 * @param classes Set de todas as turmas
 * @param courses Set de todas as unidades curriculares
 * @param classCourses Set de todas pares de turmas e unidades curriculares
 * @param slots Set de todos as aulas
 */
void saveAll(studentSet* students, classSet* classes, courseSet* courses, classCoursesSet* classCourses, slotSet* slots) {
    saveClasses(slots);
    saveClassesPerUC(classCourses);
    saveStudentsClasses(students);
}


/// Função que limpa o ecrã
void clear() {
    for (int i = 0; i < 50; i++) cout << endl;
}

/// Função que espera que o utilizador pressione enter para continuar
void wait() {
    int c; do c = getchar(); while ((c != '\n') && (c != EOF));
    cout << "Press ENTER to continue...";
    do{ c = getchar(); }while ((c != '\n') && (c != EOF));
}
#endif
