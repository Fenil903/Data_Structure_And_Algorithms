#include <iostream>
#include <string>
using namespace std;

// Creata a Node which has three parameters: Value | left child pointer | right child pointer
class TreeNode {
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left =NULL;
        right = NULL;
    }
};

void inOrderTraverse(TreeNode* root_ptr) {
    if(root_ptr != NULL) {
        inOrderTraverse(root_ptr ->left);
        cout <<root_ptr ->data <<" ";
        inOrderTraverse(root_ptr ->right);
    }
}

// Calculate Height of the Node
int getHeight(TreeNode* root_ptr) {
    int leftHeight, rightHeight;

    if(root_ptr == NULL)    // Return -1 for empty Tree or Node(NULL)
        return -1;
    else {
        leftHeight = getHeight(root_ptr ->left);    // Get height of left subtree
        rightHeight = getHeight(root_ptr ->right);    // Get height of right subtree   

        if(leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
}

int main() {
    TreeNode* node1 = new TreeNode(8);
    TreeNode* node2 = new TreeNode(6);
    TreeNode* node3 = new TreeNode(15);
    TreeNode* node4 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(10);
    TreeNode* node6 = new TreeNode(17);
    TreeNode* node7 = new TreeNode(9);
    TreeNode* node8 = new TreeNode(11);
    
    // Creating Binary Search Tree:
    //       8      (height = 3)
    //      / \
    //     6   15   (height = 2)
    //    /   / \
    //   3   10  17 (height = 1)
    //      / \
    //     9   11   (height = 0)

    node1 ->left = node2;
    node1 ->right = node3;

    node2 ->left = node4;

    node3 ->left = node5;
    node3 ->right = node6;

    node5 ->left = node7;
    node5 ->right = node8;

    cout <<"Tree: "; 
    inOrderTraverse(node1);

    cout <<"\n" <<getHeight(node3);

    return 0;
}