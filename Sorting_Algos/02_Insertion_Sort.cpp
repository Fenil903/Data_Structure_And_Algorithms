#include <iostream>
#include <string>
using namespace std;

// Insertion Sort Function
void insertionSort(int* arr, int length) {

    for (int i = 1; i <= length - 1; i++)   // For number of passes
    {
        int key = arr[i];
        int j = i-1;
        cout <<"Working on Pass: " <<i <<endl;
        while (arr[j] > key && j >=0)   // Comparison in each pass
        {
            arr[j+1] = arr[j];
            j --;
        }
        arr[j+1] = key;     
    }    
}

// Insertion Sort Adaptive Function
void insertionSortAdaptive(int* arr, int length) {
    bool isSorted = false;

    for (int i = 1; i <= length - 1; i++)   // For number of passes
    {
        isSorted = true;
        int key = arr[i];
        int j = i-1;
        cout <<"Working on Pass: " <<i <<endl;
        while (arr[j] > key && j >=0)   // Comparison in each pass
        {
            arr[j+1] = arr[j];
            j --;
            isSorted = false;
        }
        arr[j+1] = key; 
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
    // int arr[] = {2, 54, 78, 98, 4, 7};
    int arr[] = {1,2,3,4,5,6};
    int len = sizeof(arr) / sizeof(int);

    display(arr, len);

    insertionSort(arr, len);
    display(arr, len);

    return 0;
}