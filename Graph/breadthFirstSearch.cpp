#include<iostream>
using namespace std;

class Queue {
  int size, front, rear;
  int *elems;
  public:
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
  int temp = elems[++front];
  return temp;
}

void BFS(int startVertex, int A[][8], int n) {
  Queue q(10);
  int visited[8] = {0};

  cout<<startVertex<<", ";
  visited[startVertex] = 1;
  q.enqueue(startVertex);

  while(!q.isEmpty()) {
    int u = q.dequeue();
    for (int v=1; v<=n; v++) {
      if (A[u][v] == 1 && visited[v] == 0) {
        cout<<v<<", ";
        q.enqueue(v);
        visited[v] = 1;
      }
    }
  }
}

int main() {
  int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 1, 1, 1, 0, 0, 0},
                {0, 1, 0, 1, 0, 0, 0, 0},
                {0, 1, 1, 0, 1, 1, 0, 0},
                {0, 1, 0, 1, 0, 1, 0, 0},
                {0, 0, 0, 1, 1, 0, 1, 1},
                {0, 0, 0, 0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0, 1, 0, 0}};
  
  BFS(1, A, 8);
  cout<<"\n";
  BFS(4, A, 8);
  return 0;
}