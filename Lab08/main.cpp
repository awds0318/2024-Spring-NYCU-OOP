#include <iostream>
using namespace std;

class BubbleSortArray
{

private:
    int *array; // array need to be sorted
    int size;   // array size

public:
    // (1) constructor
    BubbleSortArray(int sz) : size{sz} { array = new int[sz]; }
    // (2) destructors
    ~BubbleSortArray() { delete[] array; }
    // (3) bubble sort function : void bubbleSort();
    void bubbleSort();
    // (4) display sorted array : void display();
    void display();
    // (5) find the max number in array,
    //     The function should return " int * " which points to the max number : int* findMax();
    int *findMax();
    // (6) input the number in array
    void input();
};

void BubbleSortArray::input()
{
    for (int i = 0; i < size; ++i)
    {
        cin >> array[i];
    }
}
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

void BubbleSortArray::display()
{
    for (int i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int *BubbleSortArray::findMax()
{
    bubbleSort();
    return &array[size - 1];
}

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
    cout << "** constructor executed **" << endl;
    cout << "Enter 5 integers: ";
    bubble_ptr->input();
    cout << "Original array: ";
    bubble_ptr->display();
    cout << "Sorted array: ";
    bubble_ptr->bubbleSort();
    bubble_ptr->display();
    cout << "Max value in the array: " << *bubble_ptr->findMax() << endl;
    cout << "** Destructor executed **";
    /*                                   */

    return 0;
}