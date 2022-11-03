#include "../headers/Request.h"

using namespace std;

Request::Request(int studentNumber, int requestNumber, string courseCode, string classCode, string requestType, string requestStatus, string requestDate, string requestTime) {
    this->studentNumber = studentNumber;
    this->requestNumber = requestNumber;
    this->courseCode = std::move(courseCode);
    this->classCode = std::move(classCode);
    this->requestType = std::move(requestType);
    this->requestStatus = std::move(requestStatus);
    this->requestDate = std::move(requestDate);
    this->requestTime = std::move(requestTime);
}

int Request::getStudentNumber() const {return studentNumber;}

int Request::getRequestNumber() const {return requestNumber;}

string Request::getCourseCode() const {return courseCode;}

string Request::getClassCode() const {return classCode;}

string Request::getRequestType() const {return requestType;}

string Request::getRequestStatus() const {return requestStatus;}

string Request::getRequestDate() const {return requestDate;}

string Request::getRequestTime() const {return requestTime;}

void Request::setRequestStatus(string requestStatus) {this->requestStatus = std::move(requestStatus);}

void Request::handleRequest(studentSet* students) {
    if (requestType == "remove") {
        auto student = students->find(new Student(studentNumber));
        if((*student)->removeClassCourse(classCode, courseCode))
            setRequestStatus("accepted");
        else
            setRequestStatus("rejected");
    }

    if (requestType == "add") {
        auto student = students->find(new Student(studentNumber));
        if((*student)->addClassCourse(classCode, courseCode))
            setRequestStatus("accepted");
        else
            setRequestStatus("rejected");
    }

    if (requestType == "change") {
        auto student = students->find(new Student(studentNumber));
        for (const auto& p : (*student)->getClassesPerCourse()) {
            if (p.second == courseCode) {
                if((*student)->removeClassCourse(p.first, p.second)) {
                    if ((*student)->addClassCourse(classCode, courseCode))
                        setRequestStatus("accepted");
                    else
                        setRequestStatus("rejected");
                }
                else
                    setRequestStatus("rejected");
            }
        }
    }
}

void Request::archiveRequest(ostream& out) const {
    out << studentNumber << "," << requestNumber << "," << courseCode << ","
    << classCode << "," << requestType << "," << requestStatus << "," <<
    requestDate << "," << requestTime << endl;
}