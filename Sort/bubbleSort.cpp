#include<iostream>
using namespace std;

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void bubbleSort(int arr[], int n) {
  for(int i=0; i<n-1; i++) {
    int flag = 0;
    for (int j=0; j<n-1-i; j++) {
      if (arr[j] > arr[j+1]) {
        swap(arr[j], arr[j+1]);
        flag = 1;
      }
    }
    if (flag == 0) break;
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
  bubbleSort(arr, n);
  printArray(arr, n);
  return 0;
}