#include<iostream>
using namespace std;

void mergeTwoArray(int a[], int b[], int c[], int m, int n) {
  int i, j, k;
  i = j = k = 0;
  
  while (i<m && j<n) {
    if (a[i] < b[j])
      c[k++] = a[i++];
    else 
      c[k++] = b[j++];
  }

  while(i<m)
    c[k++] = a[i++];
  
  while(j<n)
    c[k++] = b[j++];
}

void printArray(int arr[], int n) {
  for (int i=0; i<n; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<"\n";
}

int main() {
  int arr1[] = {2, 10, 18, 20, 23};
  int arr2[] = {4, 9, 19, 25, 30, 32};
  int n1 = sizeof(arr1)/sizeof(arr1[0]);
  int n2 = sizeof(arr2)/sizeof(arr2[0]);
  printArray(arr1, n1);
  printArray(arr2, n2);
  int mergedArr[n1 + n2];
  mergeTwoArray(arr1, arr2, mergedArr, n1, n2);
  printArray(mergedArr, n1+n2);
  return 0;
}