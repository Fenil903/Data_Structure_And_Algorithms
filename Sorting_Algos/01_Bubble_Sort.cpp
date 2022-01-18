#include <iostream>
#include <string>
using namespace std;

// To swap two numbers
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Bubble Sort function
void bubbleSort(int* arr, int length) {
    for (int i = 0; i < length-1; i++)   // For number of passes
    {
        for (int j = 0; j < length-1-i; j++)    // For comparison in each pass
        {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

// Bubble Sort Adaptive function
void bubbleSortAdaptive(int* arr, int length) {
    bool isSorted = false;

    for (int i = 0; i < length-1; i++)   // For number of passes
    {
        cout <<"Working on Pass: " <<i+1 <<endl;
        isSorted = true;
        for (int j = 0; j < length-1-i; j++)    // For comparison in each pass
        {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]); 
                isSorted = false;
            }
        }
        if(isSorted)
            return;
    }
}

void display(int* arr, int l) {
    for (int i = 0; i < l; i++)
    {
        cout <<arr[i] <<" ";
    }
    cout <<endl;
}

// Main Function
int main() {
    int arr[] = {2, 54, 78, 98, 4, 7};
    // int arr[] = {1,2,3,4,5,6};
    int len = sizeof(arr) / sizeof(int);

    display(arr, len);

    bubbleSortAdaptive(arr, len);
    display(arr, len);

    return 0;
}