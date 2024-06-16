#ifndef DM_H
#define DM_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;



///shape class
class shape
{
      public:
            virtual ~shape(){};
		virtual void get_information()=0;
		virtual void set_perimeter()=0;
            double get_perimeter(){return perimeter;}
      protected:
		double perimeter;
		string name;

};

///polygon class
class polygon:public shape
{
      public:
            ~polygon(){delete[] sides;}
      protected:
            double* sides;

};

///circle class

class circle:public shape
{
      public:
            circle():radius(0){name="NO NAME";}
            circle(double r, string n);
            void get_information();
		void set_perimeter();
      protected:
            double radius;

};
    


///triangle class

class triangle:public polygon
{
      public:
            triangle(){name="NO NAME";}
            triangle(double a, double b, double c, string n);
            void get_information();
		void set_perimeter();

};




///rectangle class
class rectangle:public polygon
{
      public:
            rectangle(){name="NO NAME";}
            rectangle(double a, double b, double c, double d, string n);
            void get_information();
		void set_perimeter();

};





///square class
class square:public rectangle
{
      public:
            square():rectangle(){}
            square(double a, double b, double c, double d, string n):rectangle(a, b, c, d, n){};
            void get_information();
		void set_perimeter();

};





#endif


