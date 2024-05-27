#include "dm.h"
#include <fstream>
#include <string>
#include <vector>
int main(int argc, char *argv[])
{
    //========================= Coding in here =========================//
    ///----- parse file -----//
    // ifstream ifs("pattern1.txt");
    ifstream ifs(argv[1]);

    if (ifs.fail())
    {
        cout << "Fail to open file" << endl;
        exit(1);
    }

    int num_of_shapes, nTri{0}, nRec{0}, nSqu{0}, nCir{0};
    ifs >> num_of_shapes;

    shape **sarry = new shape*[num_of_shapes];

    for (int i = 0; i < num_of_shapes; ++i)
    {
        string NAME, TYPE;
        ifs >> NAME >> TYPE;
        double a, b, c, d;

        if (TYPE == "triangle")
        {
            nTri += 1;

            ifs >> a >> b >> c;

            sarry[i] = new triangle(a, b, c, NAME);
            sarry[i] -> set_perimeter();
        }

        if (TYPE == "rectangle")
        {
            nRec += 1;

            ifs >> a >> b >> c >> d;

            sarry[i] = new rectangle(a, b, c, d, NAME);
            sarry[i] -> set_perimeter();
        }

        if (TYPE == "square")
        {
            nSqu += 1;

            ifs >> a >> b >> c >> d;

            sarry[i] = new square(a, b, c, d, NAME);
            sarry[i] -> set_perimeter();
        }

        if (TYPE == "circle")
        {
            nCir += 1;

            ifs >> a;
            
            circle cir(a, NAME);
            circle *ccir = &cir;

            sarry[i] = new circle(a, NAME);
            sarry[i] -> set_perimeter();
        }

    }
    

    //=========================== Coding end ===========================//

    ///----- print Info -----//
    cout << "[# of each shape]" << endl;
    cout << "Triangle: " << nTri << endl;
    cout << "Rectangle: " << nRec << endl;
    cout << "Square: " << nSqu << endl;
    cout << "Circle: " << nCir << endl;
    cout << endl;

    double perimeter;

    cout << "[Legal]" << endl;

    for (int i = 0; i < num_of_shapes; ++i)
    {
        perimeter = sarry[i] -> get_perimeter();
        if(perimeter == -1) continue;
        else sarry[i] -> get_information();
    }
    

    cout << "[Illegal]" << endl;
    for (int i = 0; i < num_of_shapes; ++i)
    {
        perimeter = sarry[i] -> get_perimeter();
        if(perimeter != -1) continue;
        else sarry[i] -> get_information();
    }

    delete [] sarry;

    return 0;
}
