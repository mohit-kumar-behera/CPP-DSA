#include<iostream>
using namespace std;

bool isPrime(int val) {
  int i = 2;
  while (i < val) {
    if (val % i == 0) return false;
    i++;
  }
  return true;
}

class HashTable {
  int SIZE;
  int PRIME;
  int *h_table;
  
  int hash(int);
  int primeHash(int);
  void initializeTable();
  void setPrime();
  int doubleHashFunc(int, int);
  int doubleHash(int);
  
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

int HashTable::primeHash(int key) {
  return PRIME - (key % PRIME);
}

void HashTable::initializeTable() {
  for (int i=0; i<SIZE; i++)
    h_table[i] = 0;
}

void HashTable::setPrime() {
  int i = SIZE;
  while(i > 0) {
    if (isPrime(i)) {
      PRIME = i;
      break;
    }
    i--;
  }
}

int HashTable::doubleHashFunc(int idx, int i) {
  return (idx + i * primeHash(i)) % SIZE;
}

int HashTable::doubleHash(int key) {
  // h1(x) = (h(x) + i*primeHash(i)) % 10, where i = 0,1,2,...
  int hashIdx = hash(key);
  int i = 0;
  while (h_table[doubleHashFunc(hashIdx, i)] != 0) i++;
  return doubleHashFunc(hashIdx, i);
}

HashTable::HashTable(int sz) {
  SIZE = sz;
  h_table = new int[SIZE];
  initializeTable();
  setPrime();
}

void HashTable::insert(int key) {
  int hashIdx = hash(key);
  if (h_table[hashIdx] != 0) // index is not empty
    hashIdx = doubleHash(key);
  h_table[hashIdx] = key;
}

int HashTable::search(int key) {
  int hashIdx = hash(key);
  int i = 0;
  while(h_table[doubleHashFunc(hashIdx, i)] != key) {
    i++;
    if (h_table[doubleHashFunc(hashIdx, i)] == 0) // Reach an empty table index
      return -1;
  }
  return doubleHashFunc(hashIdx, i);
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