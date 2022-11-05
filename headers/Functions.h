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
string const& classesCourses = "../files/classes_per_uc.csv";
string const& classesStudents = "../files/students_classes.csv";
string const& classesSlots = "../files/classes.csv";

//functions
void menu_full_lists(studentSet* students, classSet* classes, courseSet* courses, slotSet* slots);
void menu_partial_lists(studentSet*, classSet*, courseSet*, classCoursesSet*, slotSet*);
void printStudentSchedule(Student* student, slotSet* slots);
void menu_schedules(studentSet*, classSet*, courseSet*, classCoursesSet*, slotSet*);
void menu_requests(studentSet*, classSet*, courseSet*, classCoursesSet*, slotSet*, queue<Request*>*);
void getLessonOrder(slotSet* slots);
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
        cout << "Course: " << s.getCourseCode() << " - Class: " << s.getClassCode() << " - " << s.getDay() << " " << floatToMinutes(s.getStartHour()) << "-" << floatToMinutes(s.getEndHour()) << " " << s.getType() << endl;
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
    for (const auto& c : studentclasses) {
        for (const auto& slot : *slots) {
            if (slot->getClassCode() == c.first && slot->getCourseCode() == c.second) {
                schedule.push_back(*slot);
            }
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
    cout << "Enter n, the number of courses: ";
    cin >> n;
    for (const auto& s : *students) {
        if (s->getClassesPerCourse().size() > n) {
            cout << s->getNumber() << " - " << s->getName() << endl;
        }
    }
}

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
 * @brief Imprime o horário do estudante cujo numero foi intruduzido pelo utilizador no terminal
 *
 * A função primeiro pede ao utilizador o numero do estudante com a stream cin.\n
 * Depois procura o estudante no set de estudantes utilizando o metodo find().\n
 * A seguir itera sobre o horario do estudante e imprime todas as aulas.\n
 * Complexidade Temporal: O(log(S) + A*log(D) + C*log(N)) onde S é o numero total de estudantes, C é numero de unidades curriculares em que o estudante está instrito, N é o tamanho do set slots, A é o número de aulas do estudante por semana e D é o número maximo de aulas por dia.\n
 * Complexidade Temporal é igual a complexidade de students->find() + printStudentSchedule().\n
 *
 * @param students Set de todos os estudantes
 * @param slots Set de todas as aulas
 */
void printAnyStudentSchedule(studentSet* students, slotSet* slots) {
    int studentNumber;
    cout << "Número de estudante: ";
    cin >> studentNumber;
    auto student_it = students->find(new Student(studentNumber));
    /*if(student_it != students -> end()) printStudentSchedule(*student_it, slots, cout);
    else cout << "Student not found!" << endl;*/
}

/**
 * @brief Retorna o horário do estudante
 *
 * A função itera sobre o o set de pares ClassesPerCourse do estudante e procura a aula no set de aulas(slots) utilizando o metodo equal_range(), uma vez que os estudante terá varias aulas do mesmo par turma unidade curricular.\n
 * A seguir adiciona as aulas encontradas ao schedule.\n
 * Retorna o schedule.\n
 *
 * Complexidade Temporal: O(A*log(D) + C*log(N)) onde C é numero de unidades curriculares em que o estudante está instrito, N é o tamanho do set slots, A é o número de aulas do estudante por semana e D é o número maximo de aulas por dia.\n
 * <small><pre>
 * Explicaçao:
 *   Complexidade de cada passo: 1º for loop: C, onde C é numero de unidades curriculares em que o estudante está instrito
 *                               equal_range: log(N), onde N é o tamanho do set slots
 *                               2º for loop: M, onde M é o numero de aulas dessa cadeira por semana
 *                               addSlot: log(D), onde D é o número máximo de aulas de um dia
 *   Complexidade: C*(log(N) + M*log(D)) = C*log(N) + A*log(D), onde A é o número de aulas do estudante por semana, logo A = C*M
 * </pre></small>
 *
 * @param student
 * @param slots
 * @return O horário do estudante
 */
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

/**
 * @brief Imprime o horário do estudante passado cujo pointer é passado como argumento
 *
 * A função imprime o dia da semana, seguido de todas as aulas desse dia.\n
 * Complexidade Temporal: O(A*log(D) + C*log(N)) onde C é numero de unidades curriculares em que o estudante está instrito, N é o tamanho do set slots, A é o número de aulas do estudante por semana e D é o número maximo de aulas por dia.\n
 * Complexidade Temporal igual a getStudentSchedulde() uma vez que a complexidade de imprimir o horario é menor que o obter.
 *
 * @param student Pointer para o estudante
 * @param slots Set de todas as aulas
 */
void printStudentSchedule(Student* student, slotSet* slots){
    Schedule schedule = getStudentSchedule(student, slots);
    for(int i = 0; i < 6; i++){
        if(!schedule[i].empty())
            cout << numToWeekDay(i) << ": " << endl;
        for(const Slot& class_: schedule[i])
            cout << "    Class: " << class_.getClassCode() << " - Course: " << class_.getCourseCode() << " - "
                << class_.getType() << " - " << class_.getStartHour() << "-" << class_.getEndHour() << endl;
        cout << endl;
    }
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
