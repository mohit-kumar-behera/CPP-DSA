#include<iostream>
#include<cmath>
using namespace std;

void mergeOneArray(int a[], int low, int mid, int high) {
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
  
  for (i=0; i<high; i++)
    a[i] = b[i];
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
  mergeOneArray(arr, 0, mid, n);
  printArray(arr, n);
  return 0;
}