#include <iostream>
using namespace std;

class BubbleSortArray {
private:
    int *array; 
    int size;   

public:
    BubbleSortArray(int n);
    ~BubbleSortArray();
    void bubbleSort();
    void display();
    int* findMax();
};

BubbleSortArray::BubbleSortArray(int n) {

    cout << " ** constructor executed ** " << endl ;
    size = n;
    array = new int[size];
    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }

}

BubbleSortArray::~BubbleSortArray() {

    delete[] array;
    cout << " ** Destructor executed ** ";

}

void BubbleSortArray::bubbleSort() {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void BubbleSortArray::display() {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int* BubbleSortArray::findMax() {
    int *maxPtr = &array[0]; 
    for (int i = 1; i < size; ++i) {
        if (array[i] > *maxPtr) {
            maxPtr = &array[i]; 
        }
    }
    return maxPtr; 
}

int main() {

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    BubbleSortArray *bubble_ptr ;
    BubbleSortArray arr(n);
    bubble_ptr = &arr ;
    int *max_ptr = NULL;

    // ================================================== //   

    cout << "Original array: ";
    bubble_ptr->display();
    bubble_ptr->bubbleSort();
    cout << "Sorted array: ";
    bubble_ptr->display();
    max_ptr = bubble_ptr->findMax();
    cout << "Max value in the array: " << *max_ptr << endl;

    // ================================================== //  
    return 0;

}