#include <iostream>
#include <string>
using namespace std;

// Creata a Node which has three parameters: Value | left child pointer | right child pointer
class AVLTreeNode {
    public:
    int data;
    AVLTreeNode* left;
    AVLTreeNode* right;

    AVLTreeNode(int key) {
        data = key;
        left = NULL;
        right = NULL;
    }
};

// Return Height of the given Node
int getHeight(AVLTreeNode* root_ptr) {
    int lefHeight, rightHeight;

    if(root_ptr == NULL)    // Return -1 for empty Tree or Node(NULL)
        return -1;
    else {
        lefHeight = getHeight(root_ptr ->left);    // Get height of left subtree
        rightHeight = getHeight(root_ptr ->right);    // Get height of right subtree

        if(lefHeight > rightHeight)
            return lefHeight + 1;
        else
            return rightHeight + 1; 
    }
}

// Return Balanced Factor of the given Node
int getBalancedFactor(AVLTreeNode* root_ptr) {

    // Balanced Factor of the Node: (Height of left subtree - Height of right subtree)
    if(root_ptr == NULL)
        return -1;
    else 
        return getHeight(root_ptr ->left) - getHeight(root_ptr ->right);
}

//              Right Rotation                    :::               Left Rotation
//-------------------------------------------------|-------------------------------------------------
//       root_ptr             root_left_ptr        |       root_ptr             root_right_ptr
//         /                    /       \          |           \                  /       \
//    root_left_ptr   -->   leaf_ptr   root_ptr    |     root_right_ptr   -->   root_ptr  leaf_ptr
//      /     \                          /         |       /     \                \
//  leaf_ptr   NULL                     NULL       |    NULL   leaf_ptr           NULL 

// Right rotation
AVLTreeNode* rightRotate(AVLTreeNode* root_ptr) {
    AVLTreeNode* root_left_ptr = root_ptr ->left;
    AVLTreeNode* null_ptr = root_left_ptr ->right;
    
    // Perform rotation
    root_left_ptr ->right = root_ptr;    
    root_ptr ->left = null_ptr;

    return root_left_ptr;
} 
// Left rotation
AVLTreeNode* leftRotate(AVLTreeNode* root_ptr) {
    AVLTreeNode* root_right_ptr = root_ptr ->right;
    AVLTreeNode* null_ptr = root_right_ptr ->left;

    // Perform rotation
    root_right_ptr ->left = root_ptr;    
    root_ptr ->right = null_ptr;

    return root_right_ptr;
}

// Insert a Node in the AVL Tree in Recursive Mathod
AVLTreeNode* insertRecursive(AVLTreeNode* root_ptr, int key) {
    
    if(root_ptr == NULL) {       // Insert a Node at the end of Leaf Node
        AVLTreeNode* new_Node = new AVLTreeNode(key);       // Inserting Node
        root_ptr = new_Node;
        return root_ptr;
    }
    else if(key < root_ptr ->data)
        root_ptr ->left = insertRecursive(root_ptr ->left, key);    // Insert in left subtree
    else if(key > root_ptr ->data)
        root_ptr ->right = insertRecursive(root_ptr ->right, key);    // Insert in right subtree
    else {
        cout <<key <<" already exist!!" <<endl;
        return root_ptr;
    }

    int BalancedFactor = getBalancedFactor(root_ptr);

    // Left-Left Imbalancing
    if(BalancedFactor > 1 && key < root_ptr ->left ->data) {
        return rightRotate(root_ptr);
    }
    // Right-Right Imbalancing
    else if(BalancedFactor < -1 && key > root_ptr ->right ->data) {
        return leftRotate(root_ptr);
    }
    // Left-Right Imbalancing
    else if(BalancedFactor > 1 && key > root_ptr ->left ->data) {
        root_ptr ->left = leftRotate(root_ptr ->left);          // First left rotation at left child of that Node
        return rightRotate(root_ptr);                           // Then right rotaion at that Node      
    }
    // Right-Left Imbalancing
    else if(BalancedFactor < -1 && key < root_ptr ->right ->data) {
        root_ptr ->right = rightRotate(root_ptr ->right);       // First right rotation at left child of that Node
        return leftRotate(root_ptr);                            // Then left rotaion at that Node 
    }

    return root_ptr;
}

// Traverse the Tree
void inOrderTraverse(AVLTreeNode* root_ptr) {
    if(root_ptr != NULL) {
        inOrderTraverse(root_ptr ->left);
        cout <<root_ptr ->data <<" ";
        inOrderTraverse(root_ptr ->right);
    }
}

int main() {
    AVLTreeNode* root = NULL;

    root = insertRecursive(root, 25);
    root = insertRecursive(root, 20);
    root = insertRecursive(root, 15);
    root = insertRecursive(root, 45);

    cout <<"Tree: ";
    inOrderTraverse(root);
    cout <<endl;

    cout <<"Height of the root Node: " <<getHeight(root) <<endl;
    root = insertRecursive(root, 10);
    root = insertRecursive(root, 5);

    // Without Rotaion  ::  After Rotation
    //           25               20          
    //          / \              / \
    //         20 45            10  25
    //        /                /  \   \
    //       15               5   15   45
    //      /
    //     10           
    //    /           
    //   5           

    cout <<"Tree: ";
    inOrderTraverse(root);
    cout <<endl; 
    cout <<"Height of the root Node: " <<getHeight(root) <<endl;

    return 0;
}