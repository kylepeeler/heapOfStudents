cmake_minimum_required(VERSION 3.5)
project(heapOfStudents)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Address.cpp
    Address.h
    Date.cpp
    Date.h
    main.cpp
    Makefile
    shortReport.txt
    Student.cpp
    Student.h
    StudentDatabase.cpp
    StudentDatabase.h
    students.dat)

add_executable(heapOfStudents ${SOURCE_FILES})