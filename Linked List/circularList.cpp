#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
};

class CircularList {
	private:
		Node *head, *tail;
	public:
		CircularList() :head(NULL) {};
		~CircularList();

		bool isEmpty();
		Node *createNode(int);
		int length();

		int insertNode(int);
		int insertNodeHead(int);
		int insertNodeAt(int, int);
		int deleteHeadNode();
		int deleteLastNode();
		int deleteNodeAt(int);

		void display();
};

Node *CircularList::createNode(int val) {
	Node *p = new Node;
	p->data = val;
	p->next = NULL;
	return p;
}

bool CircularList::isEmpty() {
	if (head == NULL) return true;
	return false;
}

CircularList::~CircularList() {
	Node *p = head;

	do {
		head = head->next;
		delete p;
		p = head;
	}
	while (p != tail);
}

int formatPos(int *x, int len) {
	if (*x < 0) *x = 0;
	if (*x > len) *x = len;
}

int CircularList::length() {
	if (isEmpty()) return 0;

	int count = 0;
	Node *p = head;

	do {
		count++;
		p = p->next;
	}
	while (p != head);
	return count;
}

int CircularList::insertNode(int val) {
	Node *p = createNode(val);

	if (isEmpty()) {
		head = p;
		tail = p;
	} else {
		tail->next = p;
		tail = p;
	}
	p->next = head;

	return 1;
}

int CircularList::insertNodeHead(int val) {
	Node *p = createNode(val);

	if (isEmpty()) {
		head = p;
		tail = p;
		p->next = head;
	} else {
		tail->next = p;
		p->next = head;
		head = p;
	}
	return 1;
}

int CircularList::insertNodeAt(int pos, int val) {
	int listLength = length();
	formatPos(&pos, listLength);

	if (pos == 0) {
		insertNodeHead(val);
	} else if (pos == listLength) {
		insertNode(val);
	} else {
		Node *p = createNode(val), *temp = head;

		for(int i=1; i<pos; i++) temp = temp->next;

		p->next = temp->next;
		temp->next = p;
	}
	return 1;
}

int CircularList::deleteHeadNode() {
	Node *temp = head;
	head = head->next;
	tail->next = head;

	int val = temp->data;

	delete temp;
	return val;
}

int CircularList::deleteLastNode() {
	Node *p = head, *follower = NULL;

	while (p->next != head) {
		follower = p;
		p = p->next;
	}

	follower->next = head;
	tail = follower;

	int val = p->data;
	delete p;

	return val;
}

int CircularList::deleteNodeAt(int pos) {
	int listLength = length();
	formatPos(&pos, listLength);

	if (pos == 0) {
		deleteHeadNode();
	} else if (pos == listLength) {
		deleteLastNode();
	} else {
		Node *p = head, *follower = NULL;
		
		for(int i=1; i<pos; i++) {
			follower = p;
			p = p->next;
		}

		Node *temp = p;
		follower->next = p->next;
		int val = temp->data;

		delete temp;
		return val;
	}
}

void CircularList::display() {
	Node *p = head;

	do {
		cout<<p->data<<" ";
		p = p->next;
	} while (p != head);
	cout<<"\n";
}

int main() {
	CircularList c;
	c.insertNode(2);
	c.insertNode(5);
	c.insertNode(6);
	c.insertNodeHead(12);
	c.insertNodeAt(3, 45);
	// c.deleteHeadNode();
	c.deleteLastNode();
	// c.deleteNodeAt(3);
	c.display();
	// cout<<c.length();
}