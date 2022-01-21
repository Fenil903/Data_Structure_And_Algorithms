#include <iostream>
#include <string>
using namespace std;

// Swap two values
void swapValue(int &key1, int &key2) {
    int temp = key1;
    key1 = key2;
    key2 = temp;
}

// Create a Min-Heap using Array
class MinHeap {
    public:
    int* heap;
    int usedSize;
    int totalSize;

    // Initialize total size of Min-Heap
    MinHeap(int tSize) {
        totalSize = tSize;
        usedSize = 0;
        heap = new int[totalSize];
    }

    // Return parent of given child Node
    int parent(int index) {
        return (index - 1)/2;
    }

    // Return left child of given Node
    int getLeftChild(int index) {
        return (2*index + 1);
    }
    
    // Return right child of given Node
    int getRightChild(int index) {
        return (2*index + 2);
    }

    // Insert a Node in the Min-Heap
    void insertHeap(int key) {

        // If Heap is full then we can't add any Node in the Min-Heap
        if(usedSize == totalSize) {
            cout <<"Overflow: Heap is Full!!" <<endl;
            return;
        }
        else {
            // Current Node Index
            int index = usedSize;       

            heap[usedSize] = key;
            usedSize ++;

            // After inserting a Node check the position of that
            // Node and arrange the Min-Heap acoording to it
            while(index != 0 && heap[parent(index)] > heap[index]) 
            {
                swapValue(heap[parent(index)], heap[index]);
                index = parent(index);
            }
        }
    }

    // Rearrange The Min-Heap
    void minHeapify(int rootIndex) {
        // Left child of rootIndex
        int leftChildIndex = getLeftChild(rootIndex);
        // Right child of rootIndex
        int rightChildIndex = getRightChild(rootIndex);
        int smallest = rootIndex;

        if(leftChildIndex < usedSize && heap[leftChildIndex] < heap[rootIndex])
            smallest = leftChildIndex;
        if(rightChildIndex < usedSize && heap[rightChildIndex] < heap[smallest])
            smallest = rightChildIndex;

        // If we found another smallest Node 
        // Then swap them and rearrange the Heap
        if(smallest != rootIndex) {
            swapValue(heap[smallest], heap[rootIndex]);
            minHeapify(smallest);
        }
    }

    // Remove Top element of the Min-Heap
    int removeTopElement() {
        // For empty Heap
        if(usedSize <= 0) 
            return INT_MAX;

        // Heap has only one Node(Root Node)
        else if(usedSize == 1) {
            usedSize --;
            return heap[0];
        }

        else {
            // Store Root element
            int rootElement = heap[0];  

            // Copy last Node to a Root Node
            // And remove Top Element(Node)
            heap[0] = heap[usedSize - 1];
            usedSize --;

            // Rearrange the Min-Heap
            minHeapify(0);
            return rootElement;         // Return Top Most Element
        }
    }

    // Delete a given Node from the Min-Heap
    void deleteNode(int key) {
        int keyIndex = INT_MAX;

        // Find index of given key(Node)
        for (int i = 0; i < usedSize; i++)
        {
            if(heap[i] == key) {
                keyIndex = i;
                break;
            }
        }
        
        // Key not found in the Heap
        if(keyIndex == INT_MAX) {
            cout <<"Key Not Found!" <<endl;
            return;
        }
        else {
            // Assign smallest integr value to that Node
            heap[keyIndex] = INT_MIN;

            // After Assign smallest Node check the position of that
            // Node and arrange the Min-Heap acoording to it
            // So that Node became the root Node of the Min-Heap
            while (keyIndex != 0 && heap[parent(keyIndex)] > heap[keyIndex])
            {
                swapValue(heap[parent(keyIndex)], heap[keyIndex]);
                keyIndex = parent(keyIndex);
            }

            // Remove root Node from the Min-Heap
            removeTopElement();
            cout <<key <<" removed from the Heap!!" <<endl;
        }
        
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
    MinHeap heap(10);   
    heap.insertHeap(5);
    heap.insertHeap(9);
    heap.insertHeap(3);
    heap.insertHeap(14);
    heap.insertHeap(7);
    heap.insertHeap(4);
    heap.insertHeap(2);
    heap.display();

    // int removedEle = heap.removeTopElement();
    // (removedEle != INT_MAX) ? cout <<"Romoved Element: " <<removedEle <<endl : cout <<"Heap is Empty!" <<endl;
    // heap.display();

    heap.deleteNode(7);
    heap.deleteNode(14);
    heap.display();

    return 0;
}