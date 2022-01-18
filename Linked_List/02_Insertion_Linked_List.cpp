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

// Insert a Node at the begining of the List
void insertAtBegin(Node** ptr, int value) {
    Node* new_Ptr = new Node();   // Create a new Node with value 0 which is going to be add at begin
    new_Ptr -> data = value;
    new_Ptr -> next = *ptr;
    *ptr = new_Ptr;     // Make new Node as head Node
}

// Insert a Node at any given index
void insertAtIndex(Node** ptr, int value, int index) {
    Node* new_ptr = new Node();   // Create a new Node with value 0 which is going to be add

    /*
    We will create a new traversal Node to traverse into LinkedList
    and copy the (index - 1) Node to a traversal Node 
    to connect new Node after that Node
    */
    Node* traverse_ptr = *ptr;   // Initially assign head Node to traversal Node
    int temp = 0;

    while (temp < index-1)
    {
        traverse_ptr = traverse_ptr -> next;
        temp ++;
    }
    new_ptr -> data = value;
    new_ptr -> next = traverse_ptr -> next;
    traverse_ptr -> next = new_ptr;
}

// Insert a Node at the end of the List
void insertAtEnd(Node** ptr, int value) {
    Node* new_ptr = new Node();   // Create a new Node with value 0 which is going to be add

    /*
    We will create a new traversal Node to traverse into LinkedList
    and travel at the end of the list 
    to connect new Node after that Node
    */
    Node* traverse_ptr = *ptr;   // Initially assign head Node to traversal Node

    while (traverse_ptr ->next != NULL)
    {
        traverse_ptr = traverse_ptr ->next;        
    }
    new_ptr ->data = value;
    traverse_ptr ->next = new_ptr;
    new_ptr ->next = NULL;  // Make last Node's next is NULL   
}

// Insert a Node after a given Node
void insertAfterNode(Node* previous_Node, int value) {
    Node* new_ptr = new Node();   // Create a new Node with value 0 which is going to be add

    new_ptr ->data = value;
    new_ptr ->next = previous_Node -> next;
    previous_Node ->next = new_ptr;
}

// Main Function
int main() {
    Node* head = new Node();    // Create a head Node(1st Node) with value 0
    Node* second = new Node();  // Create a (2nd Node) with value 0
    Node* third = new Node();   // Create a (3rd Node) with value 0

    head -> data = 5;   // Assigning value to first Node 
    head -> next = second;  // Pointing next Node

    second -> data = 10;    
    second -> next = third;

    third -> data = 15;
    third -> next = NULL;

    display(head);

    // insertAtBegin(&head, 20);    // Passing address of head Node and value of new Node
    // display(head);

    // insertAtIndex(&head, 100, 2);   // Passing address of head Node, value of new Node and index
    // display(head);

    // insertAtEnd(&head, 200);   // Passing address of head Node, value of new Node
    // display(head);

    insertAfterNode(third, 80);   // Passing the privous Node of new Node and value of new Node
    display(head);

    return 0;
}