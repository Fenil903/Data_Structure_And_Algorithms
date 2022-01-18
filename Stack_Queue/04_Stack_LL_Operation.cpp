#include <iostream>
#include <string>
using namespace std;

// We are creating a node name Node which contain 2 parameters: Value | next_Object(Node)
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

// Check whether the Stack is Full or not
bool isFull(Node* top_ptr) {
    Node* new_ptr = new Node();

    if(new_ptr == NULL) 
        return true;
    else
        return false;
} 

// Check whether the Stack is Empty or not
bool isEmpty(Node* top_ptr) {
    if(top_ptr == NULL)
        return true;
    else
        return false;
}

// To append elements in the Stack
void push(Node** ptr, int value) {

    /*
    It will check whether the Stack is full or not
    If it is full then we can't append the data
    If not then we append data as top element
    */
    if(isFull(*ptr))
        cout <<"Stack Overflow!! Cannot push " <<value <<" in the Stack!" <<endl;
    else {
        Node* new_ptr = new Node();
        new_ptr ->data = value;
        new_ptr ->next = *ptr;
        *ptr = new_ptr;
    }
}

// To delete elements from the Stack
int pop(Node** top_ptr) {

    /*
    It will check whether the Stack is empty or not
    If it is empty then we can't remove the data
    If not then we remove the last apended element
    */
    if(isEmpty(*top_ptr)) {
        cout <<"Stack Underflow!! Cannot pop from the Stack!" <<endl;
        return -1;
    }
    else {
        Node* temp_ptr = *top_ptr;
        int popedValue = temp_ptr ->data;
        *top_ptr = (*top_ptr) ->next;
        delete temp_ptr;

        return popedValue;
    }
}

// Return value at specific position from the Stack
int peak(Node** top_ptr, int position) {
    Node* temp_ptr = *top_ptr;
    int temp = 1;

    while (temp < position && temp_ptr != NULL)   
    {
        temp_ptr = temp_ptr ->next;
        temp ++;
    }

    if(temp_ptr == NULL) {
        cout <<"Position out of range!!" <<endl;
        return -1;
    }
    else
        return temp_ptr ->data;    
}

void display(Node* top_ptr) {
    while (top_ptr != NULL)
    {
        cout <<top_ptr ->data <<" ";
        top_ptr = top_ptr ->next;
    }
    cout <<endl;
}

int main() {
    Node* top = NULL;   // Create Null pointer pointing first Node

    (isEmpty(top)) ? cout <<"Stack Empty!" <<endl : cout <<"Stack Not Empty!!" <<endl;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    push(&top, 40);
    display(top);
    
    // cout <<"Poped Element: " <<pop(&top) <<endl;
    // cout <<"Poped Element: " <<pop(&top) <<endl;
    // cout <<"Poped Element: " <<pop(&top) <<endl;
    // display(top);
    
    int pos = 5;
    cout <<"Element at Position " <<pos <<" is " <<peak(&top, pos) <<endl;
    display(top);

    return 0;
}