#include <iostream>
#include <string>
using namespace std;

class Stack {
    public:
    int top;
    int size;
    char* arr = new char[size];

    Stack(int length) {
        top = -1;
        size = length;
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

// Push Function to append element in the Stack
void push(Stack* s_ptr, char value) {
    if(isFull(s_ptr))
        cout <<"Stack Overflow!! Cannot add " <<value <<" in the Stack!" <<endl;
    else {
        s_ptr ->top ++;
        s_ptr ->arr[s_ptr ->top] = value;
    } 
}

// Pop Function to remove top element from the Stack
char pop(Stack* s_ptr) {
    if(isEmpty(s_ptr)) {
        cout <<"Stack Underflow!! Nothing is in the Stack!" <<endl;
        return -1;
    }
    else {
        char popedValue = s_ptr ->arr[s_ptr ->top];
        s_ptr ->top --;
        return popedValue;
    }
}

// Return Top Most element of the Stack
char stackTop(Stack* s_ptr) {
    return s_ptr ->arr[s_ptr ->top];
}

// Check for valid Operand
int isOperand(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
        return 1;
    else
        return 0;
}

// Return precedence of operand
int precedence(char ch) {
    if(ch == '*' || ch == '/' || ch == '%')
        return 3;
    else if(ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

// Convert infix expression to postfix expression
string infixToPostfix(Stack* s_ptr, string infix) {
    string postfix = "";    // Postfix Expression
    int i_Tr = 0;

    while (infix[i_Tr] != '\0')    // Traverse in infix expression
    {   
        // If the character is not valid operand than append it in the postfix expression
        if(!isOperand(infix[i_Tr])) {
            postfix = postfix + infix[i_Tr];
            i_Tr ++;
        }

        else {
            // If the current operand's precedence is higher than top element of stack
            // Then we append that operand to the stack
            // Else we remove top elements from stack and add into postfix expression
            if(precedence(infix[i_Tr]) > precedence(stackTop(s_ptr))) {
                push(s_ptr ,infix[i_Tr]);
                i_Tr ++;
            }
            else {
                postfix = postfix + pop(s_ptr);
            }
        }
    }

    // Append all remaning operands to the postfix expression
    while (!isEmpty(s_ptr))
    {
        postfix = postfix + pop(s_ptr);
    }
    
    return postfix;
}

// Main Function
int main() {
    string infix = "x-y/z-k*d";    // Infix Expression

    Stack* sp = new Stack(infix.length());
    
    sp ->arr[sp ->top] = 'c';   // Initially stack should not be empty
    cout <<"Infix Expression: " <<infix <<endl;
    cout <<"Postfix Expression: " <<infixToPostfix(sp, infix) <<endl;;

return 0;
}