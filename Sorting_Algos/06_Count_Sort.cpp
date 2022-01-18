#include <iostream>
#include <string>
using namespace std;

// Return maximum element in the array
int maxElement(int* arr, int length) {
    int max = INT_MIN;

    for (int i = 0; i < length; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countSort(int* main_arr, int length) {
    int max = maxElement(main_arr, length);   // Maximum element of the array
    int* count_Arr = new int[max+1];    // Create count array of size (max element of main array +1) 
    int main_arr_Ind = 0;   // Counter for given array

    // Make all element 0 of the count array
    for (int i = 0; i < max + 1; i++)
    {
        count_Arr[i] = 0;
    }

    // Increment corresponding index in the count array
    for (int i = 0; i < length; i++)
    {
        count_Arr[main_arr[i]] = count_Arr[main_arr[i]] + 1;
    }
    
    // Traverse in count array
    for (int count_Ind = 0; count_Ind < max+1; count_Ind++)
    {
        // If value > 0 found in count array then add that index in main array 
        if(count_Arr[count_Ind]  > 0) {
            main_arr[main_arr_Ind] = count_Ind;
            count_Arr[count_Ind] = count_Arr[count_Ind] - 1;
            main_arr_Ind ++;
            count_Ind --;
        }
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
    int arr[] = {2, 54, 78, 98, 4, 7, 7};
    // int arr[] = {1,2,3,4,5,6};
    int len = sizeof(arr) / sizeof(int);

    display(arr, len);

    countSort(arr, len);
    display(arr, len);

    return 0;
}