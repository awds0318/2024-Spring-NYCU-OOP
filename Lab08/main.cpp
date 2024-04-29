#include <iostream>
using namespace std;

class BubbleSortArray
{

private:
    int *array; // array need to be sorted
    int size;   // array size

public:
    // (1) constructor
    // (2) destructors
    // (3) bubble sort function : void bubbleSort();
    // (4) display sorted array : void display();
    // (5) find the max number in array,
    //     The function should return " int * " which points to the max number : int* findMax();
};

void BubbleSortArray::bubbleSort()
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void BubbleSortArray::display() {}
int *BubbleSortArray::findMax() {}

int main()
{

    /*     modify this block is not allowed      */

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    BubbleSortArray *bubble_ptr;
    BubbleSortArray arr(n);

    bubble_ptr = &arr;
    int *max_ptr = NULL; // point to the max number in array

    /*     modify this block is not allowed      */

    // write your code in the below block
    // only use "bubble_ptr" and "max_ptr"
    // can not initialize other parameter
    /*                                   */

    /*                                   */

    return 0;
}