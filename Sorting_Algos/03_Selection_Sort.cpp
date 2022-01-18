#include <iostream>
#include <string>
using namespace std;

// To swap two numbers
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Selection Sort function
void selectionSort(int* arr, int length) {
    int indexOfMin;

    for (int i = 0; i < length-1; i++)    // For number of passes
    {
        indexOfMin = i;
        for (int j = i+1; j <= length-1; j++)    // comparison in each pass
        {
            if(arr[j] < arr[indexOfMin]) 
                indexOfMin = j;
        }
        swap(&arr[i], &arr[indexOfMin]);
    }    
}

void display(int* arr, int l) {
    for (int i = 0; i < l; i++)
    {
        cout <<arr[i] <<" ";
    }
    cout <<endl;
}

int main() {
    int arr[] = {2, 54, 78, 98, 4, 7};
    // int arr[] = {1,2,3,4,5,6};
    int len = sizeof(arr) / sizeof(int);

    display(arr, len);

    selectionSort(arr, len);
    display(arr, len);

    return 0;
}