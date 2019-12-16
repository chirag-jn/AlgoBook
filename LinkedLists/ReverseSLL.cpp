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

void insertNode(Node**, int);
void print(Node*);
void reverse(Node**);

void insertNode(Node **head, int data) {
	Node *temp = new Node();
	temp->data = data;
	temp->next = (*head);
	(*head) = temp;
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

void reverse(Node **head) {
	Node * cur = (*head);
	Node *prev, *next = NULL;
	while(cur!=NULL) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	(*head) = prev;
}

signed main() {
	setEnv();

	Node *head = NULL;

	insertNode(&head, 10);
	insertNode(&head, 20);
	insertNode(&head, 30);

	print(head);

	reverse(&head);

	print(head);

	return 0;
}