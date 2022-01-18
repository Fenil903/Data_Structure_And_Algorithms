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

void display(Node* ptr) {
    while (ptr != NULL)                     
    {
        cout << ptr -> data << " ";
        ptr = ptr ->next;
    }
    cout <<endl;
}

// Main Function
int main() {
    Node* head = new Node();    // Create a head Node(1st Node) with value 0
    Node* second = new Node();  // Create a (2nd Node) with value 0
    Node* third = new Node();   // Create a (3rd Node) with value 0

    head -> data = 5;   // Assigning value to the Node 
    head -> next = second;  // Pointing next Node

    second -> data = 10;    
    second -> next = third;

    third -> data = 15;
    third -> next = NULL;

    display(head);

    return 0;
}