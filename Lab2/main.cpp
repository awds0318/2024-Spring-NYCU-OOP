#include <iostream>
#include "func.h"
using namespace std;

int main(){
    double x1, y1, x2, y2, x3, y3;
    cout << "Point 1's coordinate:" << endl;
    cin >> x1 >> y1;
    cout << "Point 2's coordinate:" << endl;
    cin >> x2 >> y2;
    cout << "Point 3's coordinate:" << endl;
    cin >> x3 >> y3;

    cout << "=====RESULT=====" << endl;
    cout << "Side Length: " << length(x1, y1, x2, y2) <<", " << length(x2, y2, x3, y3) <<", "<< length(x3, y3, x1, y1) << endl;
    cout << "Area: " << area(x1, y1, x2, y2, x3, y3) << endl;
    cout << "Max Difference: " << difference(x1, y1, x2, y2, x3, y3) << endl;

    return 0;
}