#include"dm.h"

/// member functions of circle class

void circle::get_information()
{
     cout<<"NAME: "<<setw(8)<<name<<", "<<"PERIMETER: "<<setw(8)<<perimeter<<", "<<"TYPE: circle"<<endl;
}

circle::circle(double r, string n){
     radius = r;
     name = n;
}

void circle::set_perimeter()
{
     if(radius < 0)
          perimeter = -1;
     else 
          perimeter = 2 * 3.14 * radius;
}


///member functions of triangle class
void triangle::get_information()
{
     cout<<"NAME: "<<setw(8)<<name<<", "<<"PERIMETER: "<<setw(8)<<perimeter<<", "<<"TYPE: triangle"<<endl;
}

triangle::triangle(double a, double b, double c, string n){
     sides = new double[3];
     sides[0] = a;
     sides[1] = b;
     sides[2] = c;
     name = n;
}

void triangle::set_perimeter()
{
     if(sides[0]+sides[1]<=sides[2] || sides[0]+sides[2]<=sides[1] || sides[2]+sides[1]<=sides[0] || sides[0] < 0 ||sides[1] < 0 || sides[2] < 0 )
          perimeter = -1;
     else 
          perimeter = sides[0]+sides[1]+sides[2];
}


///member functions of rectangle class
void rectangle::get_information()
{
     cout<<"NAME: "<<setw(8)<<name<<", "<<"PERIMETER: "<<setw(8)<<perimeter<<", "<<"TYPE: rectangle"<<endl;
}

rectangle::rectangle(double a, double b, double c, double d, string n){
     sides = new double[4];
     sides[0] = a;
     sides[1] = b;
     sides[2] = c;
     sides[3] = d;
     name = n;
}

void rectangle::set_perimeter()
{
     if(sides[0] != sides[2] || sides[1] != sides[3] || sides[0] < 0 ||sides[1] < 0 || sides[2] < 0 || sides[3] < 0 )
          perimeter = -1;
     else 
          perimeter = sides[0]+sides[1]+sides[2]+sides[3];
}


/// member functions of square class
void square::get_information()
{
     cout<<"NAME: "<<setw(8)<<name<<", "<<"PERIMETER: "<<setw(8)<<perimeter<<", "<<"TYPE: square"<<endl;
}


void square::set_perimeter()
{
     if(sides[0] != sides[1] || sides[0] != sides[2] || sides[0] != sides[3] || sides[1] != sides[2] || sides[1] != sides[3] || sides[2] != sides[3] || sides[0] < 0 ||sides[1] < 0 || sides[2] < 0 || sides[3] < 0 )
          perimeter = -1;
     else 
          perimeter = sides[0]+sides[1]+sides[2]+sides[3];
}

