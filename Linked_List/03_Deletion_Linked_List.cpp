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

// Delete a first Node of the List.
void deleteAtBegin(Node** head_ptr) {
    Node* del_ptr = *head_ptr;   // Create new Node and assign head Node 

    *head_ptr = del_ptr ->next;   // Assign second Node to be head Node
    delete del_ptr;    // Delete First Node
}

// Delete a Node at given index
void deleteAtIndex(Node** head_ptr, int index) {

    /*
    Here we create 2 Nodes: 
    1st Node considered as Head Node 
    2nd Node considered as next Node
    */
    Node* prev_ptr = *head_ptr;
    Node* del_ptr = prev_ptr ->next;
    int temp = 0;

    // We traverse untill del_ptr will become Deletimg Node
    while (temp < index-1)
    {
        prev_ptr = prev_ptr ->next;
        del_ptr = del_ptr ->next;
        temp ++;
    }

    prev_ptr ->next = del_ptr ->next;   // Assign next node of deleted node as next Node of previous Node
    delete del_ptr;    // Delete Node at specific Index
}

// Delete a Node at the end of the List
void deleteAtEnd(Node** head_ptr) {

    /*
    Here we create 2 Nodes: 
    1st Node considered as Head Node 
    2nd Node considered as next Node
    */
    Node* prev_ptr = *head_ptr;
    Node* del_ptr = prev_ptr ->next;

    // We traverse untill del_ptr will become Last Node
    while (del_ptr ->next != NULL)
    {
        prev_ptr = prev_ptr ->next;
        del_ptr = del_ptr ->next;
    }
    prev_ptr ->next = NULL;    // Make second last Node as last Node
    delete del_ptr;    // Delete last Node
}

// Delete a Node at given value of the List
void deleteAtValue(Node** head_ptr, int value) {
    
    /*
    Here we create 2 Nodes: 
    1st Node considered as Head Node 
    2nd Node considered as next Node
    */
    Node* prev_ptr = *head_ptr;
    Node* del_ptr = prev_ptr ->next;

    // We traverse untill del_ptr's or prev_ptr's value become deleting Node's value
    while (prev_ptr ->data != value && del_ptr ->data != value && del_ptr ->next != NULL)
    {
        prev_ptr = prev_ptr ->next;
        del_ptr = del_ptr ->next;
    }

    if (prev_ptr ->data == value) {     // When prev_ptr bewcome deleting Node(First Node)
        *head_ptr = del_ptr;
        delete prev_ptr;
    }
    else if (del_ptr ->data == value) {
        prev_ptr ->next = del_ptr ->next;
        delete del_ptr;
    }
    else
        cout <<"Can't find the Value in the List!!" <<endl;
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

    // deleteAtBegin(&head);   // Passing address of head Node which is going to be deleted
    // display(head);

    // deleteAtIndex(&head, 1);   // Passing address of head Node and index of Node which is going to be deleted
    // display(head);
    
    // deleteAtEnd(&head);   // Passing address of head Node
    // display(head);

    deleteAtValue(&head, 5);    // Passing address of head Node and deleting Node's Value
    display(head);

    return 0;
}