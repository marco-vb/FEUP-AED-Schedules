#include "../headers/Request.h"
using namespace std;
Request::Request(int studentNumber, string courseCode, string classCode, string requestType) {
    this->studentNumber = studentNumber;
    this->courseCode = std::move(courseCode);
    this->classCode = std::move(classCode);
    this->requestType = std::move(requestType);
    this->requestStatus = string();
}
int Request::getStudentNumber() const {return studentNumber;}
string Request::getCourseCode() const {return courseCode;}
string Request::getClassCode() const {return classCode;}
string Request::getRequestType() const {return requestType;}
string Request::getRequestStatus() const {return requestStatus;}
void Request::setRequestStatus(string requestStatus) {this->requestStatus = std::move(requestStatus);}
bool Request::handleRequest(studentSet* students, courseSet* courses, classSet* classes, classCoursesSet* classCourses) {
    if (requestType == "remove") {
        auto student = students->find(new Student(studentNumber));
        if ((*student)->removeClassCourse(classCode, courseCode, courses, classes)) {
            setRequestStatus("accepted");
            return true;
        }
        else {
            setRequestStatus("rejected");
            return false;
        }
    }
    if (requestType == "add") {
        auto student = students->find(new Student(studentNumber));
        if((*student)->addClassCourse(classCode, courseCode, courses, classes)) {
            setRequestStatus("accepted");
            return true;
        }
        else {
            setRequestStatus("rejected");
            return false;
        }
    }
    if (requestType == "change") {
        auto student = students->find(new Student(studentNumber));
        for (const auto& p : (*student)->getClassesPerCourse()) {
            if (p.second == courseCode) {
                if((*student)->removeClassCourse(p.first, p.second, courses, classes))
                    if ((*student)->addClassCourse(classCode, courseCode, courses, classes)) {
                        setRequestStatus("accepted");
                        return true;
                    }
                    else {
                        setRequestStatus("rejected");
                        return false;
                    }
                else {
                    setRequestStatus("rejected");
                    return false;
                }
            }
        }
    }
    return false;
}
void Request::archiveRequest(ostream& out) const {
    out << studentNumber << ","  << courseCode << ","
    << classCode << "," << requestType << "," << requestStatus << "," << endl;
}
