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
void push(Stack* s_ptr, char paren) {
    if(isFull(s_ptr))
        cout <<"Stack Overflow!! Cannot add " <<paren <<" in the Stack!" <<endl;
    else {
        s_ptr ->top ++;
        s_ptr ->arr[s_ptr ->top] = paren;
    } 
}

// Pop Function to remove top element from the Stack
void pop(Stack* s_ptr) {
    if(isEmpty(s_ptr))
        cout <<"Stack Underflow!! Nothing is in the Stack!" <<endl;
    else {
        s_ptr ->top --;
    }
}

// Check the expression is balanced or not
bool checkParenthesis(Stack* s_ptr, string str) {

    /*
    If closing parenthes will appear without opening parenthesis, function will be terminated
    If opening parenthesis will appear, it will apend in the Stack
    If closing parenthesis will appear, last added opening parenthesis will be removed
    */
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')   
            push(s_ptr, str[i]);

        else if(str[i] == ')') {    // Ckeck for () parenthesis
            if(s_ptr ->arr[s_ptr ->top] == '(')
                pop(s_ptr);
            else
                return 0;
        }
        else if(str[i] == '}') {    // Ckeck for {} parenthesis
            if(s_ptr ->arr[s_ptr ->top] == '{')
                pop(s_ptr);
            else
                return 0;
        }
        else if(str[i] == ']') {    // Ckeck for [] parenthesis
            if(s_ptr ->arr[s_ptr ->top] == '[')
                pop(s_ptr);
            else
                return 0;
        }
    }    

    if(isEmpty(s_ptr))
        return true;
    else
        return false;
}

// Main Function
int main() {
    string str = "[{4+5*([54-4+65/7)]}]";

    Stack* sp = new Stack(str.length());

    if(checkParenthesis(sp, str))
        cout <<"Parenthesis are Balanced!" <<endl;
    else
        cout <<"Parenthesis are not Balanced!" <<endl; 
    
return 0;
}