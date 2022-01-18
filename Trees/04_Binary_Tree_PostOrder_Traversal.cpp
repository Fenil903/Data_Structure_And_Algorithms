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

// Traverse a Tree in Pre Order 
void postOrderTraverse(Node* root) {

    // PostOrder: Left -> Right -> Root
    if(root != NULL) {
        postOrderTraverse(root ->left);  // For left subtree
        postOrderTraverse(root ->right); // For right subtree

        cout <<root ->data <<" ";   // Print Root Node value
    }
}

int main() {

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);
    
    // Creating Binary Tree:
    //       1
    //      / \
    //     2   3
    //    /   / \
    //   4   5   6
    //      / \
    //     7   8

    node1 ->left = node2;
    node1 ->right = node3;

    node2 ->left = node4;

    node3 ->left = node5;
    node3 ->right = node6;

    node5 ->left = node7;
    node5 ->right = node8;
    
    postOrderTraverse(node1);

    return 0;
}