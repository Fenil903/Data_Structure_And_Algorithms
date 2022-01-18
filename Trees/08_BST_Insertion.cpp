#include <iostream>
#include <string>
using namespace std;

// Creata a Node which has three parameters: Value | left child pointer | right child pointer
class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int key) {
        data = key;
        left = NULL;
        right = NULL;
    }
};

// Insertion in BST
void insertInBST(Node** root_ptr, int key) {
    Node* new_ptr = new Node(key);      // Inserting Node
    Node* temp_ptr = *root_ptr;     // Traversal pointer
    Node* prev_ptr = NULL;      // Parent pointer

    /*
    Traverse in Tree, if tree is empty then make inserting Node as root Node
    If value of inserting Node is greater than root Node then move to right subtree 
    If value of inserting Node is lesser than root Node then move to left subtree 
    */
    if(*root_ptr == NULL) {     // Empty tree
        *root_ptr = new_ptr;
        cout <<"Tree is empty! " <<key <<" will be root." <<endl;
    }
    
    else {
        while (temp_ptr != NULL)
        {
            prev_ptr = temp_ptr;
            // If key is already exist then can't add new Node
            if(key == temp_ptr ->data) {
                cout <<key <<" is already exist!" <<endl;
                return;
            }
            else if(key < temp_ptr ->data)
                temp_ptr = temp_ptr ->left;     // Move to left subtree
            else
                temp_ptr = temp_ptr ->right;     // Move to right subtree
        }  

        if(key < prev_ptr ->data) {
            prev_ptr ->left = new_ptr;
            cout <<"Node added: " <<key <<endl;
        }
        else {
            prev_ptr ->right = new_ptr;
            cout <<"Node added: " <<key <<endl;
        }
    }
}

// Traverse the tree
void inOrderTraverse(Node* root_ptr) {

    // InOrder: Left -> Root -> Right
    if(root_ptr != NULL) {
        inOrderTraverse(root_ptr ->left);
        cout <<root_ptr ->data <<" ";
        inOrderTraverse(root_ptr ->right);
    }
}

int main() {
    Node* root = NULL;

    insertInBST(&root, 6);
    insertInBST(&root, 8);
    insertInBST(&root, 11);
    insertInBST(&root, 2);
    insertInBST(&root, 3);
    insertInBST(&root, 1);
    // insertInBST(&root, 1);

    cout <<"InOrder: ";
    inOrderTraverse(root);

    // Tree will be like this:
    //      6
    //     / \
    //    2   8
    //   / \   \
    //  1   3   11

    return 0;
}