#ifndef DM_H
#define DM_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/// shape class
class shape
{
public:
      virtual ~shape(){}; // if use virtual functions, tou must have virtual dctor
      //----- You need to define virtual function in here -----//
      // (1) void get_information()
      // (2) void set_perimeter()
      // You should use above virtual functions in other class, define other function is forbidden !

      double get_perimeter() { return perimeter; }

protected:
      double perimeter;
      string name;
};

/// polygon class
class polygon : public shape
{
public:
      ~polygon() { delete[] sides; }

protected:
      double *sides;
};

/// circle class

/// triangle class

/// rectangle class

/// square class

#endif
