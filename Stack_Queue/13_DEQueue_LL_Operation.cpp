// DEQueue: Double Ended Queue

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

// To add a Node from last Node in the Queue
void enqueueR(Node** f_ptr, Node** r_ptr, int value) {
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

// To add a Node from head Node in the Queue
void enqueueF(Node** f_ptr, Node** r_ptr,int value) {
    Node* new_ptr = new Node();    // Create a Node which is going to be added
    new_ptr ->data = value;
    new_ptr ->next = NULL;

    // If Queue is full then new Node cannot be added
    // If Queue is empty then new created Node become first and last Node
    // Else add new Node at the front and point front pointer to new Node
    if(isFull()) {
        cout <<"Queue is Full!! Cannot add " <<value <<" in the Queue!" <<endl;
    }
    else if(isEmpty(*f_ptr)) {
        *f_ptr = new_ptr;
        *r_ptr = new_ptr;
    }
    else {
        new_ptr ->next = *f_ptr;
        *f_ptr = new_ptr;
    }
}

// To remove a Node from the Queue
int dequeueF(Node** f_ptr) {
    int dequeuedValue = -1;
    Node* del_ptr = *f_ptr;    // Create deleting Node which is head Node of the Queue

    // If Queue is empty then nothing will be removed
    // Else head Node will be removed and front pointer points to the next Node
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

// To remove a Node from last Node from the Queue
int dequeueR(Node** f_ptr, Node** r_ptr) {
    int dequeuedValue = -1;
    Node* del_ptr = *r_ptr;    // Create deleting Node which is last Node of the Queue
    Node* prev_ptr = *f_ptr;    

    // If Queue is empty then nothing will be removed
    // If the front and rear poiner are same i.e. Queue has only 1 Node
    // After delete this Node, we restrat the Queue
    // Else last Node will be removed and rear pointer points to the previous Node
    if(isEmpty(*f_ptr)) {
        cout <<"Queue is Empty!! Cannot remove Node from the Queue!" <<endl;
    }
    else if(*f_ptr == *r_ptr) {
        dequeuedValue = del_ptr ->data;
        *f_ptr = NULL;
        *r_ptr = NULL;
    }
    else {
        while (prev_ptr ->next != del_ptr)    // prev_ptr points to 2nd last Node
        {
            prev_ptr = prev_ptr ->next;
        }
        prev_ptr ->next = NULL;
        *r_ptr = prev_ptr;
        dequeuedValue = del_ptr ->data;
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
    
    enqueueR(&front, &rear, 5);
    enqueueR(&front, &rear, 10);
    enqueueR(&front, &rear, 15);
    enqueueR(&front, &rear, 20);

    display(front);

    // cout <<"Removed Element: " <<dequeueF(&front) <<endl;
    // cout <<"Removed Element: " <<dequeueF(&front) <<endl;
    // cout <<"Removed Element: " <<dequeueF(&front) <<endl;
    // cout <<"Removed Element: " <<dequeueF(&front) <<endl;    // Queue will be empty

    // enqueueF(&front, &rear, 1);
    // enqueueF(&front, &rear, 5);

    cout <<"Removed Element: " <<dequeueR(&front, &rear) <<endl;
    cout <<"Removed Element: " <<dequeueR(&front, &rear) <<endl;
    cout <<"Removed Element: " <<dequeueR(&front, &rear) <<endl;
    cout <<"Removed Element: " <<dequeueR(&front, &rear) <<endl;
    // cout <<"Removed Element: " <<dequeueR(&front, &rear) <<endl;

    display(front);
    
    return 0;
}