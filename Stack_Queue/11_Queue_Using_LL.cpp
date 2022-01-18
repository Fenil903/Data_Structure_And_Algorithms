#include <iostream>
#include <string>
using namespace std;

// Create a Node of the Queue which which contain 2 parameters: Value | next_Object(Node) 
class Node {
    public:
    int data;
    Node* next;

    // Every node initially contain the value 0 and doesn't point to next Node
    Node() {
        data = 0;
        next = NULL;
    }
};

void display(Node*f_ptr) {
    while (f_ptr != NULL)
    {
        cout <<f_ptr ->data <<" ";
        f_ptr = f_ptr ->next;
    }
    cout <<endl;    
}

// Main Function
int main() {
    Node* front = NULL;    // Create front pointer points first Node int the Queue
    Node* rear = NULL;    // Create rear pointer points last Node int the Queue

    Node* head = new Node();   // Create head Node(1st Node) of the Queue
    Node* second = new Node();  // Create 2nd Node of the Queue
    Node* third = new Node();   // Create 3rd Node of the Queue

    head ->data = 5;    // Assign value of the Node
    head ->next = second;   // Point to the next Node

    // Both pointer to the head Node
    front = head;   
    rear = head;

    second ->data = 10;
    second ->next = third;

    rear = rear ->next;

    third ->data = 15;
    third ->next = NULL;

    rear = rear ->next;

    display(front);

    return 0;
}