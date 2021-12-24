#include<iostream>
using namespace std;

class Queue {
    public:
        int data;
        Queue *next;
        Queue() {
            next = NULL;
        }
        bool isEmpty();
        Queue * createNode(int);
        void enqueue(int);
        int dequeue();
        int first();
        int last();
        void display();
};
Queue *front = NULL;
Queue *rear = NULL;

Queue *Queue::createNode(int val) {
    Queue *q = new Queue;
    if (!q) return NULL;
    q->data = val;
    q->next = NULL;
    return q;
}

bool Queue::isEmpty() {
    return front == NULL;
}
void Queue::enqueue(int val) {
    Queue *q = createNode(val);
    if (!q) {
        cout<<"Queue is Full\n";
        return;
    }
    if (front == NULL) {
        front = rear = q;
    } else {
        rear->next = q;
        rear = q;
    }
}
int Queue::dequeue() {
    if (isEmpty()) {
        cout<<"Queue is Empty\n";
        return -1;
    }
    int x = front->data;
    Queue *temp = front;
    front = front->next;
    delete temp;
    return x;
}

void Queue::display() {
    Queue *p = front;
    if (p==NULL) return;
    while (p != NULL) {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<"\n";
}

int main() {
    Queue queue;
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.display();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.display();
    return 0;
}