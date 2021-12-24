#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;
};

class Tree {
  Node *root;
  public:
    Tree():root(NULL) {};
    Node *getRoot() {
      return root;
    };
    Node *createNode(int);
    Node *insertData(Node *,int);
    Node *search(Node *, int);
    Node *deleteData(Node *, int);
    Node *inorderPrec(Node *);
    Node *inorderSucc(Node *);
    int height(Node *);
    void inorder(Node *);
};

int Tree::height(Node *p) {
  int x, y;
  if (p == NULL) return 0;
  x = height(p->left);
  y = height(p->right);
  return x>y ? x+1 : y+1;
}

Node *Tree::createNode(int data) {
  Node *p = new Node;
  p->data = data;
  p->left = p->right = NULL;
  if (root == NULL) root = p;
  return p; 
}

Node *Tree::insertData(Node *p, int data) {
  if (p == NULL) {
    p = createNode(data);
    return p;
  }

  if (data < p->data)
    p->left = insertData(p->left, data);
  else if (data > p->data)
    p->right = insertData(p->right, data);
  return p;
}

Node *Tree::search(Node *p, int key) {
  if (p == NULL) return NULL;
  
  if (key == p->data)
    return p;
  else if (key < p->data)
    return search(p->left, key);
  else
    return search(p->right, key);
}

Node *Tree::inorderPrec(Node *p) {
  if (p && p->right != NULL) return inorderPrec(p->right);
  return p;  
}

Node *Tree::inorderSucc(Node *p) {
  if (p && p->left != NULL) return inorderSucc(p->left);
  return p;  
}

Node *Tree::deleteData(Node *p, int key) {
  Node *q;
  if (p == NULL) {
    return NULL;
  }

  if (p->left == NULL && p->right == NULL) {
    if (p == root) root = NULL;
    delete p;
    return NULL;
  }

  if (key < p->data) {
    p->left = deleteData(p->left, key);
  } else if (key > p->data) {
    p->right = deleteData(p->right, key);
  } else {
    // key is found
    if (height(p->left) > height(p->right)) {
      q = inorderPrec(p->left);
      p->data = q->data;
      p->left = deleteData(p->left, q->data);
    } else {
      q = inorderSucc(p->right);
      p->data = q->data;
      p->right = deleteData(p->right, q->data);
    }
  }
  return p;
}

void Tree::inorder(Node *p) {
  if (p == NULL) return;
  inorder(p->left);
  cout<<p->data<<" ";
  inorder(p->right);
}

int main() {
  Tree tree;
  tree.insertData(tree.getRoot(), 30);
  tree.insertData(tree.getRoot(), 20);
  tree.insertData(tree.getRoot(), 40);
  tree.insertData(tree.getRoot(), 10);
  tree.insertData(tree.getRoot(), 25);
  tree.insertData(tree.getRoot(), 35);
  tree.insertData(tree.getRoot(), 45);
  tree.insertData(tree.getRoot(), 42);
  tree.insertData(tree.getRoot(), 43);
 
  tree.inorder(tree.getRoot());
  cout<<"\n";

  cout<<"Find 23 : "<<tree.search(tree.getRoot(), 23)<<"\n";
  cout<<"Find 20 : "<<tree.search(tree.getRoot(), 20)<<"\n";
  cout<<"Find 45 : "<<tree.search(tree.getRoot(), 45)->data<<"\n";
  cout<<"Find 35 : "<<tree.search(tree.getRoot(), 35)->data<<"\n";

  cout<<"height : "<<tree.height(tree.getRoot())<<"\n";

  cout<<"prec of 30 : "<<tree.inorderPrec(tree.getRoot()->left)->data<<"\n";
  cout<<"succc of 30 : "<<tree.inorderSucc(tree.getRoot()->right)->data<<"\n";

  tree.deleteData(tree.getRoot(), 25);
  tree.inorder(tree.getRoot());
  cout<<"\n";

  tree.deleteData(tree.getRoot(), 43);
  tree.inorder(tree.getRoot());
  cout<<"\n";

  tree.deleteData(tree.getRoot(), 45);
  tree.inorder(tree.getRoot());
  cout<<"\n";
  
  tree.deleteData(tree.getRoot(), 30);
  tree.inorder(tree.getRoot());
  cout<<"\n";
  
  return 0;
}