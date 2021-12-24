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
        int data;
        Stack *next;
        Stack() {
            next = NULL;
        };
        bool isEmpty();
        void push(int);
        int pop();
        int stackTop();
        int peek(int);
};
Stack *top = NULL;

bool Stack::isEmpty() {
    return top == NULL;
}

void Stack::push(int val) {
    Stack *s = new Stack;
    s->data = val;
    s->next = top;
    top = s;
}

int Stack::pop() {
    if (isEmpty())
        return '0';
    int val = top->data;
    Stack *temp = top;
    top = top->next;
    delete temp;
    return val;
}

int Stack::stackTop() {
    if (isEmpty())
        return '0';
    return top->data;
}

int convertToNum(char ch) {
    return ch - '0';
}

int evaluatePostfix(string str) {
    Stack stack;
    int i = 0, num, op1, op2, res;
    while(str[i] != '\0') {
        if (isOperand(str[i])) {
            num = convertToNum(str[i++]);
            stack.push(num);
        } else {
            op2 = stack.pop();
            op1 = stack.pop();
            switch(str[i++]) {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    res = op1 / op2;
                    break;
            }
            stack.push(res);
        }
    }
    return stack.stackTop();
}

int main() {
    string expression = "35*62/+4-";
    int res = evaluatePostfix(expression);
    cout<<res;
    return 0;
}