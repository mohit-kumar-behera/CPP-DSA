#include<iostream>
#include<cmath>
using namespace std;

void merge(int a[], int low, int mid, int high) {
  int i, j, k;
  i = k = low, j = mid + 1;
  int b[high];

  while (i<=mid && j<high) {
    if (a[i] < a[j])
      b[k++] = a[i++];
    else  
      b[k++] = a[j++];
  }

  while (i<=mid)
    b[k++] = a[i++];

  while (j<high)
    b[k++] = a[j++];
  
  for (i=low; i<high; i++)
    a[i] = b[i];
}

void mergeSort(int a[], int low, int high) {
  int mid;
  if (low < high) {
    mid = floor((low + high) / 2);
    mergeSort(a, low, mid);
    mergeSort(a, mid+1, high);
    merge(a, low, mid, high);
  }
}

void printArray(int arr[], int n) {
  for (int i=0; i<n; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<"\n";
}

int main() {
  int arr[] = {2, 5, 8, 12, 13, 6, 7, 10};
  int n = sizeof(arr)/sizeof(arr[0]);
  int mid = floor(n / 2);
  printArray(arr, n);
  mergeSort(arr, 0, n);
  printArray(arr, n);
  return 0;
}