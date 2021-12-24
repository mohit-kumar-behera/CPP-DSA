#include<iostream>
using namespace std;

class Queue {
    public:
    int size, front, rear;
    int *elems;
    
        Queue() {
            size = 0;
            front = rear = 0;
        }
        Queue(int sz) {
            size = sz;
            front = rear = 0;
            elems = new int[size];
        }
        ~Queue() {
            delete [] elems;
        }
        int getPosition(int);
        bool isEmpty();
        bool isFull();
        void enqueue(int);
        int dequeue();
        int first();
        int last();
};
int Queue::getPosition(int x) {
    return (x + 1) % size;
}
bool Queue::isEmpty() {
    return front == rear;
}
bool Queue::isFull() {
    return getPosition(rear) == front;
}
void Queue::enqueue(int val) {
    if (isFull()) return;
    rear = getPosition(rear);
    elems[rear] = val;
}
int Queue::dequeue() {
    if (isEmpty()) return -1;
    front = getPosition(front);
    int x = elems[front];
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
    Queue queue(5);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.dequeue();
    queue.enqueue(7);
    queue.enqueue(8);
    cout<<queue.first()<<"\n";
    cout<<queue.last()<<"\n";
    cout<<queue.front<<"\n";
    cout<<queue.rear<<"\n";
    for(int i=0;i < 5; i++) {
        cout<<queue.elems[i]<<" ";
    }
    return 0;
}