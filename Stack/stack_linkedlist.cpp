#include <iostream>
using namespace std;

class Stack {
    public:
        int data;
        Stack *next;

        Stack() {
            next = NULL;
        };

        bool isEmpty();
        // bool isValidRange(int);
        int push(int);
        int pop();
        int stackTop();
        int peek(int);
};
Stack *top = NULL;

bool Stack::isEmpty() {
    return top == NULL;
}

int Stack::push(int val) {
    Stack *s = new Stack;
    s->data = val;
    s->next = top;
    top = s;
    return 1;
}

int Stack::pop() {
    if (isEmpty())
        return -1;
    int val = top->data;
    Stack *temp = top;
    top = top->next;
    delete temp;
    return val;
}

int Stack::stackTop() {
    if (isEmpty())
        return -1;
    return top->data;
}

int main() {
    Stack stack;
    stack.push(13);
    stack.push(3);
    stack.push(24);
    stack.push(17);
    cout<<stack.stackTop();
    stack.pop();
    cout<<stack.stackTop();
    return 0;
}