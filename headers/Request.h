#ifndef REQUEST_H_
#define REQUEST_H_

#include "Types.h"

using namespace std;

class Request {
    private:
        int studentNumber;
        int requestNumber;
        string courseCode;
        string classCode;
        string requestType;
        string requestStatus;
        string requestDate;
        string requestTime;
    public:
        Request(int studentNumber, int requestNumber, string courseCode, string classCode, string requestType, string requestStatus, string requestDate, string requestTime);
        int getStudentNumber() const;
        int getRequestNumber() const;
        string getCourseCode() const;
        string getClassCode() const;
        string getRequestType() const;
        string getRequestStatus() const;
        string getRequestDate() const;
        string getRequestTime() const;
        void setRequestStatus(string requestStatus);
        void handleRequest(studentSet* students);
        void archiveRequest(ostream& out) const;
};

#endif