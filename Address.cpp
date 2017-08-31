//Address.cpp
//Written by Kyle A. Peeler
//February 29, 2016

#include <string>
#include <sstream>
#include "Address.h"

using namespace std;
/*
* Name: Address()
* Purpose:
* 	Default constructor for Address()
* Parameters:
* 	None
* Return Value:
* 	Returns default instance of Address object
*/
Address::Address() {
  this->line1 = "Unspecified Address";
  this->line2 = "";
  this->city = "Unspecified City";
  this->state = "Unspecified State";
  this->zip = -1;
}//end def constructor

/*
* Name: ~Address()
* Purpose:
* 	Deconstructor for Address(), Automatically called when Address object is deleted
* Parameters:
* 	None
* Return Value:
* 	None
*/
Address::~Address() {
}//end Deconstructor

/*
* Name: Address(const Address &addr)
* Purpose:
* 	Copy constructor for Address() objects, is called when setting two addresses equal to each other
* Parameters:
* 	const Address &addr - the original value to be copied (immutable)
* Return Value:
* 	Address - copy of the original address passed in
*/
Address::Address(const Address &addr) {
    this->line1 = addr.line1;
    this->line2 = addr.line2;
    this->city = addr.city;
    this->state = addr.state;
    this->zip = addr.zip;
}//end copy constructor

/*
* Name: Address() - overloaded constructor
* Purpose:
* 	Overloaded Address constructor that initializes the Address object with the
* 	specified values
* Parameters:
* 	line1: string - Stores the first line of the address
* 	line2: string - Stores the second line of the address
* 	city: string - Stores the city line of the address
* 	state: string - Stores the state line of the address
* 	zip: int - Stores the zip code of the address
* Return Value:
* 	Address - returns an initialized Address object with the set Parameters
*/
Address::Address(string line1, string line2, string city, string state, int zip) {
    this->line1 = line1;
    this->line2 = line2;
    this->city = city;
    this->state = state;
    this->zip = zip;
} // end overloaded constructor

/*
* Name: Address() - overloaded constructor
* Purpose:
* 	Overloaded Address constructor that initializes the Address object with the
* 	specified values, this constructor assumes line2 is empty
* Parameters:
* 	line1: string - Stores the first line of the address
* 	city: string - Stores the city line of the address
* 	state: string - Stores the state line of the address
* 	zip: int - Stores the zip line of the address
* Return Value:
* 	Address - returns an initialized Address object with the set Parameters
*/
Address::Address(string address, string city, string state, int zip) {
    this->line1 = address;
    this->line2 = "";
    this->city = city;
    this->state = state;
    this->zip = zip;
}// end overloaded constructor

/*
* Name: getLine1()
* Purpose:
* 	Returns the first line of the address
* Parameters:
* 	None
* Return Value:
* 	String - The first line of the address
*/
string Address::getLine1() {
  return this->line1;
}//end getLine1

/*
* Name: setLine1(string line)
* Purpose:
* 	Sets the first address line to the specified value
* Parameters:
* 	line: string - The value you want to set to address line 1
* Return Value:
* 	None
*/
void Address::setLine1(string line) {
  this->line1 = line;
}//end setline1

/*
* Name: getLine2()
* Purpose:
* 	Returns the second line of the address
* Parameters:
* 	None
* Return Value:
* 	String - The second line of the address
*/
string Address::getLine2() {
  return this->line2;
}//end getline2

/*
* Name: setLine2(string line)
* Purpose:
* 	Sets the second address line to the specified value
* Parameters:
* 	line: string - The value you want to set to address line 2
* Return Value:
* 	None
*/
void Address::setLine2(string line) {
  this->line2 = line;
}//end setline2

/*
* Name: getCity()
* Purpose:
* 	Returns the city of the address
* Parameters:
* 	None
* Return Value:
* 	String - The city of the address
*/
string Address::getCity() {
  return this->city;
}//end getCity

/*
* Name: setCity(string city)
* Purpose:
* 	Sets the city of the address to the specified value
* Parameters:
* 	city: string - The value you want to set to city
* Return Value:
* 	None
*/
void Address::setCity(string city) {
  this->city = city;
}//end setCity


/*
* Name: getState()
* Purpose:
* 	Returns the state of the address
* Parameters:
* 	None
* Return Value:
* 	String - The state of the address
*/
string Address::getState() {
  return this->state;
}//end getState

/*
* Name: setState(string state)
* Purpose:
* 	Sets the state of the address to the specified value
* Parameters:
* 	state: string - The value you want to set to state
* Return Value:
* 	None
*/
void Address::setState(string state) {
  this->state = state;
}//end setState

/*
* Name: getZip()
* Purpose:
* 	Returns the zip code of the address
* Parameters:
* 	None
* Return Value:
* 	int - the zip code of the address
*/
int Address::getZip() {
  return this->zip;
}//end getZip

/*
* Name: setZip(int zip)
* Purpose:
* 	Sets the zip code of the address to the specified value
* Parameters:
* 	zip: int - The value you want to set to the zip code
* Return Value:
* 	None
*/
void Address::setZip(int zip) {
  this->zip = zip;
}

/*
* Name: intToString(int num)
* Purpose:
* 	Helper function to convert integer values to string
* Parameters:
* 	num: int - the integer to convert to string
* Return Value:
* 	String - the string representation of the integer passed in
*/
string Address::intToString(int num){
    stringstream ss;
    ss << num;
    return ss.str();
}//end intToString

/*
* Name: toString()
* Purpose:
* 	Prints out the string representation of the address, skips Address Line 2 if empty
* Parameters:
* 	None
* Return Value:
* 	String - the string value of the address object
*/
string Address::toString() {
    if (this->getLine2() != ""){
        return this->getLine1() + ", " + this->getLine2() + ", " + this->getCity() + ", " + this->getState() + " " + intToString(this->getZip());
    }else{
        return this->getLine1() + ", " + this->getCity() + ", " + this->getState() + " " + intToString(this->getZip());
    }
}//end toString
