#include<iostream>
using namespace std;

class Queue {
    int size, front, rear;
    int *elems;
    public:
        Queue() {
            size = 0;
            front = rear = -1;
        }
        Queue(int sz) {
            size = sz;
            front = rear = -1;
            elems = new int[size];
        }
        ~Queue() {
            delete [] elems;
        }
        bool isEmpty();
        bool isFull();
        void enqueue(int);
        int dequeue();
        int first();
        int last();
};

bool Queue::isEmpty() {
    return front == rear;
}
bool Queue::isFull() {
    return rear == size-1;
}
void Queue::enqueue(int val) {
    if (isFull()) return;
    elems[++rear] = val;
}
int Queue::dequeue() {
    if (isEmpty()) return -1;
    int x = elems[++front];
    return x;
}
int Queue::last() {
    if (rear != -1)
        return elems[rear];
    return -1;
}
int Queue::first() {
    return elems[front + 1];
}

int main() {
    Queue queue(7);
    queue.enqueue(3);
    queue.enqueue(7);
    // queue.enqueue(1);
    // queue.enqueue(2);
    // cout<<queue.first()<<"\n";
    // cout<<queue.last()<<"\n";
    // queue.dequeue();
    // cout<<queue.last()<<"\n";
    // queue.enqueue(13);
    // queue.dequeue();
    // cout<<queue.first()<<"\n";
    // cout<<queue.last()<<"\n";
    // queue.dequeue();
    // queue.dequeue();
    queue.enqueue(13);
    queue.enqueue(14);
    queue.enqueue(15);
    queue.enqueue(16);
    queue.enqueue(17);
    queue.enqueue(18);
    cout<<queue.last()<<"\n";
    return 0;
}