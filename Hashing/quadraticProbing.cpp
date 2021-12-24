#include<iostream>
using namespace std;

class HashTable {
  int SIZE;
  int *h_table;
  int hash(int);
  void initializeTable();
  int quadraticProbeFunc(int, int);
  int quadraticProbe(int);
  public:
    HashTable(int); 
    void insert(int);
    int search(int);
    void display();
    ~HashTable();
};

int HashTable::hash(int key) {
  return key % SIZE;
}

void HashTable::initializeTable() {
  for (int i=0; i<SIZE; i++)
    h_table[i] = 0;
}

int HashTable::quadraticProbeFunc(int idx, int i) {
  return (idx + i * i) % SIZE;
}

int HashTable::quadraticProbe(int key) {
  // h1(x) = (h(x) + f(i)) % 10, where f(i) = i*i and i = 0,1,2,...
  int hashIdx = hash(key);
  int i = 0;
  while (h_table[quadraticProbeFunc(hashIdx, i)] != 0) i++;
  return quadraticProbeFunc(hashIdx, i);
}

HashTable::HashTable(int sz) {
  SIZE = sz;
  h_table = new int[SIZE];
  initializeTable();
}

void HashTable::insert(int key) {
  int hashIdx = hash(key);
  if (h_table[hashIdx] != 0) // index is not empty
    hashIdx = quadraticProbe(key);
  h_table[hashIdx] = key;
}

int HashTable::search(int key) {
  int hashIdx = hash(key);
  int i = 0;
  while(h_table[quadraticProbeFunc(hashIdx, i)] != key) {
    i++;
    if (h_table[quadraticProbeFunc(hashIdx, i)] == 0) // Reach an empty table index
      return -1;
  }
  return quadraticProbeFunc(hashIdx, i);
}

void HashTable::display() {
  for (int i=0; i<SIZE; i++)
    cout<<i<<" -> "<<h_table[i]<<"\n";
}

HashTable::~HashTable() {
  delete [] h_table;
}

int main() {
  int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
  int arrSize = sizeof(A)/sizeof(A[0]);
  int hashTableSize = arrSize * 2;
  HashTable H_Table(hashTableSize);

  cout<<"Inserting...\n";
  for (int i=0; i<arrSize; i++)
    H_Table.insert(A[i]);\

  cout<<"\nSearching...\n";
  int keys[] = {6, 26, 45, 10};
  int keySize = sizeof(keys)/sizeof(keys[0]);
  for (int i=0; i<keySize; i++) {
    int data = H_Table.search(keys[i]);
    cout<<keys[i];
    if (data == -1) cout<<" not found\n";
    else cout<<" found at index "<<data<<"\n";
  }

  cout<<"\nHash Table\n---------------\n";
  H_Table.display();

  return 0;
}