#include <iostream>
#include <string>
using namespace std;

// To swap two numbers
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Return Partition Index
int partition(int* arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    
    do {    
        while (arr[i] <= pivot)    // Stop when arr[i] > pivot element
        {
            i ++;
        }
        
        while (arr[j] > pivot)    // Stop when arr[j] <= pivot element
        {
            j --;
        }

        // If i < j then swap arr[i] and arr[j] and continue untill i >=j
        if(i < j) {
            swap(&arr[i], &arr[j]); 
        }
    } while(i < j);   // Run this lopp untill i >= j

    // Swap pivot element in array with partition Index element
    swap(&arr[low], &arr[j]);

    return j;   // Return partition index
}

void display(int* arr, int l) {
    for (int i = 0; i < l; i++)
    {
        cout <<arr[i] <<" ";
    }
    cout <<endl;
}

// Quick Sort Function
void QuickSort(int* arr, int low, int high) {
    cout <<"Quick Sore Running for: " <<low <<"-" <<high <<endl;
    int partitionIndex;    // Index of pivot element.

    if (low < high) {   // Iterate QuickSort function untill the size of subarry is = 1(i.e. low >= high)
        partitionIndex = partition(arr, low, high);
        cout <<partitionIndex <<endl;
        display(arr, 6);
        QuickSort(arr, low, partitionIndex - 1);    // Running for left subarray of pivot element
        QuickSort(arr, partitionIndex + 1, high);    // Running for right subarray of pivot element
    }
}


int main() {
    int arr[] = {2, 54, 78, 98, 4, 7};
    // int arr[] = {1,2,3,4,5,6};
    int len = sizeof(arr) / sizeof(int);

    display(arr, len);

    QuickSort(arr, 0, len-1);
    display(arr, len);


    return 0;
}