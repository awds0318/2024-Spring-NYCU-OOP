#include <iostream>
using namespace std;

// for 3x3 matrix
void input_matrix(int matrix[][3], int a = 3, int b = 3);
void print_matrix(int matrix[][3], int a = 3, int b = 3);

// for 3x2 matrix
void input_matrix(int matrix[][2], int a = 3, int b = 2);
void print_matrix(int matrix[][2], int a = 3, int b = 2);

int main()
{
    int matrixA[3][3];
    int operation;
    cout << "Input Matrix A:" << endl;
    input_matrix(matrixA);
    cout << "Matrix A:" << endl;
    print_matrix(matrixA);

    while (1)
    {
        cout << "Operation: ";
        cin >> operation;
        if (operation == 1)
        {
            cout << "Matrix A:" << endl;
            // transpose
            int temp[3][3];
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    temp[i][j] = matrixA[j][i];
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    matrixA[i][j] = temp[i][j];
                }
            }
            print_matrix(matrixA);
        }
        else // if(operation == 2)
        {
            int matrixB[3][2];
            cout << "Input Matrix B:" << endl;
            input_matrix(matrixB);
            cout << "Matrix B:" << endl;
            print_matrix(matrixB);

            cout << "Matrix A X Matrix B:" << endl; // 3x3 * 3x2 (ixk * kxj)
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    int value{0};
                    for (int k = 0; k < 3; k++)
                    {
                        value += matrixA[i][k] * matrixB[k][j];
                    }
                    cout << "   " << value;
                }
                cout << endl;
            }
            break;
        }
    }
    return 0;
}

void input_matrix(int matrix[][3], int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void input_matrix(int matrix[][2], int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void print_matrix(int matrix[][3], int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << "   " << matrix[i][j];
        }
        cout << endl;
    }
}

void print_matrix(int matrix[][2], int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << "   " << matrix[i][j];
        }
        cout << endl;
    }
}
