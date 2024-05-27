#include "dm.h"

/// member functions of circle class

void circle::get_information()
{
     cout << "NAME: " << setw(8) << name << ", " << "PERIMETER: " << setw(8) << perimeter << ", " << "TYPE: circle" << endl;
}

/// member functions of triangle class
void triangle::get_information()
{
     cout << "NAME: " << setw(8) << name << ", " << "PERIMETER: " << setw(8) << perimeter << ", " << "TYPE: triangle" << endl;
}

/// member functions of rectangle class
void rectangle::get_information()
{
     cout << "NAME: " << setw(8) << name << ", " << "PERIMETER: " << setw(8) << perimeter << ", " << "TYPE: rectangle" << endl;
}

/// member functions of square class
void square::get_information()
{
     cout << "NAME: " << setw(8) << name << ", " << "PERIMETER: " << setw(8) << perimeter << ", " << "TYPE: square" << endl;
}
