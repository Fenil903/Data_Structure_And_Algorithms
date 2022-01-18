#include <iostream>
#include <string>
using namespace std;

// We are creating a node name Node which contain 3 parameters: Value | prev_Object(Node) | next_Object(Node)
class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    // Every node initially contain the value 0 and doesn't point to next Node or previous Node
    Node() {
        data = 0;
        prev = NULL;
        next = NULL;
    }
};

void display(Node* head_ptr) {
    Node* temp_ptr = new Node();    // Create a new Node 

    // Traverse through First Node to End Node
    while (head_ptr != NULL)
    {
        cout << head_ptr ->data << " ";
        temp_ptr = head_ptr;
        head_ptr = head_ptr ->next;
    }
    cout <<endl;

    // Traverse in reverse
    while (temp_ptr != NULL)
    {
        cout << temp_ptr ->data << " ";
        temp_ptr = temp_ptr ->prev;
    }
    cout <<endl;    
}

// Insert a Node at Begining of the List
void insertAtBegin(Node** head_ptr, int value) {
    Node* new_ptr = new Node();    // Create a new Node with value 0

    new_ptr ->data = value;
    new_ptr ->next = *head_ptr;
    new_ptr ->prev = NULL;
    (*head_ptr) ->prev = new_ptr;
    *head_ptr = new_ptr;
}

// Delete the First Node of the List
void deleteAtBegin(Node** head_ptr) {
    Node* del_ptr = *head_ptr;    // Create new Node and assign head Node

    *head_ptr = del_ptr ->next;
    (*head_ptr) ->prev = NULL;
    delete del_ptr;
}

// Main Function
int main() {
    Node* head = new Node();    // Create a head Node(1st Node) with value 0
    Node* second = new Node();    // Create a (2nd Node) with value 0
    Node* third = new Node();    // Create a (3rd Node) with value 0
    Node* fourth = new Node();    // Create a (4th Node) with value 0

    head ->data = 4;    // Assign the value of the Node 
    head ->prev = NULL;    // previous of head Node is NULL
    head ->next = second;   // Connect next Node

    second ->data = 9;
    second ->prev = head;
    second ->next = third;

    third ->data = 15;
    third ->prev = second;
    third ->next = fourth;

    fourth ->data = 25;
    fourth ->prev = third;
    fourth ->next = NULL;

    display(head);

    // insertAtBegin(&head, 50);
    // display(head);

    deleteAtBegin(&head);
    display(head);

    return 0;
}