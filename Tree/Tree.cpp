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
        Tree() {root = NULL;}
        Node *createNode(int);
        void preorder(Node *);
        void inorder(Node *);
        void postorder(Node *);
};

Node *Tree::createNode(int data) {
    Node *p = new Node;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void Tree::preorder(Node *root) {
    if (!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void Tree::inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void Tree::postorder(Node *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main() {
    Tree tree;
    Node *start;
    start = tree.createNode(20);
    start->left = tree.createNode(14);
    start->left->left = tree.createNode(24);
    start->right = tree.createNode(15);
    start->right->left = tree.createNode(5);
    tree.preorder(start);
    cout<<"\n";
    tree.inorder(start);
    cout<<"\n";
    tree.postorder(start);
    return 0;
}