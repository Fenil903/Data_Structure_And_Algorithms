#include <iostream>
#include <string>
using namespace std;

// Creata a Node which has three parameters: Value | left child pointer | right child pointer
class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left =NULL;
        right = NULL;
    }
};

// Searching in BST: return Node if element found else return null pointer
Node* searchElement(Node* root_ptr, int key) {
    if(root_ptr != NULL) {   // Check whether thr Tree is empty or not
        if(root_ptr ->data == key)   
            return root_ptr;     // If key was found then return it
        else if(root_ptr ->data > key)
            return searchElement(root_ptr ->left, key);     // key < root i.e search in left subtree
        else
            return searchElement(root_ptr ->right, key);     // key > root i.e search in right subtree
    }
    else
        return NULL;
}

Node* IterativeSearch(Node* root_ptr, int key) {
    Node* trav_ptr = root_ptr;
    
    while (trav_ptr != NULL) 
    {
        if(trav_ptr ->data == key)
            return trav_ptr;
        else if(trav_ptr ->data > key) 
            trav_ptr = trav_ptr ->left;     // Move to left subtree
        else
            trav_ptr = trav_ptr ->right;     // Move to right subtree
    }
    return NULL;    // Element not found
}

int main() {
    Node* node1 = new Node(8);
    Node* node2 = new Node(6);
    Node* node3 = new Node(15);
    Node* node4 = new Node(3);
    Node* node5 = new Node(10);
    Node* node6 = new Node(17);
    Node* node7 = new Node(9);
    Node* node8 = new Node(11);
    
    // Creating Binary Search Tree:
    //       8
    //      / \
    //     6   15
    //    /   / \
    //   3   10  17
    //      / \
    //     9   11

    node1 ->left = node2;
    node1 ->right = node3;

    node2 ->left = node4;

    node3 ->left = node5;
    node3 ->right = node6;

    node5 ->left = node7;
    node5 ->right = node8;

    int element = 0;

    // if(searchElement(node1, element) != NULL)
    //     cout <<"Element found: " <<element <<endl;
    // else
    //     cout <<"Element not found!" <<endl;

    if(IterativeSearch(node1, element) != NULL)
        cout <<"Element found: " <<element <<endl;
    else
        cout <<"Element not found!" <<endl;

    return 0;
}