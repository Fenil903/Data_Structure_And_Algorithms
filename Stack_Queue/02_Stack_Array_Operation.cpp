#include <iostream>
#include <string>
using namespace std;

// Create a Stack with limited Size
class Stack {
    public:
    int size;   // Size of the Stack
    int top;    // Point to the Top most element of the Stack
    int* arr = new int[size];   // Create a Stack using Array

    Stack(int s) {
        size = s;
        top = -1;
    }
};

// Ckeck whether the Stack is empty or not
bool isEmpty(Stack* s_ptr) {
    if(s_ptr ->top < 0) 
        return true;
    else
        return false;  
}

// Ckeck whether the Stack is full or not
bool isFull(Stack* s_ptr) {
    if(s_ptr ->top == s_ptr ->size-1)
        return true;
    else 
        return false;
}

// Push Function to append element in the Stack
void push(Stack* s_ptr, int value) {

    /*
    First chech whether the Stack is Full or not
    If not full then append the element at the top of the Stack
    */
    if(isFull(s_ptr))    
        cout <<"Stack Overflow!! Cannot push " << value <<" int the Stack!" <<endl;
    else {
        s_ptr ->top ++;
        s_ptr ->arr[s_ptr->top] = value;
    }
}

// Pop Function to remove top element from the Stack
int pop(Stack* s_ptr) {

    /*
    First chech whether the Stack is Empty or not
    If not Empty then remove last added element from the Stack
    and return poped element
    */
    if(isEmpty(s_ptr)) {
        cout <<"Stack Underflow!! Cannot pop from the Stack!" <<endl;
        return -1;
    }
    else {
        int popedElement = s_ptr ->arr[s_ptr ->top];
        s_ptr ->top --;
        return popedElement;
    } 
}

// Return value at given position
int peak(Stack* s_ptr, int position) {
    if(s_ptr ->top - position + 1 < 0) {    // Check the given position is valid(in range of Stack) or not
        cout <<"Position out of Range!!" <<endl;
        return -1;
    }
    else 
        return s_ptr ->arr[s_ptr ->top -position + 1];   // Here 1st position data will be last added data
}

void display(Stack* s_ptr) {
    for (int i = 0; i <= s_ptr->top; i++)
    {
        cout << s_ptr ->arr[i] << " ";
    }
    cout <<endl;
}

// Main Fuction
int main() {
    Stack* sp = new Stack(5);   // Create Stack pointer to access Stack from the memory

    // (isFull(sp)) ? cout <<"Full" <<endl : cout <<"Not Full" <<endl;
    // (isEmpty(sp)) ? cout <<"Empty" <<endl : cout <<"Not Empty" <<endl;

    push(sp, 10);
    push(sp, 20);
    push(sp, 30);
    push(sp, 40);
    push(sp, 50);
    // push(sp, 500);
    display(sp);

    // pop(sp);
    // pop(sp);
    // pop(sp);
    // pop(sp);
    // pop(sp);
    // pop(sp);
    // display(sp);
    int pos = 4;

    cout << "Value at Position " <<pos <<" is " <<peak(sp, pos) <<endl;

    return 0;  
}