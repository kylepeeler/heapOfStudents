// Date.cpp
// Created by Kyle A Peeler on 2/26/16.

#include "Date.h"
#include <cstdlib>
#include <sstream>

using namespace std;

/*
* Name: Date()
* Purpose:
* 	Default constructor for Date()
* Parameters:
* 	None
* Return Value:
* 	Date - Returns default instance of date object (all values set to -1)
*/
Date::Date(){
    this->month = -1;
    this->day = -1;
    this->year = -1;
}//end constructor




/*
* Name: ~Date()
* Purpose:
* 	Deconstructor for Date() - Automatically called when Date is destroyed
* Parameters:
* 	None
* Return Value:
* 	None
*/
Date::~Date(){
}//end Deconstructor

/*
* Name: Date(string dateString)
* Purpose:
* 	Overloaded constructor for Date class
* Parameters:
* 	dateString: string - a string in the format of "mm/dd/yyyy"
* Return Value:
* 	Date - Returns initialized instance of date object with values set to
* 				 specified date
*/
Date::Date(string dateString) {
    //convert the date string to a stream
    istringstream inputDateString(dateString);
    //date string format is in mm/dd/yyyy
    //create variables to store month
    string month;
    // ... and day
    string day;
    // ... and year
    string year;
    //parse the date string like we parse other stuff
    getline(inputDateString, month, '/');
    getline(inputDateString, day, '/');
    getline(inputDateString, year);
    //convert the substrings to integer values and store them
    this->month = atoi(month.c_str());
    this->day = atoi(day.c_str());
    this->year = atoi(year.c_str());
}//end Overloaded constructor

/*
* Name: Date(int mm, int dd, int yyyy)
* Purpose:
* 	Overloaded constructor for Date class w/ integer values for day, month, yearStr
* Parameters:
* 	mm: int - month value
* 	dd: int - day value
* 	yyyy: int - year value
* Return Value:
* 	Date - Returns initialized instance of date object with values set to sepecified integers
*/
Date::Date(int mm, int dd, int yyyy){
    this->month = mm;
    this->day = dd;
    this->year = yyyy;
}//end Overloaded constructor

/*
* Name: setFromString(string dateString)
* Purpose:
* 	Sets the date object to the month, day, and year specified in the date string
* Parameters:
* 	dateString: string - the string to obtain the month, day, and year
* Return Value:
* 	None
*/
void Date::setFromString(string dateString){
    //convert the date string to a stream
    istringstream inputDateString(dateString);
    //date string format is in mm/dd/yyyy
    //create variables to store month
    string month;
    // ... and day
    string day;
    // ... and year
    string year;
    //parse the date string like we parse other stuff
    getline(inputDateString, month, '/');
    getline(inputDateString, day, '/');
    getline(inputDateString, year);
    //convert the substrings to integer values and store them
    this->month = atoi(month.c_str());
    this->day = atoi(day.c_str());
    this->year = atoi(year.c_str());
}//end setFromString

/*
* Name: getMonth()
* Purpose:
* 	returns the month value from the current date instance
* Parameters:
* 	None
* Return Value:
* 	int - the integer representation of the month, -1 if not set
*/
int Date::getMonth() {
    return this->month;
}//end getMonth

/*
* Name: getDay()
* Purpose:
* 	returns the day value from the current date instance
* Parameters:
* 	None
* Return Value:
* 	int - the integer representation of the day, -1 if not set
*/
int Date::getDay() {
    return this->day;
}//end getDay

/*
* Name: getYear()
* Purpose:
* 	returns the year value from the current date instance
* Parameters:
* 	None
* Return Value:
* 	int - the integer representation of the year, -1 if not set
*/
int Date::getYear() {
    return this->year;
}//end getYear

/*
* Name: intToString(int num)
* Purpose:
* 	Helper function to convert an integer to stringstream
* Parameters:
* 	num: int - the integer to convert to string
* Return Value:
* 	String - the string representation of the passed in integer
*/
string Date::intToString(int num){
    stringstream ss;
    ss << num;
    return ss.str();
}//end intToString

/*
* Name: toString()
* Purpose:
* 	Returns the string representation of the date in the format 'mm/dd/yyyy'
* Parameters:
* 	None
* Return Value:
* 	None
*/
string Date::toString() {
    string monthStr = intToString(this->getMonth());
    string dayStr = intToString(this->getDay());
    string yearStr = intToString(this->getYear());
    return monthStr + "/" + dayStr + "/" + yearStr;
}//end toString
