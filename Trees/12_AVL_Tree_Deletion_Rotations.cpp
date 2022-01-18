#include <iostream>
#include <string>
using namespace std;

class AVLTreeNode {
    public:
    int data;
    AVLTreeNode *left;
    AVLTreeNode *right;

    AVLTreeNode(int key) {
        data = key;
        left = NULL;
        right = NULL;
    }
};

AVLTreeNode* findSuccessor(AVLTreeNode* node_ptr) {
    while (node_ptr ->left != NULL)
    {
        node_ptr = node_ptr ->left;
    }
    return node_ptr;
}
// Return Height of the given Node
int getHeight(AVLTreeNode* node_ptr) {
    int leftHeight, rightHeight;

    if(node_ptr == NULL)    // Return -1 for empty Tree or Node(NULL)
        return -1;
    else {
        leftHeight = getHeight(node_ptr ->left);    // Get height of left subtree
        rightHeight = getHeight(node_ptr ->right);    // Get height of right subtree

        if(leftHeight > rightHeight)
            return leftHeight + 1;
        else 
            return rightHeight + 1;
    }
}

// Return Balanced Factor of the given Node
int getBalanceFactor(AVLTreeNode* node_ptr) {

    // Balanced Factor of the Node: (Height of left subtree - Height of right subtree)
    if(node_ptr == NULL)
        return -1;
    else
        return getHeight(node_ptr ->left) - getHeight(node_ptr ->right);
}

AVLTreeNode* rightRotate(AVLTreeNode* node_ptr) {
    AVLTreeNode* node_left_ptr = node_ptr ->left;
    AVLTreeNode* null_ptr = node_left_ptr ->right;

    // Perform rotation
    node_left_ptr ->right = node_ptr;
    node_ptr ->left = null_ptr;

    return node_left_ptr;
}

AVLTreeNode* leftRotate(AVLTreeNode* node_ptr) {
    AVLTreeNode* node_right_ptr = node_ptr ->right;
    AVLTreeNode* null_ptr = node_right_ptr ->left;

    // Perform rotation
    node_right_ptr ->left = node_ptr;
    node_ptr ->right = null_ptr;

    return node_right_ptr;
}

// Insert a Node in AVL Tree recursively
AVLTreeNode* insertInAVL(AVLTreeNode* root_ptr, int key) {

    if(root_ptr == NULL) {       // Insert a Node at the end of Leaf Node
        AVLTreeNode* new_ptr = new AVLTreeNode(key);       // Inserting Node
        root_ptr = new_ptr;
        return root_ptr;
    }
    else if(key < root_ptr ->data)
        root_ptr ->left = insertInAVL(root_ptr ->left, key);    // Insert in left subtree
    else if(key > root_ptr ->data)
        root_ptr ->right = insertInAVL(root_ptr ->right, key);    // Insert in right subtree
    else {
        cout <<key <<" already exist!" <<endl;
    }

    int balanceFactor = getBalanceFactor(root_ptr);

    // Left-Left Imbalancing
    if(balanceFactor > 1 && key < root_ptr ->left ->data) {
        return rightRotate(root_ptr);
    }
    // Right-Right Imbalancing
    else if(balanceFactor < -1 && key > root_ptr ->right ->data)
        return leftRotate(root_ptr);
    // Left-Right Imbalancing
    else if(balanceFactor > 1 && key > root_ptr ->left ->data) {
        root_ptr ->left = leftRotate(root_ptr ->left);          // First left rotation at left child of that Node
        return rightRotate(root_ptr);                           // Then right rotaion at that Node
    }
    // Right-Left Imbalancing
    else if(balanceFactor < -1 && key < root_ptr ->right ->data) {
        root_ptr ->right = rightRotate(root_ptr ->right);          // First right rotation at right child of that Node
        return leftRotate(root_ptr);                               // Then letf rotaion at that Node
    }

    return root_ptr;
}

// Delete a Node from AVL Tree recursively
AVLTreeNode* deleteNodeAVL(AVLTreeNode* root_ptr, int key) {
    AVLTreeNode* temp_ptr = NULL;

    if(root_ptr == NULL)        // Tree is Empty
        return root_ptr;
    else if(key < root_ptr ->data) 
        root_ptr ->left = deleteNodeAVL(root_ptr ->left, key);      // Search key in left subtree
    else if(key > root_ptr ->data)
        root_ptr ->right = deleteNodeAVL(root_ptr ->right, key);      // Search key in right subtree

    // Statergy when key found in the Tree
    else {      
        // key Node is a leaf Node
        if(root_ptr ->left == NULL && root_ptr ->right == NULL) {
            temp_ptr = root_ptr ->left;
            delete root_ptr;
            return temp_ptr;
        }
        // key Node has only left child 
        else if(root_ptr ->left != NULL && root_ptr ->right == NULL) {
            temp_ptr = root_ptr ->left;
            delete root_ptr;
            return temp_ptr;
        }
        // key Node has only right child 
        else if(root_ptr ->left == NULL && root_ptr ->right != NULL) {
            temp_ptr = root_ptr ->right;
            delete root_ptr;
            return temp_ptr;
        }
        // key Node has two child
        else {
            temp_ptr = findSuccessor(root_ptr ->right);

            // Copy smallest value in deleting Node and delete that smallest Node
            root_ptr ->data = temp_ptr ->data;
            root_ptr ->right = deleteNodeAVL(root_ptr ->right, temp_ptr ->data);
        }
    }

    int balanceFactor = getBalanceFactor(root_ptr);

    // Left-Left Imbalancing
    if(balanceFactor > 1 && getBalanceFactor(root_ptr ->left) > 0) {
        return rightRotate(root_ptr);
    }
    // Left-Right Imbalancing
    else if(balanceFactor > 1 && getBalanceFactor(root_ptr ->left) < 0) {
        root_ptr ->left = leftRotate(root_ptr ->left);
        return rightRotate(root_ptr);
    }
    // Right-Right Imbalancing
    else if(balanceFactor < -1 && getBalanceFactor(root_ptr ->right) < 0) {
        return leftRotate(root_ptr);
    }
    else if(balanceFactor < -1 && getBalanceFactor(root_ptr ->right) > 0) {
        root_ptr ->right = rightRotate(root_ptr ->right);
        return leftRotate(root_ptr);
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

    root = insertInAVL(root, 25);
    root = insertInAVL(root, 20);
    root = insertInAVL(root, 15);
    root = insertInAVL(root, 45);
    root = insertInAVL(root, 10);
    root = insertInAVL(root, 5);
    root = insertInAVL(root, 1);
    cout <<"Root Node: " <<root ->data <<" Height of root Node: " <<getHeight(root) <<endl;

    //              INSERTION                                      DELETION
    //--------------------------------------------|-------------------------------------------------
    // Without Rotaion   ::   After Rotation      | Without Rotaion   ::   After Rotation 
    //             25               20            |         20                   20
    //            / \              / \            |        / \                  / \
    //           20 45            10  25          |       10  25               5   25
    //          /                /  \   \         |      /     \              / \   \
    //         15               5   15   45       |     5       45           1   10  45
    //        /                /                  |    /
    //       10               1                   |   1
    //      /                                     |
    //     5                                      |
    //    /                                       |       
    //   1                                        |

    cout <<"Tree: ";
    inOrderTraverse(root);
    
    // Deleting a Node
    int key = 15;
    root = deleteNodeAVL(root, key);
    (root == NULL) ? cout <<"\nTree is empty nothing is deleted!" <<endl : cout <<"\n" <<key <<" is deleted" <<endl;

    cout <<"\nAfter Deletion, Tree: ";
    inOrderTraverse(root);
    cout <<"\nRoot Node: " <<root ->data <<" Height of root Node: " <<getHeight(root) <<endl;

    return 0;
}