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

// Check whether the Queue is empty or not
bool isEmpty(Node* f_ptr) {
    if(f_ptr == NULL)
        return true;
    else
        return false;
}

// Check whether the Queue is full or not
bool isFull() {

    // Try to make new Node
    // If Node will be created then Queue is not Full
    Node* new_ptr = new Node();

    if(new_ptr == NULL)
        return true;
    else
        return false;
}

// To add a Node in the Queue
void enqueue(Node** f_ptr, Node** r_ptr, int value) {
    Node* new_ptr = new Node();    // Create a Node which is going to be added
    new_ptr ->data = value;
    new_ptr ->next = NULL;

    // If Queue is full then new Node cannot be added
    // If Queue is empty then new created Node become first and last Node
    // Else add new Node at the end and point rear pointer to new Node
    if(isFull()) {
        cout <<"Queue is Full!! Cannot add " <<value <<" in the Queue!" <<endl;
    }
    else if(isEmpty(*f_ptr)) {
        *f_ptr = new_ptr;
        *r_ptr = new_ptr;
    }
    else {
        (*r_ptr) -> next =new_ptr;
        *r_ptr = (*r_ptr) ->next;
    }
}

// To remove a Node from the Queue
int dequeue(Node** f_ptr) {
    int dequeuedValue = -1;
    Node* del_ptr = *f_ptr;    // Create deleting Node which is head Node of the Queue

    // If Queue is empty then nothing will be removed
    // Else head Node will be removed 
    // and front point the next Node
    if(isEmpty(*f_ptr)) {
        cout <<"Queue is Empty!! Cannot remove Node from the Queue!" <<endl;
    }
    else {
        dequeuedValue = (*f_ptr) ->data;
        *f_ptr = (*f_ptr) ->next;
        delete del_ptr;
    }
    return dequeuedValue;
}

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
    
    enqueue(&front, &rear, 5);
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 15);
    enqueue(&front, &rear, 20);

    display(front);

    cout <<"Removed Element: " <<dequeue(&front) <<endl;
    cout <<"Removed Element: " <<dequeue(&front) <<endl;
    cout <<"Removed Element: " <<dequeue(&front) <<endl;
    cout <<"Removed Element: " <<dequeue(&front) <<endl;    // Queue will be empty

    display(front);
    
    enqueue(&front, &rear, 25);
    display(front);

    return 0;
}