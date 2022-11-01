cmake_minimum_required(VERSION 3.23)
project(schedule)

set(CMAKE_CXX_STANDARD 14)

add_executable(schedule main.cpp headers/ClassCourse.h headers/ClassSchedule.h headers/Request.h headers/ScheduleManagement.h headers/Slot.h headers/Student.h headers/WeeklySchedule.h definitions/ClassCourse.cpp definitions/ClassSchedule.cpp definitions/Request.cpp definitions/ScheduleManagement.cpp definitions/Slot.cpp definitions/Student.cpp definitions/WeeklySchedule.cpp headers/Class.h headers/Course.h definitions/Class.cpp definitions/Course.cpp headers/StudentNew.h headers/Schedule.h definitions/Schedule.cpp definitions/StudentNew.cpp)
