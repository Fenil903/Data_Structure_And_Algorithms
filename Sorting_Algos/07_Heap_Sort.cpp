#include <iostream>
#include <string>
using namespace std;

// Swap two values
void swapValue(int &key1, int &key2) {
    int temp = key1;
    key1 = key2;
    key2 = temp;
}

// Retrun left child of the Node
int getLeftChild(int arr[], int index) {
    return (2*index + 1);
}

// Retrun right child of the Node
int getRightChild(int arr[], int index) {
    return (2*index + 2);
}

// Rearrange the Max-Heap
void heapify(int arr[], int i, int size) {
    // Left child of given Node
    int leftChild = getLeftChild(arr, i);
    // Right child of given Node
    int rightChild = getRightChild(arr, i);
    int largest = i;

    if(leftChild < size && arr[leftChild] > arr[largest])
        largest = leftChild;
    if(rightChild < size && arr[rightChild] > arr[largest])
        largest = rightChild;

    // If we found another larger Node 
    // Then swap them and rearrange the Heap
    if(largest != i) {
        swapValue(arr[largest], arr[i]);
        heapify(arr, largest, size);
    }
}

// Heap Sort algorithm
void heapSort(int arr[], int size) {

    // Build heap (rearrange array)
    for (int i = size/2 - 1; i >= 0; i--)    {
        heapify(arr, i, size);
    }

    // One by one extract an element from heap
    for (int i = size - 1; i > 0; i--)
    {
        // Move current root to end
        swapValue(arr[i], arr[0]);

        // call max heapify on the reduced heap
        heapify(arr, 0, i);
    }
}

void printHeap(int arr[], int size) {
    cout <<"Heap: ";
    for (int i = 0; i < size; i++)
    {
        cout <<arr[i] <<" ";
    }
    cout <<endl;
}

// Main Function
int main() {
    int arr[] = {14, 4, 5, 10, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printHeap(arr, size);
    heapSort(arr, size);
    printHeap(arr, size);

    return 0;
}