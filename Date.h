//Date.h
#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS

#include <string>

using namespace std;

class Date{
  private:
    int month;
    int day;
    int year;
    string intToString(int num);
  public:
    Date();
    ~Date();
    Date(int mm, int dd, int yyyy);
    Date(string dateString);
    void setFromString (string dateString);
    int getMonth();
    int getDay();
    int getYear();
    string toString();
};//end date class def

#endif
