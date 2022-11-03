cmake_minimum_required(VERSION 3.23)
project(schedule)

set(CMAKE_CXX_STANDARD 14)

add_executable(schedule main.cpp headers/Request.h headers/Slot.h definitions/Request.cpp definitions/Slot.cpp headers/Class.h headers/Course.h definitions/Class.cpp definitions/Course.cpp headers/Student.h headers/Schedule.h definitions/Schedule.cpp definitions/Student.cpp definitions/functions.cpp headers/functions.h)
