//StudentDatabase.h
#ifndef STUDATABASE_H_EXISTS
#define STUDATABASE_H_EXISTS

#include "Student.h"

class StudentDatabase {
  private:
    int numStudents;
    Student * students;
    void swapStudents(Student * student1, Student  * student2);
    void swapIndex(int *a, int *b);
public:
    StudentDatabase();
    StudentDatabase(int size);
    ~StudentDatabase();
    void addStudent(Student * stu);
    void printFullStudentReport(string outputFileName);
    void printSimpleStudentReport(string outputFileName);
    void printSortedStudentReport(string outputFileName);
}; //end StudentDatabase def

#endif
