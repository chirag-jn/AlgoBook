#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define endl '\n'

void setEnv() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("../input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("../output.txt", "w", stdout);
    // for writing error to error.txt
    freopen("../error.txt", "w", stderr);
	#endif
}

class Node {
public:
	int data;
	Node *prev;
	Node *next;
};

void pushNode(Node**, int);
void appendNode(Node**, int);
void print(Node*);
void insertBefore(Node**, int, int);
Node* searchNode(Node**, int);
void deleteNode(Node**, int);

// Inserting Node at front
void pushNode(Node** head, int data) {
	Node *temp = new Node();
	temp->data = data;
	temp->prev = NULL;
	temp->next = (*head);

	if((*head)!=NULL) {
		(*head)->prev = temp;
	} 

	(*head) = temp;

}

// Adding a node at the end
void appendNode(Node **head, int data) {
	Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if((*head)==NULL) {
		temp->prev = NULL;
		(*head) = temp;
		return;
	}	

	Node *last = (*head);
	while(last->next!=NULL) {
		last = last->next;
	}

	last->next = temp;
	temp->prev = last;
}

void print(Node *head) {
	Node *temp;
	temp = head;
	while(temp!=NULL) {
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

void insertBefore(Node **head, int data, int key) {
	Node *temp = new Node();
	temp->data = data;

	Node *nextNode = (*head);
	while(nextNode!=NULL && nextNode->data!=key) {
		nextNode = nextNode->next;
	}

	if(nextNode==NULL) {
		cout<<"Key doesn't exist"<<endl;
		return;
	}

	temp->prev = nextNode->prev;
	nextNode->prev = temp;
	temp->next = nextNode;
	if (temp->prev!=NULL) {
		temp->prev->next = temp;
	} else {
		// it's the first node.
		// you can eliminate this somehow though
		(*head) = temp;
	}
}

Node *searchNode(Node**head, int key) {
	Node *temp = (*head);
	while(temp!=NULL) {
		if(temp->data == key) {
			return temp;
		} else {
			temp = temp->next;
		}
	}
	return NULL;
}

void deleteNode(Node **head, int key) {
	Node *toDel = searchNode(head, key);
	if(toDel==NULL) {
		cout<<"Node doesn't exist"<<endl;
		return;
	}
	if((*head)==NULL) {
		cout<<"List empty"<<endl;
		return;
	}

	// Checking head node
	if((*head)==toDel) {
		(*head) = toDel->next;
	}

	// Changing next if toDel isn't last
	if(toDel->next!=NULL) {
		toDel->next->prev = toDel->prev;
	}

	// Changing prev if toDel isn't the first node
	if(toDel->prev!=NULL) {
		toDel->prev->next = toDel->next;
	}

	free(toDel);
}

signed main() {
	setEnv();

	Node *head = NULL;
	int temp;

	for(int i=0; i<5; i++) {
		cin>>temp;
		pushNode(&head, temp);
	}

	print(head);

	for(int i=0; i<5; i++) {
		cin>>temp;
		appendNode(&head, temp);
	}

	print(head);

	insertBefore(&head, 12, 0); // should give an error as 0 doesn't exist

	insertBefore(&head, 11, 1);
	print(head);

	deleteNode(&head, 2);
	print(head);

	return 0;
}