#include<iostream>
using namespace std;

int getParentIndex(int i) {
  return i % 2 == 0 ? (i/2)-1 : (i/2);
}

void insertIntoHeap(int A[], int n) {
  int temp, i = n;
  temp = A[i];
  while (i>1 && temp > A[getParentIndex(i)]) {
    A[i] = A[getParentIndex(i)];
    i = getParentIndex(i);
  }
  A[i] = temp;
}

void createHeap(int A[], int n) {
  for (int i=0; i<n; i++)
    insertIntoHeap(A, i);
}

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int deleteMax(int A[], int n) {
  int i, j, temp = A[0];
  A[0] = A[n-1];
  i = 0;
  j = 2 * i + 1;
  while(j < n-1) {
    if (A[j] < A[j+1])
      j += 1;
    if (A[i] < A[j]) {
      swap(A[i], A[j]);
      i = j;
      j = 2*i + 1;
    } else {
      break;
    }
  }
  A[j] = temp;
  return temp;
}

void displayHeap(int A[], int n) {
  for (int i=0; i<n; i++)
    cout<<A[i]<<" ";
  cout<<"\n";
}

int main() {
  int Heap[]={0,14,15,5,20,30,8,40};
  int size = sizeof(Heap)/sizeof(Heap[0]);
  createHeap(Heap, size);
  displayHeap(Heap, size);
  deleteMax(Heap, size);
  displayHeap(Heap, size);
  return 0;
}