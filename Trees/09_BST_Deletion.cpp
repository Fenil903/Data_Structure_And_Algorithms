#include <iostream>
#include <string>
using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key) {
        data = key;
        left = NULL;
        right = NULL;
    }
};

// Insertion in BST
void insertNodeBST(TreeNode** root_ptr, int key) {
    TreeNode* new_ptr = new TreeNode(key);      // Inserting Node
    TreeNode* temp_ptr = *root_ptr;     // Traversal pointer
    TreeNode* prev_ptr = NULL;      // Parent pointer

    if(*root_ptr == NULL) {     // Empty tree
        *root_ptr = new_ptr;
        cout <<"Root value added! " <<key <<endl;
    }
    else {
        while (temp_ptr != NULL)
        {
            prev_ptr = temp_ptr;

            // If key is already exist then can't add new Node
            if(key == temp_ptr ->data) {
                cout <<key <<" already exist!!" <<endl;
                return;
            }
            else if(key < temp_ptr ->data)
                temp_ptr = temp_ptr ->left;     // Move to left subtree
            else
                temp_ptr = temp_ptr ->right;     // Move to right subtree
        }

        if(key < prev_ptr ->data) {
            prev_ptr ->left = new_ptr;
        }
        else {
            prev_ptr ->right = new_ptr;
        }
    }
}

// Find smallest Node in right subtree(inOrder Successor)
TreeNode* findSuccessor(TreeNode* temp_right_ptr) {
    while (temp_right_ptr ->left != NULL)
    {
        temp_right_ptr = temp_right_ptr ->left;
    }
    return temp_right_ptr;
}

// Function to delete a Node in BST
TreeNode* deleteNodeBST(TreeNode** root_ptr, int key) {
    TreeNode* temp_ptr = *root_ptr;     // Traversal pointer
    TreeNode* return_ptr = NULL;

    // When tree is empty
    if(*root_ptr == NULL) {
        return *root_ptr;
    } 
    else if(key < temp_ptr ->data)
        temp_ptr ->left = deleteNodeBST(&temp_ptr ->left, key);     // Search key in left subtree
    else if(key > temp_ptr ->data)
        temp_ptr ->right = deleteNodeBST(&temp_ptr ->right, key);     // Search key in right subtree
    
    // Strategy when deleting Node found
    else {
        // Deleting Node is Leaf Node
        if(temp_ptr ->left == NULL && temp_ptr ->right == NULL) {
            return_ptr = temp_ptr ->left;
            delete temp_ptr;
            return return_ptr;
        }
        // Deleting Node has only right child
        else if(temp_ptr ->left == NULL && temp_ptr ->right != NULL) {
            return_ptr = temp_ptr ->right;
            delete temp_ptr;
            return return_ptr;
        }
        // Deleting Node has only left child
        else if(temp_ptr ->left == NULL && temp_ptr ->right == NULL) {
            return_ptr = temp_ptr ->left;
            delete temp_ptr;
            return return_ptr;
        }
        // Deleting Node has two child OR root Node
        else {
            return_ptr = findSuccessor(temp_ptr ->right);

            // Copy smallest value in deleting Node and delete that smallest Node
            temp_ptr ->data = return_ptr ->data;    
            temp_ptr ->right = deleteNodeBST(&temp_ptr ->right, return_ptr ->data);
        }
    }
    return temp_ptr;
}

void inOrderTraverse(TreeNode* root_ptr) {
    if(root_ptr != NULL) {
        inOrderTraverse(root_ptr ->left);
        cout <<root_ptr ->data <<" ";
        inOrderTraverse(root_ptr ->right);
    }
}

int main() {
    TreeNode* root = NULL;
    
    insertNodeBST(&root, 5);
    insertNodeBST(&root, 1);
    insertNodeBST(&root, 2);
    insertNodeBST(&root, 3);
    insertNodeBST(&root, 9);
    insertNodeBST(&root, 6);
    insertNodeBST(&root, 7);
    insertNodeBST(&root, 8);
    insertNodeBST(&root, 10);
    insertNodeBST(&root, 11);
    insertNodeBST(&root, 15);
    // (root == NULL) ? cout <<"NULL" <<endl : cout <<"Not NULL" <<endl;

    // Tree will be like this:
    //        5
    //      /  \
    //     /    \
    //    /      \
    //   2        9
    //  / \     /   \
    // 1   3   7     11
    //        / \    / \
    //       6   8  10  15

    cout <<"Tree: ";
    inOrderTraverse(root);

    int key = 5;
    (deleteNodeBST(&root, key) == NULL) ? cout <<"\nTree is empty nothing is deleted"
                                                 <<endl
                                        : cout <<"\n" <<key <<" is deleted" <<endl;
    cout <<"Tree: ";
    inOrderTraverse(root);

    return 0;
}