#include<iostream>
using namespace std;

class Node {
    public:
        Node *left;
        Node *right;
        int data;
};

class Queue {
    Node *Q;
    Queue *next;
    public:
        Queue() {
            next = NULL;
        }
        int isEmpty();
        Queue *createNode(Node *);
        void enqueu(Node *);
        Node *dequeu();
};
Queue *front = NULL;
Queue *rear = NULL;

int Queue::isEmpty() {
    return front == NULL;
}

Queue *Queue::createNode(Node *addr) {
    Queue *q = new Queue;
    q->Q = addr;
    q->next = NULL;
    return q;
}

void Queue::enqueu(Node *addr) {
    Queue *q = createNode(addr);
    if (front == NULL) {
        front = rear = q;
    } else {
        rear->next = q;
        rear = q;
    }
}

Node *Queue::dequeu() {
    if (isEmpty())
        return NULL;
    Node *nTemp = NULL;
    Queue *qTemp;
    nTemp = front->Q;
    qTemp = front;
    front = front->next;
    delete qTemp;
    return nTemp;
}

class Tree {
    Node *root;
    public:
        Tree(){root = NULL;}
        Node *createNode(int);
        Node *createTree();
        void preorder(Node *);
        void inorder(Node *);
        void postorder(Node *);
        int countNodes(Node *);
        int height(Node *);
};

Node *Tree::createNode(int data) {
    Node *p = new Node;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Node *Tree::createTree() {
    Node *p, *t;
    Queue q;
    int x;
    cout<<"Enter data for root node :\t";
    cin>>x;
    root = createNode(x);
    q.enqueu(root);

    while(!q.isEmpty()) {
        p = q.dequeu();
        cout<<"enter left child of "<<p->data<<":\t";
        cin>>x;
        if (x != -1) {
            t = createNode(x);
            p->left = t;
            q.enqueu(t);
        }
        cout<<"enter right child of "<<p->data<<":\t";
        cin>>x;
        if (x != -1) {
            t = createNode(x);
            p->right = t;
            q.enqueu(t);
        }
    }   
    return root; 
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

int Tree::countNodes(Node *root) {
    if (!root) return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int Tree::height(Node *root) {
    int x=0, y=0;
    if (!root) return 0;  
    x = height(root->left);
    y = height(root->right);
    if (x > y) return x+1;
    else return y+1; 
}


int main() {
    Tree tree;
    Node *start;
    start = tree.createTree();
    tree.preorder(start);
    cout<<"\n";
    tree.inorder(start);
    cout<<"\n";
    tree.postorder(start);
    cout<<"\n";
    cout<<tree.countNodes(start)<<"\n";
    cout<<tree.height(start)<<"\n";
    return 0;
}