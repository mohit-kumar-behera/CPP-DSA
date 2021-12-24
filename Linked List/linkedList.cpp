#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
};

class LinkedList {
	private:
		Node *head, *tail;
	public:
		LinkedList() :head(NULL) {};
		~LinkedList();

		Node *createNode(int);
		bool isEmpty();
		int length();
		
		int insertNode(int);
		int insertNodeHead(int);
		int insertNodeAt(int, int);
		int deleteHeadNode();
		int deleteNodeAt(int);

		int sumAll();
		int getMax();
		int getMin();
		Node *find(int);

		int isSorted();
		int removeDuplicate();
		int reverseList();

		int concat(LinkedList *);
		LinkedList operator + (LinkedList &);

		int isLoop();

		void display();
};

Node *LinkedList::createNode(int val) {
	Node *p = new Node;
	p->data = val;
	p->next = NULL;
	return p;
}

bool LinkedList::isEmpty() {
	return head == NULL;
}

LinkedList::~LinkedList() {
	Node *p = head;

	while (p != NULL) {
		head = head->next;
		delete p;
		p = head;
	}
}

int formatPos(int *x, int len) {
	if (*x < 0) *x = 0;
	if (*x > len) *x = len;
}

int LinkedList::length() {
	if (isEmpty()) return 0;

	int count = 1;
	Node *p = head;

	while (p->next != NULL) {
		count++;
		p = p->next;
	}
	return count;
}

int LinkedList::insertNode(int val) {
	Node *p = createNode(val);

	if (isEmpty()) {
		head = p;
		tail = p;
	} else {
		tail->next = p;
		tail = p;
	}
	return 1;
}

int LinkedList::insertNodeHead(int val) {
	Node *p = createNode(val);

	if (isEmpty()) {
		head = p;
		tail = p;
	} else {
		p->next = head;
		head = p;
	}
	return 1;
}

int LinkedList::insertNodeAt(int pos, int val) {
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

int LinkedList::deleteHeadNode() {
	Node *temp = head;
	head = head->next;
	int val = temp->data;

	delete temp;
	return val;
}

int LinkedList::deleteNodeAt(int pos) {
	int listLength = length();
	formatPos(&pos, listLength);

	if (pos == 0) {
		deleteHeadNode();
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

int LinkedList::sumAll() {
	if (isEmpty()) return 0;

	int sum = 0;
	Node *p = head;
	
	while (p != NULL) {
		sum += p->data;
		p = p->next;
	}
	return sum;
}

int LinkedList::getMax() {
	if (isEmpty()) return -1;

	Node *p = head; 
	int max = p->data;
	p = p->next;

	while (p != NULL) {
		if (p->data > max) max = p->data;
		p = p->next;
	}
	return max;
}

int LinkedList::getMin() {
	if (isEmpty()) return -1;

	Node *p = head; 
	int min = p->data;
	p = p->next;

	while (p != NULL) {
		if (p->data < min) min = p->data;
		p = p->next;
	}
	return min;
}

Node *LinkedList::find(int key) {
	if (isEmpty()) return NULL;

	Node *p = head, *q = NULL;
	while (p != NULL) {
		if (key == p->data) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

int LinkedList::isSorted() {
	Node *p = head->next;
	int val = head->data;

	while (p != NULL) {
		if (p->data < val)
			return 0;
		val = p->data;
		p = p->next;
	}
	return 1;
}

int LinkedList::removeDuplicate() {
	if (isSorted()) {
		
		Node *p = head;
		Node *q = head->next;

		while (q != NULL) {
			if (p->data != q->data) {
				p = q;
				q = q->next;
			} else {
				Node *temp = q;
				p->next = q->next;
				q = p->next;

				delete temp;
			}
		}
		return 1;
	}

	return 0;
}

int LinkedList::reverseList() {
	Node *p = head, *q = NULL, *r = NULL;

	while(p != NULL) {
		r = q;
		q = p;
		p = p->next;

		q->next = r;
	}
	head = q;

	return 1;
}

int LinkedList::concat(LinkedList *secondList) {
	Node *first = this->tail;
	Node *second = secondList->head;

	first->next = second;
}

LinkedList LinkedList::operator +(LinkedList &secondList) {

	// cout<<this->head->data<<"\n";
	// cout<<secondList.head->data;

	LinkedList *firstList = this;
	LinkedList mergedList;

	if (!firstList->isSorted() && !secondList.isSorted()) return mergedList;


	Node *firstListNode = this->head;
	Node *secondListNode = secondList.head;

	if (firstListNode->data < secondListNode->data) {
		mergedList.insertNode(firstListNode->data);
		firstListNode = firstListNode->next;
	} else {
		mergedList.insertNode(secondListNode->data);
		secondListNode = secondListNode->next;
	}

	while (secondListNode != NULL && firstListNode != NULL) {
		if (firstListNode -> data < secondListNode->data) {
			mergedList.insertNode(firstListNode->data);
			firstListNode = firstListNode->next;
		} else {
			mergedList.insertNode(secondListNode->data);
			secondListNode = secondListNode->next;  
		}
	}

	if (firstListNode != NULL) {
		while (firstListNode != NULL) {
			mergedList.insertNode(firstListNode->data);
			firstListNode = firstListNode->next;
		}
	}
	else if (secondListNode != NULL) {
		while (secondListNode != NULL) {
			mergedList.insertNode(secondListNode->data);
			secondListNode = secondListNode->next;
		}
	}

	return mergedList;
}

int LinkedList::isLoop() {
	Node *p, *q;
	p = head;
	q = head;

	do {
		p = p->next;
		q = q->next;
		q = (q != NULL) ? q->next : NULL;
	} while (p && q);

	return ( p == q ) ? true : false;
}

void LinkedList::display() {
	Node *p = head;

	if (!isEmpty()) {
		while (p != NULL) {
			cout<<p->data<<" ";
			p = p->next;
		}
		cout<<"\n";
	} else {
		cout<<"Linked list is empty\n";
	}

}


int main() {
	LinkedList p;
	p.insertNode(3);
	p.insertNode(14);
	p.insertNode(23);
	p.insertNode(37);
	p.insertNode(46);
	p.insertNode(51);
	p.insertNode(64);
	p.insertNode(79);
	p.display();
	// p.insertNodeHead(23);
	// // p.display();
	// p.insertNodeAt(2, 32);
	// p.display();
	// p.deleteHeadNode();
	// p.deleteNodeAt(4);
	// p.display();

	// cout<<p.sumAll()<<"\n";
	// cout<<p.getMin()<<"\n";
	// cout<<p.getMax()<<"\n";
	// cout<<p.find(6)<<"\n";

	// cout<<p.isSorted()<<"\n";
	// p.removeDuplicate();
	// p.display();
	// p.reverseList();
	// p.display();	

	LinkedList q;
	q.insertNode(13);
	q.insertNode(14);
	q.insertNode(23);
	q.insertNode(33);
	q.insertNode(47);
	q.display();
	// p.concat(&q);
	// p.display();
	// q.concat(&p);
	// q.display();
	// LinkedList r = p + q;
	// p.display();
	// q.display();
	// r.display();
	
	p.isLoop();
	p.display();

	return 0;
}


// class Node {
// 	private:
// 		int data;
// 		Node *next;
// 	public:
// 		bool isEmpty();
// 		Node *createNode(int);

// 		int insertNode(int);
// 		int insertNodeHead(int);
// 		int insertNodeTail(int);
// 		int insertNodeAt(int, int);

// 		int deleteHeadNode();
// 		int deleteNodeAt(int);
		
// 		int length();
// 		int sumAll();
// 		int getMax();
// 		int getMin();
// 		int find(int);

// 		int isSorted();
// 		int removeDuplicate();

// 		int reverseList();

// 		// int concat(Node *);

// 		void display();
// };

// Node *head = NULL;
// Node *tail = NULL;

// int formatPos(int *x, int len) {
// 	if (*x < 0) *x = 0;
// 	if (*x > len) *x = len;
// }

// bool Node::isEmpty() {
// 	if (head == NULL) return true;
// 	return false;
// }

// Node *Node::createNode(int val) {
// 	Node *p = new Node;
// 	p->data = val;
// 	p->next = NULL;
// 	return p;
// }

// int Node::insertNode(int val) {
// 	Node *p = createNode(val);

// 	if (isEmpty()) {
// 		head = p;
// 		tail = p;
// 	} else {  
// 		tail->next = p;
// 		tail = p;
// 	}
// 	return 1;
// }

// int Node::insertNodeHead(int val) {
// 	Node *p = createNode(val);

// 	if (isEmpty()) {
// 		head = p;
// 		tail = p;
// 	} else {
// 		p->next = head;
// 		head = p;
// 	}
// 	return 1;
// }

// int Node::insertNodeAt(int pos, int val) {
// 	int listLength = length();
// 	formatPos(&pos, listLength);

// 	if (pos == 0) {
// 		insertNodeHead(val);
// 	} else if (pos == listLength) {
// 		insertNode(val);
// 	} else {
// 		Node *p = createNode(val), *temp = head;

// 		for(int i=1; i<pos; i++) temp = temp->next;

// 		p->next = temp->next;
// 		temp->next = p;
// 	}
// 	return 1;
// }

// int Node::deleteHeadNode() {
// 	Node *temp = head;
// 	head = head->next;
// 	int val = temp->data;

// 	delete temp;
// 	return val;
// }

// int Node::deleteNodeAt(int pos) {
// 	int listLength = length();
// 	formatPos(&pos, listLength);

// 	if (pos == 0) {
// 		deleteHeadNode();
// 	} else {
// 		Node *p = head, *follower = NULL;
		
// 		for(int i=1; i<pos; i++) {
// 			follower = p;
// 			p = p->next;
// 		}

// 		Node *temp = p;
// 		follower->next = p->next;
// 		int val = temp->data;

// 		delete temp;
// 		return val;
// 	}
// }

// int Node::length() {
// 	if (isEmpty()) return 0;

// 	int count = 1;
// 	Node *p = head;

// 	while (p->next != NULL) {
// 		count++;
// 		p = p->next;
// 	}
// 	return count;
// }

// int Node::sumAll() {
// 	if (isEmpty()) return 0;

// 	int sum = 0;
// 	Node *p = head;
	
// 	while (p != NULL) {
// 		sum += p->data;
// 		p = p->next;
// 	}
// 	return sum;
// }

// int Node::getMax() {
// 	if (isEmpty()) return -1;

// 	Node *p = head; 
// 	int max = p->data;
// 	p = p->next;

// 	while (p != NULL) {
// 		if (p->data > max) max = p->data;
// 		p = p->next;
// 	}
// 	return max;
// }

// int Node::getMin() {
// 	if (isEmpty()) return -1;

// 	Node *p = head; 
// 	int min = p->data;
// 	p = p->next;

// 	while (p != NULL) {
// 		if (p->data < min) min = p->data;
// 		p = p->next;
// 	}
// 	return min;
// }

// int Node::find(int key) {
// 	if (isEmpty()) return -1;

// 	Node *p = head, *q = NULL;
// 	while (p != NULL) {
// 		if (key == p->data) {
// 			q->next = p->next;
// 			p->next = head;
// 			head = p;
// 			return 1;
// 		}
// 		q = p;
// 		p = p->next;
// 	}
// 	return 0;
// }

// int Node::isSorted() {
// 	Node *p = head->next;
// 	int val = head->data;

// 	while (p != NULL) {
// 		if (p->data < val)
// 			return 0;
// 		val = p->data;
// 		p = p->next;
// 	}
// 	return 1;
// }

// int Node::removeDuplicate() {
// 	if (isSorted()) {
// 		Node *p = head;
// 		Node *q = head->next;

// 		while (q != NULL) {
// 			if (p->data != q->data) {
// 				p = q;
// 				q = q->next;
// 			} else {
// 				Node *temp = q;
// 				p->next = q->next;
// 				q = p->next;

// 				delete temp;
// 			}
// 		}
// 		return 1;
// 	}

// 	return 0;
// }

// int Node::reverseList() {
// 	Node *p = head, *q = NULL, *r = NULL;

// 	while(p != NULL) {
// 		r = q;
// 		q = p;
// 		p = p->next;

// 		q->next = r;
// 	}
// 	head = q;

// 	return 1;
// }

// // int Node::concat(Node *q) {

// // 	return 1;
// // }

// void Node::display() {
// 	Node *p = head;

// 	if (!isEmpty()) {
// 		while (p != NULL) {
// 			cout<<p->data<<" ";
// 			p = p->next;
// 		}
// 		cout<<"\n";
// 	} else {
// 		cout<<"Linked list is empty\n";
// 	}

// }


// int main() {
// 	Node *p;
// 	p->insertNode(3);
// 	p->insertNode(7);
// 	p->insertNode(2);
// 	p->insertNode(1);
// 	p->insertNode(6);
// 	p->insertNode(4);
// 	p->insertNode(3);
// 	p->insertNode(9);
// 	p->display();

// 	// cout<<"Length: "<<p->length()<<"\n";
// 	// cout<<"Summation: "<<p->sumAll()<<"\n";
// 	// cout<<"Max: "<<p->getMax()<<"\n";
// 	// cout<<"Min: "<<p->getMin()<<"\n";
// 	// cout<<"Find 9: "<<p->find(9)<<"\n";
// 	// p->display();
// 	// cout<<"Find 20: "<<p->find(20)<<"\n";
// 	// p->display();
	
// 	// p->insertNodeAt(0, 1);
// 	// p->display();
// 	// p->insertNodeAt(-4, 1);
// 	// p->display();
// 	// p->insertNodeAt(7, 1);
// 	// p->display();
// 	// p->insertNodeAt(9, 1);
// 	// p->display();
// 	// p->insertNodeAt(4, 24);
// 	// p->display();

// 	// p->deleteHeadNode();
// 	// p->display();
// 	// p->deleteNodeAt(7);
// 	// p->display();
// 	// p->deleteNodeAt(3);
// 	// p->display();

// 	// cout<<p->isSorted();
// 	// p->removeDuplicate();
// 	// p->display();

// 	// p->reverseList();
// 	// p->display();

// 	// Node *q;
// 	// q->insertNode(12);
// 	// q->insertNode(24);
// 	// q->insertNode(81);
// 	// q->insertNode(15);
// 	// q->insertNode(35);
// 	// q->display();

// 	// p->concat(q);
// 	// p->display();
	
// 	return 0;
// }