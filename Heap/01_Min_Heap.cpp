#include <iostream>
#include <string>
using namespace std;

// Create a Min-Heap using Array
class MinHeap {
    public:
    int* heap;
    int usedSize;
    int totaoSize;

    // Initialize total size of Min-Heap
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
    // Create a Min-Heap of size 10
    MinHeap heap_ptr(10);

    heap_ptr.heap[0] = 2;
    heap_ptr.usedSize ++;
    
    heap_ptr.heap[1] = 7;
    heap_ptr.usedSize ++;
    
    heap_ptr.heap[2] = 3;
    heap_ptr.usedSize ++;
    
    heap_ptr.heap[3] = 14;
    heap_ptr.usedSize ++;

    heap_ptr.display();

    return 0;
}