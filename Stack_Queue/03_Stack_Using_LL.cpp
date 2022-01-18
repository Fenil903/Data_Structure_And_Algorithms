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
bool isFull(Node* top) {
    Node* temp_Node = new Node();

    if(temp_Node == NULL)
        return true;
    else    
        return false;
}

// Check whether the Stack is Empty or not
bool isEmpty(Node* top) {
    if(top == NULL)
        return true;
    else
        return false; 
}   

void display(Node* ptr) {
    while (ptr != NULL)                     
    {
        cout << ptr -> data << " ";
        ptr = ptr ->next;
    }
    cout <<endl;
}

int main() {
    Node* top = new Node();
    Node* second = new Node();
    Node* third = new Node();

    top ->data = 10;
    top ->next = second;

    second ->data = 20;
    second ->next = third;

    third ->data = 30;
    third ->next = NULL;

    display(top);

    return 0;
}