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

// Traverse a Tree in In Order and check for BST 
int isBST(Node* root) {
    static Node* prev_ptr = NULL;

    // PreOrder: Left -> Root -> Right
    if(root != NULL) {
        if(!isBST(root ->left))  // check if left subtree exist or not
            return 0;
        if(prev_ptr != NULL && root ->data <= prev_ptr ->data) {    // Value of root Node must > prev Node else return false
            return 0;
        }
        prev_ptr = root;    // If the root > child then make root as prev_ptr
        return isBST(root ->right);
    }
    else 
        return 1;
}

int main() {
     // Creating Non Binary Search Tree:
    //       1
    //      / \
    //     2   3
    //    /   / \
    //   4   5   6
    //      / \
    //     7   8

    // Node* node1 = new Node(1);
    // Node* node2 = new Node(2);
    // Node* node3 = new Node(3);
    // Node* node4 = new Node(4);
    // Node* node5 = new Node(5);
    // Node* node6 = new Node(6);
    // Node* node7 = new Node(7);
    // Node* node8 = new Node(8);

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
    
    (isBST(node1)) ? cout <<"This is BST!" <<endl : cout <<"This is not BST!" <<endl;

    return 0;
}