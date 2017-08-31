// Student.cpp for Heap of Students
// Created by Kyle A Peeler on 2/27/16.

#include <string>
#include <sstream>
#include "Student.h"

/*
* Name: Student()
* Purpose:
* 	Default constructor for Student(), Creates instances of Address + Date on heap
* Parameters:
* 	None
* Return Value:
* 	Returns default instance of Student()
*/
Student::Student(){
    this->fName = "Unnamed";
    this->lName = "Student";
    this->currentAddress = new Address();
    this->dateOfBirth = new Date();
    this->completionDate = new Date();
    this->creditHoursCompleted = 0;
    this->gradePointAverage = 0.0;
}//end default student constructor

/*
* Name: Student(string firstName, string lastName)
* Purpose:
* 	Overloaded constructor for Student() initializes student with specified first name and last name
* Parameters:
* 	firstName: string - the first name of the student
* 	lastName: string - the last name of the student
* Return Value:
* 	Returns initialized instance of Student with name set and default Address, DOB, and Completion Date
*/
Student::Student(string firstName, string lastName){
    this->fName = firstName;
    this->lName = lastName;
    this->currentAddress = new Address();
    this->dateOfBirth = new Date();
    this->completionDate = new Date();
    this->creditHoursCompleted = 0;
    this->gradePointAverage = 0.0;
}//end overloaded student constructor

/*
* Name: Student(const Student &original)
* Purpose:
* 	Copy constructor for student, automatically called on assignment operator between two student objects
* Parameters:
* 	const Student &original - the original student object to be copied (immutable)
* Return Value:
* 	Student - a copy of the student object passed in
*/
Student::Student(const Student &original) {
    this->fName = original.fName;
    this->lName = original.lName;
    this->currentAddress->setLine1(original.currentAddress->getLine1());
    this->currentAddress->setLine2(original.currentAddress->getLine2());
    this->currentAddress->setCity(original.currentAddress->getCity());
    this->currentAddress->setZip(original.currentAddress->getZip());
    this->currentAddress->setState(original.currentAddress->getState());
    this->dateOfBirth->setFromString(original.dateOfBirth->toString());
    this->completionDate->setFromString(original.completionDate->toString());
    this->creditHoursCompleted = original.creditHoursCompleted;
    this->gradePointAverage = original.gradePointAverage;
}//end student copy constructor

/*
* Name: ~Student()
* Purpose:
* 	Student deconstructor, automatically deletes DOB, Completion Date, and Address from Heap when Student is deleted
* Parameters:
* 	None
* Return Value:
* 	Void
*/
Student::~Student(){
    delete this->currentAddress;
    delete this->dateOfBirth;
    delete this->completionDate;
}//end deconstructor

/*
* Name: getFirstName()
* Purpose:
* 	Returns the first name of the student
* Parameters:
* 	None
* Return Value:
* 	String - the first name of the student
*/
string Student::getFirstName() {
    return this->fName;
}//end getFirstName

/*
* Name: setFirstName(string name)
* Purpose:
* 	Sets the first name of the student to the specified value
* Parameters:
* 	name: string - The first name to assign to student
* Return Value:
* 	None
*/
void Student::setFirstName(string name) {
    this->fName = name;
}//end setFirstName

/*
* Name: getLastName()
* Purpose:
* 	Returns the last name of the student
* Parameters:
* 	None
* Return Value:
* 	String - the last name of the student
*/
string Student::getLastName() {
    return this->lName;
}//end getLastName

/*
* Name: setLastName(string name)
* Purpose:
* 	Sets the last name of the student to the specified value
* Parameters:
* 	name: string - The last name to assign to student
* Return Value:
* 	None
*/
void Student::setLastName(string name) {
    this->lName = name;
}//end setLastName

/*
* Name: getFullName()
* Purpose:
* 	Returns the first name and last name of the student with a space inbetween
* Parameters:
* 	None
* Return Value:
* 	String - returns the full name of the student
*/
string Student::getFullName() {
    return getFirstName() + " " + getLastName();
}//end getFullName

/*
* Name: getAddress()
* Purpose:
* 	Returns the address object that corresponds to the student
* Parameters:
* 	None
* Return Value:
* 	Address * - Pointer to the address object of the student
*/
Address * Student::getAddress() {
    return this->currentAddress;
}//end getAddress

/*
* Name: getDOB()
* Purpose:
* 	Returns the date object that corresponds to the student's date of birth
* Parameters:
* 	None
* Return Value:
* 	Date * - Pointer to the date object of the student's date of birth
*/
Date * Student::getDOB() {
    return this->dateOfBirth;
}//end getDOB

/*
* Name: getCompletionDate()
* Purpose:
* 	Returns the date object that corresponds to the student's date of completion (graduation date)
* Parameters:
* 	None
* Return Value:
* 	Date * - Pointer to the date object of the student's graduation date
*/
Date * Student::getCompletionDate() {
    return this->completionDate;
}//end getCompletionDate

/*
* Name: getGPA()
* Purpose:
* 	Returns the GPA of the Student
* Parameters:
* 	None
* Return Value:
* 	float - the GPA of the student
*/
float Student::getGPA() {
    return this->gradePointAverage;
}//end getGPA

/*
* Name: setGPA(float GPA)
* Purpose:
* 	Sets the GPA of the student to the specified GPA
* Parameters:
* 	GPA: float - the GPA to assign to the student
* Return Value:
* 	none
*/
void Student::setGPA(float GPA) {
    this->gradePointAverage = GPA;
}//end setGPA

/*
* Name: getCreditHoursCompleted()
* Purpose:
* 	Returns the number of credit hours the student has completed
* Parameters:
* 	None
* Return Value:
* 	int - the number of credit hours the student has completed
*/
int Student::getCreditHoursCompleted() {
    return this->creditHoursCompleted;
}//end getCreditHoursCompleted

/*
* Name: setCreditHoursCompleted(int creditHours)
* Purpose:
* 	Assigns the specified number of credit hours completed to the student
* Parameters:
* 	creditHours - int: the number of credit hours to set
* Return Value:
* 	None
*/
void Student::setCreditHoursCompleted(int creditHours) {
    this->creditHoursCompleted = creditHours;
}//end setCreditHoursCompleted

/*
* Name: floatToString(float num)
* Purpose:
* 	Helper function to convert a float number to it's string representation
* Parameters:
* 	num: float - the float to convert to a string
* Return Value:
* 	string - the string representation of the float
*/
string Student::floatToString(float num){
    stringstream ss;
    ss << num;
    return ss.str();
}//end floatToString

/*
* Name: intToString(int num)
* Purpose:
* 	Helper function to convert an integer to it's string representation
* Parameters:
* 	num: int - the integer to convert to a string
* Return Value:
* 	string - the string representation of the integer
*/
string Student::intToString(int num){
    stringstream ss;
    ss << num;
    return ss.str();
}//end intToString

/*
* Name: toString()
* Purpose:
* 	Outputs the student object as a string
* Parameters:
* 	None
* Return Value:
* 	String - the string representation of a student
*/
string Student::toString() {
    return "First Name: " + this->fName + "\n" +
           "Last Name: " + this->lName + "\n" +
           "Address: " + this->currentAddress->toString() + "\n"
           "DOB: " + this->dateOfBirth->toString() + "\n" +
           "Completion Date: " + this->completionDate->toString() + "\n" +
           "GPA: " + floatToString(this->gradePointAverage) + "\n" +
           "Credit Hours Completed: " + intToString(creditHoursCompleted);
}//end toString()
