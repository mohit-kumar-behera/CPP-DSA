#include <iostream>
using namespace std;

class Stack {
    int size;
    int top;
    int *elems;
    public:
        Stack() {
            size = 0;
            top = -1;
            elems = new int[size];
        }
        Stack(int sz) {
            size = sz;
            top = -1;
            elems = new int[sz];
        };
        ~Stack() {
            delete [] elems;
        }
        bool isEmpty();
        bool isFull();
        bool isValidRange(int);
        int push(int);
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

int Stack::push(int val) {
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

int main() {
    Stack stack(5);
    stack.push(13);
    stack.push(3);
    stack.push(24);
    stack.push(17);
    cout<<stack.stackTop();
    stack.pop();
    cout<<stack.stackTop();
    return 0;
}