// StudentDatabase.cpp
// Created by Kyle A Peeler on 2/28/16.
//

#include <string>
#include <iostream>
#include <fstream>
#include "StudentDatabase.h"

/*
* Name: StudentDatabase()
* Purpose:
* 	the default constructor for a student database, initializes database of size 0
* Parameters:
* 	None
* Return Value:
* 	StudentDatabase - initialized instance of a student database of size 0
*/
StudentDatabase::StudentDatabase() {
    this->numStudents = 0;
    students = new Student[numStudents];
}//end StudentDatabase

/*
* Name: StudentDatabase(int size)
* Purpose:
* 	Overloaded constructor for a student database, initializes database to specified size
* Parameters:
* 	size - int: the size to initialize the student database to
* Return Value:
* 	StudentDatabase - initialized instance of a student database of size n
*/
StudentDatabase::StudentDatabase(int size) {
    this->numStudents = size;
    students = new Student[numStudents];
}//end StudentDatabase overloaded constructor

/*
* Name: ~StudentDatabase()
* Purpose:
* 	StudentDatabase Deconstructor - Automatically called when a student database is deleted
* Parameters:
* 	None
* Return Value:
* 	None
*/
StudentDatabase::~StudentDatabase() {
    delete[] students;
}//end StudentDatabase Deconstructor

/*
* Name: addStudent
* Purpose:
* 	Adds a student to the current instance of the student database
* Parameters:
* 	student: Student * - The student pointer to add to the database
* Return Value:
* 	None
*/
void StudentDatabase::addStudent(Student* stu) {
    //create a new student array with new size
    Student * tmpStudents = new Student[numStudents + 1];
    //copy each students data
    for (int i = 0; i < numStudents; i++){
        tmpStudents[i].setFirstName(this->students[i].getFirstName());
        tmpStudents[i].setLastName(this->students[i].getLastName());
        tmpStudents[i].getAddress()->setLine1(this->students[i].getAddress()->getLine1());
        tmpStudents[i].getAddress()->setLine2(this->students[i].getAddress()->getLine2());
        tmpStudents[i].getAddress()->setCity(this->students[i].getAddress()->getCity());
        tmpStudents[i].getAddress()->setZip(this->students[i].getAddress()->getZip());
        tmpStudents[i].getAddress()->setState(this->students[i].getAddress()->getState());
        tmpStudents[i].getDOB()->setFromString(this->students[i].getDOB()->toString());
        tmpStudents[i].getCompletionDate()->setFromString(this->students[i].getDOB()->toString());
        tmpStudents[i].setGPA(this->students[i].getGPA());
        tmpStudents[i].setCreditHoursCompleted(this->students[i].getCreditHoursCompleted());
    }//end interating through students
    //now copy over the new students data
    tmpStudents[numStudents].setLastName(stu->getLastName());
    tmpStudents[numStudents].setFirstName(stu->getFirstName());
    tmpStudents[numStudents].getAddress()->setLine1(stu->getAddress()->getLine1());
    tmpStudents[numStudents].getAddress()->setLine2(stu->getAddress()->getLine2());
    tmpStudents[numStudents].getAddress()->setCity(stu->getAddress()->getCity());
    tmpStudents[numStudents].getAddress()->setState(stu->getAddress()->getState());
    tmpStudents[numStudents].getAddress()->setZip(stu->getAddress()->getZip());
    tmpStudents[numStudents].getDOB()->setFromString(stu->getDOB()->toString());
    tmpStudents[numStudents].getCompletionDate()->setFromString(stu->getCompletionDate()->toString());
    tmpStudents[numStudents].setGPA(stu->getGPA());
    tmpStudents[numStudents].setCreditHoursCompleted(stu->getCreditHoursCompleted());
    //free the old students pointer
    delete [] students;
    //set the students pointer to the new array
    students = tmpStudents;
    //increase number of students
    this->numStudents++;
}//end addStudent

/*
* Name: printFullStudentReport(string outputFileName)
* Purpose:
* 	Prints out the information of each student, including full name, address,
* 	date of birth, date of completion, GPA, and credit hours completed, outputs
* 	to the specified file
* Parameters:
* 	outputFileName: string - the file name to output the full student report to
* Return Value:
* 	None
*/
void StudentDatabase::printFullStudentReport(string outputFileName) {
    //delete any existing full reports before we make a new one
    remove(outputFileName.c_str());
    //create instance of ofstream
    ofstream outFile;
    //open our output file
    outFile.open(outputFileName.c_str());
    for (int i = 0; i < this->numStudents; i++){
        //print the header for a student
        outFile << "Student #" << i + 1 << endl << "------------" << endl << this->students[i].toString() << endl << "\n";
    }//end interate through all students
    //close the file so we can open it in other programs
    outFile.close();
    //output to the console where the full student report is located
    cout << "Full Student Report Created @ ./" << outputFileName << endl;
}//end fullStudentReport

/*
* Name: printSimpleStudentReport(string outputFileName)
* Purpose:
* 	Prints out the full name of each student, outputs to the specified file
* Parameters:
* 	outputFileName: string - the file name to output the full student report to
* Return Value:
* 	None
*/
void StudentDatabase::printSimpleStudentReport(string outputFileName){
    //delete any existing simple reports before we can make a new one
    remove(outputFileName.c_str());
    //create instance of ofstream
    ofstream outFile;
    //open our output file
    outFile.open(outputFileName.c_str());
    for (int i = 0; i < this->numStudents; i++){
        //print the header to output a name
        outFile << "Student #" << i + 1 << endl << "------------" << endl << this->students[i].getFullName() << endl << "\n";
    }//end iterate through all students
    //close the file so we can open it in other programs
    outFile.close();
    //output to the console where the short student report is located
    cout << "Simple Student Report Created @ ./" << outputFileName << endl;
}//end printSimpleStudentReport

/*
* Name: swapIndex(int* a, int*b)
* Purpose:
* 	Basic swap helper function to be used on the sorting algorithm to sort the names of students
* Parameters:
* 	a: int * - pointer to first integer to swap
* 	b: int * - pointer to second integer to swap
* Return Value:
* 	None
*/
void StudentDatabase::swapIndex(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}//end swapIndex

/*
* Name: printSortedStudentReport(string outputFileName)
* Purpose:
* 	Prints the sorted list of students in alphabetical order, outputs to specified file
* Parameters:
* 	outputFileName: string - the name of the file to output the alphabetized list
* Return Value:
* 	None
*/
void StudentDatabase::printSortedStudentReport(string outputFileName){
    //create an array of all of the indexes
    int studentIndexes[this->numStudents];
    for (int i = 0; i < this->numStudents; i++){
        //before we sort the list, each index corresponds to the original student assigned
        studentIndexes[i] = i;
    }//end for
    //bubblesort implementation
    for (int j = 0; j < this->numStudents - 1; j++){
        for (int k = 0; k < this->numStudents - 1; k++){
          //if the full name is bigger than the next largest name, swap the indexes (NOT THE POINTERS)
            if (this->students[studentIndexes[k]].getFullName() > this->students[studentIndexes[k + 1]].getFullName()){
                swapIndex(&studentIndexes[k], &studentIndexes[k + 1]);
            }//end if
        }//end for
    }//end bubblesort
    //delete any existing sorted reports before we can make a new one
    remove(outputFileName.c_str());
    //create instance of ofstream
    ofstream outFile;
    //open our output file
    outFile.open(outputFileName.c_str());
    //iterate through the sorted names using the sorted index array
    for (int s = 0; s < this->numStudents; s++){
        //output the sorted student name + header
        outFile << "Sorted Student #" << s + 1 << endl << "----------------" << endl << this->students[studentIndexes[s]].getFullName() << endl << "\n";
    }//end for
    //close the file so it can be opened in other programs
    outFile.close();
    //output to the console so the user knows the file was created
    cout << "Sorted Student Report Created @ ./" << outputFileName << endl;
}//end printSortedStudentReport
