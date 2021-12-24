#include<iostream>
using namespace std;

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void insertionSort(int arr[], int n) {
  int temp, j;
  for(int i=1; i<n; i++) {
    temp = arr[i];
    j = i-1;
    while (j>-1 && arr[j] > temp) {
      swap(arr[j+1], arr[j]);
      j--;
    }
    arr[j+1] = temp;
  }
}

void printArray(int arr[], int n) {
  for (int i=0; i<n; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<"\n";
}

int main() {
  int arr[] = {5, 3, 2, 7, 5, 9, 10, 3, 12};
  int n = sizeof(arr)/sizeof(arr[0]);
  printArray(arr, n);
  insertionSort(arr, n);
  printArray(arr, n);
  return 0;
}