// main.cpp
// Created by Kyle A Peeler on 3/4/16.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "StudentDatabase.h"

using namespace std;

/*
* Name: loadStudentDBFromFile
* Purpose:
* 	Loads the StudentDatabase with the information from the specified file
* Parameters:
* 	filename: string - the filename containing the student information
* 	studentDatabase: studentDatabase* - the pointer to the student database to
* 																			load information into
* Return Value:
* 	none
*/
void loadStudentDBFromFile(string fileName, StudentDatabase* studentDatabase){
    //create instance of the input file stream
    ifstream inputFile;
    //open the specified file name
    inputFile.open(fileName.c_str());
    if (inputFile.fail()){
        //output an error if we can't open the file
        cout << "Error opening 'students.dat', please check if the file exists and try again." << endl;
    }else{
        //else we got the file loaded!
        //dummy variable to hold the first line (header)
        string headerLine;
        //variable to hold the current line we are parsing
        string line;
        //eat the first line because it is always the header line
        getline(inputFile, headerLine);
        //loop until end of students.dat
        while(getline(inputFile, line)){
            //convert the line to an input stream so we can parse the line individually
            istringstream iss(line);
            //after the first line lets parse
            //separate line into strings representing each piece
            string inFName;
            string inLName;
            string inStreetAddress;
            string inAddress2;
            string inCity;
            string inState;
            string inZip;
            string inBirthday;
            string inGradDate;
            string inGPA;
            string inCredHours;
            //parse the line and store the information in it's respective variable
            //everything is delimited by a comma except for the last item
            getline(iss, inLName, ',');
            getline(iss, inFName, ',');
            getline(iss, inStreetAddress, ',');
            getline(iss, inAddress2, ',');
            getline(iss, inCity, ',');
            getline(iss, inState, ',');
            getline(iss, inZip, ',');
            getline(iss, inBirthday, ',');
            getline(iss, inGradDate, ',');
            getline(iss, inGPA, ',');
            getline(iss, inCredHours);
            //create a new student object
            Student * newStudent = new Student(inFName, inLName);
            //initialize the new student info
            newStudent->getAddress()->setLine1(inStreetAddress);
            newStudent->getAddress()->setLine2(inAddress2);
            newStudent->getAddress()->setCity(inCity);
            newStudent->getAddress()->setState(inState);
            newStudent->getAddress()->setZip(atoi(inZip.c_str()));
            newStudent->getDOB()->setFromString(inBirthday);
            newStudent->getCompletionDate()->setFromString(inGradDate);
            newStudent->setGPA((float) atof(inGPA.c_str()));
            newStudent->setCreditHoursCompleted(atoi(inCredHours.c_str()));
            //add the student to the database
            studentDatabase->addStudent(newStudent);
            //delete the temp student we added to the database since (s)he is now
            //added
            delete newStudent;
        }//end while of parsing
        //close the input file after we write it
        inputFile.close();
    }//end else, opened the file okay
}//end loadStudentDBFromFile

/*
* Name: main()
* Purpose:
* 	The main function of the program, starts the program when it is run
* Parameters:
* 	None
* Return Value:
* 	int - status code of the program, typically 0 (all okay)
*/
int main() {
    //create our student database on the heap
    StudentDatabase* studentDB = new StudentDatabase();
    //load the student database with the info from the file
    loadStudentDBFromFile("students.dat", studentDB);
    //output a full student report to the file namedfullReport.txt
    studentDB->printFullStudentReport("fullReport.txt");
    //output a student report with only names to the file named shortReport.txt
    studentDB->printSimpleStudentReport("shortReport.txt");
    //output a student report that is sorted, named alphaReport.txt
    studentDB->printSortedStudentReport("alphaReport.txt");
    //delete the studentDB when the program is done
    delete studentDB;
}//end main
