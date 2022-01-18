#include <iostream>
#include <string>
using namespace std;

void display(int* arr, int low, int l) {
    for (int i = low; i <= l; i++)
    {
        cout <<arr[i] <<" ";
    }
    cout <<endl;
}

// Sort Algorithm
void merge(int* arr, int mid, int low, int high) {
    // cout <<"Merge Fun Running for(mid, low, high): " <<mid <<", " <<low <<", " <<high <<endl;

    int i = low, j = mid + 1, k =low;   // i for 1st subarray, j for 2nd subarray, k for new temp array
    int* arr_temp = new int[high+1];    // Create temporary array

    while (i <= mid && j <= high)   // Iterate untill one of subarray became empty 
    {
        // If the value of left subarray is small then store in the new array
        // (or else store rigth subarray value)
        if(arr[i] < arr[j]) { 
            arr_temp[k] = arr[i];
            i ++;
            k ++;
        }
        else {
            arr_temp[k] = arr[j];
             j ++;
             k ++;
        }
    }

    // If right subarray became empty then store remain left subarray elements in new array
    while (i <= mid)
    {
        arr_temp[k] = arr[i];
        i ++;
        k ++;
    }

    // If left subarray became empty then store remain right subarray elements in new array
    while (j <= high)
    {
        arr_temp[k] = arr[j];
        j ++;
        k ++;
    }
    
    // Copy the temporary(new) array to original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = arr_temp[i];
    }   
}

// Merge Sort Function
void mergeSort(int* arr, int low, int high) {
    // cout <<"Merge sort Running for: " <<low <<"<->" <<high <<endl;
    int mid;
    if(low < high) {       // Iterate MergeSort function untill the size of subarry is = 1(i.e. low >= high)
        mid = (low + high) / 2;

        mergeSort(arr, low, mid);    // Running for left subarray
        mergeSort(arr, mid+1, high);    // Running for right subarray

        // display(arr, low, high);
        merge(arr, mid, low, high);    // Sort that subarrays
    }
}

int main() {
    int arr[] = {2, 54, 78, 98, 4, 7, 4, 43, 54, 76, 2, 1};
    // int arr[] = {1,2,3,4,5,6};
    int len = sizeof(arr) / sizeof(int);

    display(arr, 0, len-1);

    mergeSort(arr, 0, len-1);
    display(arr, 0, len-1);

    return 0;
}