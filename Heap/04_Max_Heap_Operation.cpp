#include <iostream>
#include <string>
using namespace std;

// Swap two values
void swapValue(int &key1, int &key2) {
    int temp = key1;
    key1 = key2;
    key2 = temp;
}

// Create a Max-Heap using Array
class MaxHeap {
    public:
    int* heap;
    int usedSize;
    int totalSize;

    // Initialize total size of Max-Heap
    MaxHeap(int tSize) {
        totalSize = tSize;
        usedSize = 0;
        heap = new int[totalSize];
    }

    // Return parent of given child Node
    int parent(int index) {
        return (index - 1)/2;
    }
    
    int getLeftChild(int index) {
        return (2*index + 1);
    }

    int getRightChild(int index) {
        return (2*index + 2);
    }

    // Insert a Node in the Max-Heap
    void insertHeap(int key) {

        // If Heap is full then we can't add any Node in the Max-Heap
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
            // Node and arrange the Max-Heap acoording to it
            while(index != 0 && heap[parent(index)] < heap[index]) {
                swapValue(heap[parent(index)], heap[index]);
                index = parent(index);
            } 
        }
    }

    // Rearrange The Max-Heap
    void maxHeapify(int rootIndex) {
        // Left child of rootIndex
        int leftChildIndex = getLeftChild(rootIndex);
        // Right child of rootIndex
        int rightChildIndex = getRightChild(rootIndex);
        int largest = rootIndex;

        if(leftChildIndex < usedSize && heap[leftChildIndex] > heap[rootIndex])
            largest = leftChildIndex;
        if(rightChildIndex < usedSize && heap[rightChildIndex] > heap[largest])
            largest = rightChildIndex;

        // If we found another larger Node 
        // Then swap them and rearrange the Heap
        if(largest != rootIndex) {
            swap(heap[largest], heap[rootIndex]);
            maxHeapify(largest);
        }
    }

    // Remove Top element of the Max-Heap
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

            // Rearrange the Max-Heap
            maxHeapify(0);
            return rootElement;        // Return Top Most Element
        }
    }

    // Delete a given Node from the Max-Heap
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
            cout <<"Key Not Found!!" <<endl;
            return;
        }        
        else {
            // Assign largest integr value to that Node
            heap[keyIndex] = INT_MAX;

            // After Assign largest Node check the position of that
            // Node and arrange the Max-Heap acoording to it
            // So that Node became the root Node of the Max-Heap
            while (keyIndex != 0 && heap[parent(keyIndex)] < heap[keyIndex])
            {
                swap(heap[parent(keyIndex)], heap[keyIndex]);
                keyIndex = parent(keyIndex);
            }
            
            // Remove root Node from the Max-Heap
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

    // Create a Max-Heap of size 10
    MaxHeap heap(10);

    heap.insertHeap(14);
    heap.insertHeap(4);
    heap.insertHeap(5);
    heap.insertHeap(10);
    heap.insertHeap(7);
    heap.insertHeap(6);
    heap.display();

    // int removedEle = heap.removeTopElement();
    // (removedEle != INT_MAX) ? cout <<"Romoved Element: " <<removedEle <<endl : cout <<"Heap is Empty!" <<endl;
    // heap.display();

    heap.deleteNode(10);
    heap.deleteNode(7);
    heap.display();

    return 0;
}