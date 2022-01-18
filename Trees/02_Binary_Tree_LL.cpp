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
        left = NULL;
        right = NULL;
    }
};

int main() {
    Node* root = new Node(5);   // Create root Node 
    Node* second = new Node(4);   // Create second Node 
    Node* third = new Node(9);   // Create third Node

    root ->left = second;   // Make second Node as left child of root Node
    root ->right = third;   // Make third Node as right child of root Node

    return 0;
}