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
void print(Node*);
void reverse(Node**);

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

void print(Node *head) {
	Node *temp;
	temp = head;
	while(temp!=NULL) {
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

void reverse(Node **head) {
	Node *temp = NULL;
	Node *cur = (*head);
	while(cur!=NULL) {
		temp = cur->prev;
		cur->prev = cur->next;
		cur->next = temp;
		cur = cur->prev;
	}
	if(temp!=NULL) {
		(*head) = temp->prev;
	}
}

signed main() {
	setEnv();

	Node *head = NULL;
	pushNode(&head, 10);
	pushNode(&head, 20);
	pushNode(&head, 30);

	print(head);

	reverse(&head);

	print(head);

	return 0;
}