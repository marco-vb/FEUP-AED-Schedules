#ifndef REQUEST_H_
#define REQUEST_H_

#include "Types.h"

using namespace std;

class Request {
    private:
        int studentNumber;
        string courseCode;
        string classCode;
        string requestType;
        string requestStatus;
    public:
        Request(int studentNumber, string courseCode, string classCode, string requestType);
        int getStudentNumber() const;
        string getCourseCode() const;
        string getClassCode() const;
        string getRequestType() const;
        string getRequestStatus() const;
        void setRequestStatus(string requestStatus);
        bool handleRequest(studentSet*, courseSet*, classSet*, classCoursesSet*);
        void archiveRequest(ostream& out) const;
};

#endif