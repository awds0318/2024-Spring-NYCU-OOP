#include <iostream>
using namespace std;

int main(){
    int matrixA[3][3];
    int operation;
    cout << "Input Matrix A:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
        cin >> matrixA[i][j];
        }
    }
    cout << "Matrix A:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
        cout << "   " << matrixA[i][j];
        }
        cout << endl;
    }


    while (1)
    {
        cout << "Operation: ";
        cin >> operation;
        cout << operation << endl;
        if (operation == 1)
        {
            cout << "Matrix A:" << endl;
            int temp[3][3];
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                temp[i][j] = matrixA[j][i];
                cout << "   " << temp[i][j];
                }
                cout << endl;
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                matrixA[i][j] = temp[i][j];
                }
            }
        }
        else // if(operation == 2)
        {   
            int matrixB[2][3];
            cout << "Input Matrix B:" << endl;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                cin >> matrixB[i][j];
                }
            }
            cout << "Matrix B:"<< endl;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                cout << "   " << matrixB[i][j];
                }
                cout << endl;
            }
            cout << "Matrix A X Matrix B:" << endl;
            for (int i = 0; i < 3; i++)
            {   
                cout << "   " << matrixA[i][0] * matrixB[0][0] + matrixA[i][1] * matrixB[1][0] + matrixA[i][2] * matrixB[2][0];
                cout << "   " << matrixA[i][0] * matrixB[0][1] + matrixA[i][1] * matrixB[1][1] + matrixA[i][2] * matrixB[2][1] << endl;
            }
            break;
        }
    }
    
    return 0;
}