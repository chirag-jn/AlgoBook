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
	Node *next;
};

// Double star for call by reference
void insertNode(Node**, int);
void deleteList(Node**);
void deleteNode(Node**, int);
void print(Node*);

void insertNode(Node **head, int data) {
	Node *temp = new Node();
	temp->data = data;
	temp->next = (*head);
	(*head) = temp;
}

void deleteList(Node **head) {
	Node *cur, *next;
	cur = *head;
	while(cur!=NULL) {
		next = cur->next;
		free(cur);
		cur = next;
	}
	*head = NULL;
}

void deleteNode(Node **head, int key) {
	Node *temp, *prev;
	temp = *head;
	// Head node is the required node to be deleted.
	if(temp!=NULL && temp->data==key) {
		*head = temp->next;
		free(temp);
		return;
	}
	// Traversing to the node before the node to be deleted.
	while(temp!=NULL && temp->data!=key) {
		prev = temp;
		temp = temp->next;
	}
	
	// Key doesn't exist
	if(temp==NULL) return;

	// Key exists
	prev->next = temp->next;
	free(temp);
}

void print(Node *head) {
	Node *temp = head;
	if(temp==NULL) {
		cout<<"Empty"<<endl;
	}
	while(temp!=NULL) {
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

signed main() {
	setEnv();

	Node *head = NULL;
	int temp;

	for(int i=0; i<5; i++) {
		cin>>temp;
		insertNode(&head, temp);
	}

	print(head);
	deleteNode(&head, 4);
	print(head);
	deleteList(&head);
	print(head);

	return 0;
}