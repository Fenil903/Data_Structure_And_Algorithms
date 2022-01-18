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

void display(Node* head_ptr) {
    Node* temp_ptr = head_ptr;

    do
    {
        cout << temp_ptr ->data << " ";
        temp_ptr = temp_ptr ->next;

    } while (temp_ptr != head_ptr);   
    cout <<endl; 
}

// Special Case: Insert a Node at first Node
void insertAtHead(Node** head_ptr, int value) {
    Node* new_ptr = new Node();    // Create a new Node
    Node* temp_ptr = *head_ptr;    // Create a temporary pointer points head Node

    while (temp_ptr ->next != *head_ptr)    // Jump to the last Node
    {
        temp_ptr = temp_ptr ->next;
    }

    new_ptr ->data = value;
    temp_ptr ->next = new_ptr;
    new_ptr ->next = *head_ptr;
    *head_ptr = new_ptr;    // Make new Node as head Node
}

// Special Case: Delete a first Node 
void deleteFirstNode(Node** head_ptr) {

    /*
    Here we create 2 Nodes: 
    1st Node considered as Head Node 
    2nd Node considered as next Node
    */
    Node* prev_ptr = *head_ptr;
    Node* temp_ptr = prev_ptr ->next;

    while (temp_ptr ->next != *head_ptr)    // Jump to the last Node
    {
        temp_ptr = temp_ptr ->next;
    }
    
    temp_ptr ->next = prev_ptr ->next;
    *head_ptr = prev_ptr ->next;
    delete prev_ptr;
}

// Main Function
int main() {
    Node* head = new Node();    // Create a head Node(1st Node) with value 0
    Node* second = new Node();  // Create a (2nd Node) with value 0
    Node* third = new Node();  // Create a (3rd Node) with value 0
    Node* fourth = new Node();  // Create a (4th Node) with value 0

    head ->data = 9;   // Assigning value to the Node 
    head ->next = second;   // Pointing next Node

    second ->data = 15;
    second ->next = third;

    third ->data = 8;
    third ->next = fourth;

    fourth ->data = 1;
    fourth ->next = head;

    display(head);

    // insertAtHead(&head, 20);    // Passing address of head Node and value of new Node
    // display(head);

    deleteFirstNode(&head);
    display(head);

    return 0;
}