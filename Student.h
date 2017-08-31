//Student.h
#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS

#include <string>
#include "Date.h"
#include "Address.h"

class Student{
private:
    string fName;
    string lName;
    Address* currentAddress;
    Date* dateOfBirth;
    Date* completionDate;
    float gradePointAverage;
    int creditHoursCompleted;
    string floatToString(float num);
    string intToString(int num);
  public:
    Student();
    Student(const Student &original);
    Student(string firstName, string lastName);
    ~Student();
    string getFirstName();
    void setFirstName(string name);
    string getLastName();
    void setLastName(string name);
    string getFullName();
    Address * getAddress();
    Date * getDOB();
    Date * getCompletionDate();
    float getGPA();
    void setGPA(float GPA);
    int getCreditHoursCompleted();
    void setCreditHoursCompleted(int creditHours);
    string toString();
}; //end student class def
#endif
