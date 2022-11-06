#ifndef REQUEST_H_
#define REQUEST_H_

#include "Types.h"

using namespace std;

/**
 * @brief Classe que representa um pedido de alteração de horário
 *
 * Esta classe é usada para representar um pedido de alteração de horário e guarda o número do aluno, o código da turma, a unidade curricular, o tipo de pedido e o estado do pedido.
 */
class Request {
    private:
        /// Numero de estudante
        int studentNumber;

        /// Código da unidade curricular
        string courseCode;

        /// Código da turma
        string classCode;

        /// Tipo de pedido
        string requestType;

        /// Estado do pedido
        string requestStatus;
    public:
        /**
         * @brief Construtor da classe Request
         * @param studentNumber Numero de estudante
         * @param courseCode Código da unidade curricular
         * @param classCode Código da turma
         * @param requestType Tipo de pedido
         */
        Request(int studentNumber, string courseCode, string classCode, string requestType);

        /**
         * @brief Retorna o número de estudante
         * @return O número de estudante
         */
        int getStudentNumber() const;

        /**
         * @brief Retorna o código da unidade curricular
         * @return O código da unidade curricular
         */
        string getCourseCode() const;

        /**
         * @brief Retorna o código da turma
         *
         * Retorna o código da turma no caso de inscrição ou mudança retorna da turma de destino, no caso de remoção retorna da turma de origem
         * @return O código da turma
         */
        string getClassCode() const;

        /**
         * @brief Retorna o tipo de pedido
         * @return O tipo de pedido
         */
        string getRequestType() const;

        /**
         * @brief Retorna o estado do pedido
         * @return O estado do pedido
         */
        string getRequestStatus() const;

        /**
         * @brief Altera o estado do pedido
         * @param requestStatus Novo estado do pedido
         */
        void setRequestStatus(string requestStatus);

        /**
         * @brief Processa o pedido, se possível
         *
         * Processa o pedido, se possível.\n
         * Este metodo consgue adicionar ou remover uma turma a um estudante, ou trocar uma turma por outra, para isto, primeiro remove o estudante da turma de origem e adiciona-o à turma de destino.\n
         *
         * @return true se o pedido for aceite, false caso contrario
         */
        bool handleRequest(studentSet*, courseSet*, classSet*, classCoursesSet*);

        /**
         * @brief Arquiva o pedido atraves da stream fornecida
         * @param out Stream de output
         */
        void archiveRequest(ostream& out) const;
};

#endif