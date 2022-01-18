#include <iostream>
#include <string>
using namespace std;

// Create a Stack with limited Size
class Stack {
    public:
    int size;   // Size of the Stack
    int top;    // Point to the Top most element of the Stack
    int* arr = new int[size];   // Create a Stack using Array dynamically

    Stack(int s) {
        size = s;
        top = -1;
    }
};

// Ckeck whether the Stack is empty or not
bool isEmpty(Stack* ptr) {
    if(ptr ->top < 0) 
        return true;
    else
        return false;  
}

// Ckeck whether the Stack is full or not
bool isFull(Stack* ptr) {
    if(ptr ->top == ptr ->size-1)
        return true;
    else 
        return false;
}

void display(Stack* ptr) {
    for (int i = 0; i < ptr->size; i++)
    {
        cout << ptr ->arr[i] << " ";
    }
    cout <<endl;
}

// Main Fuction
int main() {
    Stack* s = new Stack(5);   // Stack pointer to access Stack from the memory

    s->arr[0] = 5; 
    s->top ++;
    s->arr[1] = 34; 
    s->top ++;
    s->arr[2] = 23; 
    s->top ++;
    s->arr[3] = 32; 
    s->top ++;
    s->arr[4] = 65; 
    s->top ++;

    display(s);

    (isFull(s)) ? cout <<"Full" : cout <<"Not Full";
    
    return 0;  
}