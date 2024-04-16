#include "func.h"
#include <iostream>
#include <cmath>
using namespace std;

double length(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double s, a, b, c;
    a = length(x1, y1, x2, y2);
    b = length(x2, y2, x3, y3);
    c = length(x3, y3, x1, y1);
    s = (a + b + c) / 2;
    return sqrt(s * fabs(s - a) * fabs(s - b) * fabs(s - c));
}
double difference(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double a, b, c;
    a = length(x1, y1, x2, y2);
    b = length(x2, y2, x3, y3);
    c = length(x3, y3, x1, y1);

    return max(max(fabs(a - b), fabs(b - c)), fabs(c - a));
}