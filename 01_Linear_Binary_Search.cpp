#include <iostream>
#include <string>
using namespace std;

// Linear Search-----------------------------------------------------------------------------------
void linearSearch(int s, int array[], int element) {
    int flag = 0;
    for (int i = 0; i < s; i++)
    {
        if(array[i] == element) {
            cout << "Element Found at Index: "  << i <<endl;
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    cout << "Can't Find Element!!" <<endl;
        
}

// Binary Search-----------------------------------------------------------------------------------
void binarysearch(int s, int array[], int element) {
    int low = 0, high = s-1, mid;
    int flag = 0;

    while (low <= high)
    {
        mid = (low + high)/2;

        if(array[mid] == element) {
            cout << "Element Found at Index: "  << mid <<endl;
            flag = 1;
            break;
        }

        if(array[mid] > element) 
            high = mid - 1;
        else 
            low = mid + 1;
    }
    if(flag == 0)
    cout << "Can't Find Element!!" <<endl;   
}

int main() {

    int arr[] = {10, 15, 17, 20, 25, 27, 30, 35, 37, 40, 45, 47, 50};
    int size = sizeof(arr) / sizeof(int);
    int search = 1;

    // linearSearch(size, arr, search);
    binarysearch(size, arr, search);

    return 0;
}