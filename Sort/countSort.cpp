#include<iostream>
using namespace std;

int findMax(int arr[], int n) {
  int max = arr[0];
  for (int i=1; i<n; i++) {
    if (arr[i] > max)
      max = arr[i];
  }
  return max;
}

void countSort(int arr[], int n) {
  int max, i, j, *countArr;
  max = findMax(arr, n);
  countArr = new int[max + 1];

  for (i=0; i<max+1; i++)
    countArr[i] = 0;

  for (i=0; i<n; i++)
    countArr[arr[i]]++;
  
  i=0, j=0;
  while (i < max+1) {
    if (countArr[i] > 0) {
      arr[j++] = i;
      countArr[i]--;
    } else {
      i++;
    }
  }
}

void printArray(int arr[], int n) {
  for (int i=0; i<n; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<"\n";
}

int main() {
  int arr[] = {6, 3, 9, 10, 15, 6, 8, 12, 3, 6};
  int n = sizeof(arr)/sizeof(arr[0]);
  printArray(arr, n);
  countSort(arr, n);
  printArray(arr, n);
  return 0;
}