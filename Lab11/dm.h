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

      virtual void get_information() = 0;
      virtual void set_perimeter() = 0;

      double get_perimeter() { return perimeter; }

protected:
      double perimeter;
      string name;
};

/// polygon class
class polygon : public shape
{
public:
      polygon(int nl) : num_of_length{nl} { sides = new double[nl]; }
      ~polygon() { delete[] sides; }

protected:
      double *sides;
      int num_of_length;
};

/// circle class
class circle : public shape
{
      const double PI = 3.14;
      double R;
      string NAME;

public:
      circle(double r, string n) : R{r}, NAME{n} {}
      void get_information();
      void set_perimeter()
      {
            if (R < 0)
            {
                  perimeter = -1;
            }
            else
            {
                  perimeter = 2 * PI * R;
            }
            name = NAME;
      }
};

/// triangle class
class triangle : public polygon
{
      string NAME;
public:
      triangle(double a, double b, double c, string n) : polygon(3), a{a}, b{b}, c{c}, NAME{n} {}
      void get_information();
      void set_perimeter()
      {
            if ((a + b > c) && (b + c > a) && (a + c > b) && (a > 0) && (b > 0) && (c > 0))
                  perimeter = a + b + c;
            else 
                  perimeter = -1;

            name = NAME;
      }

protected:
      double a, b, c;
};

/// rectangle class
class rectangle : public polygon
{
      string NAME;
public:
      rectangle(double a, double b, double c, double d, string n) : polygon(4), a{a}, b{b}, c{c}, d{d}, NAME{n} {}
      void get_information();
      void set_perimeter()
      {
            if ((a == c) && (b == d) && (a > 0) && (b > 0) && (c > 0) && (d > 0))
                  perimeter = a + b + c + d;
            else 
                  perimeter = -1;

            name = NAME;
      }

protected:
      double a, b, c, d;
};

/// square class
class square : public rectangle
{
      string NAME;
public:
      square(double a, double b, double c, double d, string n) : rectangle(a, b, c, d, n), NAME{n} {}
      void get_information();
      void set_perimeter()
      {
            if ((a == b) && (b == c) && (c == d) && (d == a) && (a > 0) && (b > 0) && (c > 0) && (d > 0))
                  perimeter = a + b + c + d;
            else 
                  perimeter = -1;

            name = NAME;
      }

};
#endif
