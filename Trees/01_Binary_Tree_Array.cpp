#include <iostream>
#include <string>
using namespace std;

// Create a Binary tree using Array 
class BinaryTree {
    public: 
    int size;
    char* treeArray = new char[size];

    BinaryTree(int s) {
        size = s;
    }
};

// Insert a root element 
void root(BinaryTree* t_ptr, char key) {
    if(t_ptr ->treeArray[0] != '\0') 
        cout <<"Tree has already a root!" <<endl;
    else 
        t_ptr ->treeArray[0] = key;
}

// Insert left child if it's parent exist
void insert_left(BinaryTree* t_ptr, int parent, char key) {
    if(t_ptr ->treeArray[parent] == '\0') 
        cout <<"No Parent exist at " <<parent <<"! Can't add " <<key <<endl;
    else 
        t_ptr ->treeArray[parent*2 + 1] = key;
}

// Insert right child if it's parent exist
void insert_right(BinaryTree* t_ptr, int parent, char key) {
    if(t_ptr ->treeArray[parent] == '\0') 
        cout <<"No Parent exist at " <<parent <<"! Can't add " <<key <<endl;
    else 
        t_ptr ->treeArray[parent*2 + 2] = key;
}

void display(BinaryTree* t_ptr) {
    for (int i = 0; i < t_ptr ->size; i++)
    {
        if(t_ptr ->treeArray[i] != '\0')
            cout <<t_ptr ->treeArray[i] <<" ";
        else
            cout <<'_' <<" ";
    }
    cout <<endl;
}

// Find left and right child of given parent
void findChild(BinaryTree* t_ptr, int parent) {
    char leftChild = t_ptr ->treeArray[parent*2 +1];    // left child
    char rightChild = t_ptr ->treeArray[parent*2 +2];   // right child

    if(leftChild != '\0')
        cout <<"Left Child: " <<leftChild <<endl;
    else
        cout <<"Left Child didn't exist!!" <<endl;

    if(rightChild != '\0')
        cout <<"Right Child: " <<rightChild <<endl;
    else
        cout <<"Right Child didn't exist!!" <<endl;
}

// Find parent of given child
void findParent(BinaryTree* t_ptr, char key) {
    for (int i = 0; i < t_ptr ->size; i++)
    {
        if(t_ptr ->treeArray[i] == key) {
            cout <<"Parent of child " <<key <<" is: " <<t_ptr ->treeArray[(i-1)/2] <<" at: " <<(i-1)/2 <<endl;
            return;
        }
    }

    cout <<"Can't find Child!!" <<endl;
}

int main() {
    BinaryTree* Tp = new BinaryTree(10);    // Tree pointer to create(access) a binary tree
    
    root(Tp, 'A');  
    insert_left(Tp, 0, 'B');
    insert_right(Tp, 0, 'C');
    insert_left(Tp, 1, 'D');
    insert_right(Tp, 1, 'E');
    insert_right(Tp, 3, 'F');

    display(Tp);
    // findChild(Tp, 4);
    findParent(Tp, 'B');

    return 0;
}