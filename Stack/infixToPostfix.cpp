#include <iostream>
using namespace std;

int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

int isOperand(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 0;
    return 1;
}

class Stack {
    public:
        char data;
        Stack *next;
        Stack() {
            next = NULL;
        };
        bool isEmpty();
        void push(char);
        char pop();
        char stackTop();
        char peek(char);
};
Stack *top = NULL;

bool Stack::isEmpty() {
    return top == NULL;
}

void Stack::push(char val) {
    Stack *s = new Stack;
    s->data = val;
    s->next = top;
    top = s;
}

char Stack::pop() {
    if (isEmpty())
        return '0';
    char val = top->data;
    Stack *temp = top;
    top = top->next;
    delete temp;
    return val;
}

char Stack::stackTop() {
    if (isEmpty())
        return '0';
    return top->data;
}

string infixToPostfix(string str) {
    Stack stack;
    string postfix;
    int i = 0;
    while (str[i] != '\0') {
        if (isOperand(str[i])) {
            postfix.push_back(str[i++]);
        } else {
            if (precedence(str[i]) > precedence(stack.stackTop())) {
                stack.push(str[i++]);
            } else {
                postfix.push_back(stack.pop());
            }
        }
    }

    while(!stack.isEmpty()) {
        postfix.push_back(stack.pop());
    }
    postfix[i] = '\0';
    return postfix;
}

int main() {
    string expression = "a+b*c-D/E";
    string postfix = infixToPostfix(expression);
    for (int i=0; i<postfix.length(); i++) {
        cout<<postfix[i];
    }
    return 0;
}
