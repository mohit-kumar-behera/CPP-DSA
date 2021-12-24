#include<iostream>
using namespace std;

class Stack {
  int size, top, *elems;
  public:
    Stack(int sz) {
      size = sz;
      top = -1;
      elems = new int[size];
    }
    ~Stack() {
      delete [] elems;
    }
    bool isFull();
    bool isEmpty();
    void push(int);
    int pop();
};

bool Stack::isFull() {
  return top == size-1;
}

bool Stack::isEmpty() {
  return top == -1;
}

void Stack::push(int val) {
  if (isFull()) return;
  elems[++top] = val;
}

int Stack::pop() {
  if (isEmpty()) return -1;
  int temp = elems[top--];
  return temp;
}

void DFS(int u, int A[][8], int n) {
 Stack s(10);
 int visited[8] = {0}; 
 s.push(u);

 while(!s.isEmpty()) {
   u = s.pop();
   if (visited[u] == 0) {
     cout<<u<<", ";
     visited[u] = 1;

     for (int v=1; v<=n; v++) {
       if (A[u][v] == 1 && visited[v] == 0)
        s.push(v);
     }
   }
 }
}

int main (){
  int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 1, 1, 1, 0, 0, 0},
                {0, 1, 0, 1, 0, 0, 0, 0},
                {0, 1, 1, 0, 1, 1, 0, 0},
                {0, 1, 0, 1, 0, 1, 0, 0},
                {0, 0, 0, 1, 1, 0, 1, 1},
                {0, 0, 0, 0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0, 1, 0, 0}};

  int u = 5;
  DFS(u, A, 8);
  cout << endl;

  return 0;
} 