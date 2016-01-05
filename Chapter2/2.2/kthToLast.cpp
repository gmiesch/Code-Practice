#include <iostream>

using std::cout;
using std::endl;

//Basic linked-list structure needed to solve problem
struct Node {
	int data;
	Node *next;
	
	Node(int d) : data{d}, next{nullptr} { }
};

void insert(Node * &head, int data) {
	Node * newNode = new Node(data);
	newNode->next = head;
	head = newNode;
}

void printList(Node * head) {
	while(head) {
		cout << head->data << "-->";
		head = head->next;
	}
	cout << "nullptr" << endl;
}

//Returns a pointer to the node k elements from the end
//If k > length of the list then it returns the head
Node* kthToLast(int k, Node * head) {
	Node * rover1 = head;
	Node * rover2 = head;

	for(int i = 1; i <= k; i++) {
		if(rover1->next != nullptr) {
			rover1 = rover1->next;
		} else {
			return head;
		}
	}

	while(rover1->next != nullptr) {
		rover1 = rover1->next;
		rover2 = rover2->next;
	}
	return rover2;
}

int main() {
	Node * head = nullptr;
	
	for(int i = 10; i >= 0; i--) {
		insert(head, i);
	}

	printList(head);

	Node *ret = kthToLast(4, head);
	cout << ret->data << endl;

	return 0;
}
