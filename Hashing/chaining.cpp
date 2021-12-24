#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
};

class HashTable {
  Node **HT;
  int SIZE;
  void insertNode(Node *);
  int searchNode(int);
  int hash(int);
  void initializeTable();
  public:
    HashTable(int);
    Node * createNode(int);

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
    HT[i] = NULL;
}


HashTable::HashTable(int sz) {
  SIZE = sz;
  HT = new Node*[SIZE];
  initializeTable();
}

Node *HashTable::createNode(int val) {
  Node *p = new Node;
  p->data = val;
  p->next = NULL;
  return p;
}

void HashTable::insertNode(Node *newNode) {
  int hashIdx = hash(newNode->data);
  if (HT[hashIdx] == NULL) {
    HT[hashIdx] = newNode;
  } else {
    Node *successor = HT[hashIdx];
    Node *follower = HT[hashIdx];
    bool flag = false;
    while (successor && successor->data < newNode->data) {
      follower = successor;
      successor = successor->next;
      flag = true; // follower is changed
    } 

    if (!flag) {
      // node to be inserted at first position
      newNode->next = follower->next;
      HT[hashIdx] = newNode;
    } else {
      newNode->next = follower->next;
      follower->next = newNode;
    }

  }
}

int HashTable::searchNode(int key) {
  int hashIdx = hash(key);
  Node *searchInIdx = HT[hashIdx];
  while(searchInIdx) {
      if (searchInIdx->data == key)
        return searchInIdx->data;
      searchInIdx = searchInIdx->next;
  }
  return -1;
}

void HashTable::insert(int key) {
  Node *p = createNode(key);
  insertNode(p);
}

int HashTable::search(int key) {
  int foundData = searchNode(key);
  return foundData;
}

void HashTable::display() {
  for (int i=0; i<SIZE; i++) {
    Node *currIdx = HT[i];
    cout<<i<<" : ";
    if (!currIdx) cout<<"null";
    while(currIdx) {
      cout<<currIdx->data;
      if (currIdx->next != NULL) cout<<" -> ";
      currIdx = currIdx->next;
    }
    cout<<"\n";
  }
}

HashTable::~HashTable() {
  for (int i=0; i<SIZE; i++) {
    Node *startFromNode = HT[i];
    Node *temp = HT[i];
    while(startFromNode) {
      startFromNode = startFromNode->next;
      delete temp;
      temp = startFromNode;
    }
  }
  delete [] HT;
}

int main() {
  int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
  int arrSize = sizeof(A)/sizeof(A[0]);
  int hashTableSize = arrSize * 2;
  HashTable H_Table(hashTableSize);

  cout<<"Inserting...\n";
  for (int i=0; i<arrSize; i++)
    H_Table.insert(A[i]);\

  cout<<"\nSearching...\n";
  int keys[] = {6, 10};
  int keySize = sizeof(keys)/sizeof(keys[0]);
  for (int i=0; i<keySize; i++) {
    int data = H_Table.search(keys[i]);
    cout<<keys[i];
    if (data == -1) cout<<" not found\n";
    else cout<<" found\n";
  }

  cout<<"\nHash Table\n---------------\n";
  H_Table.display();
  return 0;
}

