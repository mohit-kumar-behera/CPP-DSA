#include <iostream>
using namespace std;

class Stack {
    int size;
    int top;
    char *elems;
    public:
        Stack() {
            size = 0;
            top = -1;
            elems = new char[size];
        }
        Stack(int sz) {
            size = sz;
            top = -1;
            elems = new char[size];
        };
        ~Stack() {
            delete [] elems;
        }
        bool isEmpty();
        bool isFull();
        bool isValidRange(int);
        int push(char);
        int pop();
        int stackTop();
        int peek(int);
};

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == size-1;
}

bool Stack::isValidRange(int pos) {
    return (pos > -1) && (pos < size);
}

int Stack::push(char val) {
    if (isFull()) 
        return -1;
    elems[++top] = val;
    return 1;
}

int Stack::pop() {
    if (isEmpty())
        return -1;
    return elems[top--];
}

int Stack::peek(int pos) {
    if(!isValidRange(pos))
        return -1;
    return elems[top-pos+1];
}

int Stack::stackTop() {
    if(isEmpty())
        return -1;
    return elems[top];
}

bool checkParanthesis(string exp) {
    int size = exp.length();
    Stack stack(size);
    
    int i = 0;
    while(exp[i] != '\0') {
        char ch = exp[i];
        if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            if(stack.isEmpty())
                return false;
            stack.pop();
        }
        i++;
    }
    return stack.isEmpty();
}

int main() {
    string exp = "((a+b)*(c-d))";
    cout<<checkParanthesis(exp);
    return 0;
}