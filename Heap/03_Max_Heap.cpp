#include <iostream>
#include <string>
using namespace std;

// Create a Max-Heap using Array
class MinHeap {
    public:
    int* heap;
    int usedSize;
    int totaoSize;

    // Initialize total size of Max-Heap
    MinHeap(int tSize) {
        totaoSize = tSize;
        usedSize = 0;
        heap = new int[totaoSize];
    }

    void display() {
        cout <<"Heap: ";
        for (int i = 0; i < usedSize; i++)
            cout <<heap[i] <<" ";
        cout <<endl;
    }
};

// Main Function
int main() {
    // Create a Max-Heap of size 10
    MinHeap heap_ptr(10);

    heap_ptr.heap[0] = 14;
    heap_ptr.usedSize ++;
    
    heap_ptr.heap[1] = 10;
    heap_ptr.usedSize ++;
    
    heap_ptr.heap[2] = 6;
    heap_ptr.usedSize ++;
    
    heap_ptr.heap[3] = 4;
    heap_ptr.usedSize ++;

    heap_ptr.display();

    return 0;
}