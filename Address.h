//Address.h
#ifndef ADDR_H_EXISTS
#define ADDR_H_EXISTS

#include <string>
using namespace std;

class Address {
  private:
    string line1;
    string line2;
    string city;
    string state;
    int zip;
    string intToString(int num);
  public:
    Address();
    ~Address();
    Address(const Address &addr);
    Address(string line1, string line2, string city, string state, int zip);
    Address(string address, string city, string state, int zip);
    string getLine1();
    void setLine1(string line);
    string getLine2();
    void setLine2(string line);
    string getCity();
    void setCity(string city);
    string getState();
    void setState(string state);
    int getZip();
    void setZip(int zip);
    string toString();
};//end address class def

#endif
