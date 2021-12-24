#include<iostream>
using namespace std;

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int Partition(int arr[], int low, int high) {
  int pivot = arr[low];
  int i = low, j = high;
  do {
    do {i++;} while (arr[i] <= pivot);
    do {j--;} while (arr[j] > pivot);
    if (i < j)
      swap(arr[i], arr[j]); 
  } while (i < j);
  swap(arr[low], arr[j]);
  return j;
}

void quickSort(int arr[], int low, int high) {
  int partition;
  if (low < high) {
    partition = Partition(arr, low, high);
    quickSort(arr, low, partition);
    quickSort(arr, partition + 1, high);
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
  quickSort(arr, 0, n);
  printArray(arr, n);
  return 0;
}