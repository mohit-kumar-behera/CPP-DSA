#include<iostream>
using namespace std;

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void selectionSort(int arr[], int n) {
  int j,k;
  for(int i=0; i<n-1; i++) {
    for(j=k=i; j<n; j++) {
      if (arr[j] < arr[k]) 
        k = j;
    }
    swap(arr[k], arr[i]);
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
  selectionSort(arr, n);
  printArray(arr, n);
  return 0;
}