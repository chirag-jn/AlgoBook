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

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
}

void debug(string s) { // Doesn't run in case of an online judge
	#ifndef ONLINE_JUDGE
	cout<<s<<endl;
	#endif
}

void debug(int s) { // Doesn't run in case of an online judge
	#ifndef ONLINE_JUDGE
	cout<<s<<endl;
	#endif
}

class Node {
public:
	int data;
	Node *left;
	Node *right;
	bool operator <(const Node & obj) const
	{
		return data < obj.data;
	}
	Node() {

	}
	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

Node* searchNode(Node*, int);
Node* insertNode(Node*, int);
Node* deleteNode(Node*, int);
Node* findMinValue(Node*);
void inOrderTraverse(Node*);
void preOrderTraverse(Node*);
void postOrderTraverse(Node*);

Node* searchNode(Node* head, int key) {
	if(head == NULL) {
		cout<<"Node not found with key "<<key<<endl;
		return NULL;
	}
	if(head->data == key) {
		return head;
	} else if(head->data > key) {
		return searchNode(head->left, key);
	} else {
		return searchNode(head->right, key);	
	}
}

Node* insertNode(Node* head, int key) {
	if(head!=NULL && head->data == key) {
		cout<<"Value already exists"<<endl;
		return NULL;
	} 
	if(head == NULL) {
		return new Node(key);
	}
	if(head->data > key) {
		head->left = insertNode(head->left, key);
	} else if(head->data < key) {
		head->right = insertNode(head->right, key);
	}
	return head;
}

Node* deleteNode(Node *head, int key) {
	if(head==NULL) {
		return head;
	}
	if(head->data == key) {
		if(head->left == NULL) {
			Node *temp = head->right;
			free(head);
			return temp;
		} else if(head->right == NULL) {
			Node *temp = head->left;
			free(head);
			return temp;
		} else {
			Node *temp = findMinValue(head->right);
			head->data = temp->data;
			head->right = deleteNode(head->right, temp->data);	
		}
	} else if(head->data > key) {
		head->left = deleteNode(head->left, key);
	} else {
		head->right = deleteNode(head->right, key);
	}
	return head;
}

Node* findMinValue(Node *head) {
	Node *temp = head;
	while(temp!=NULL && temp->left!=NULL) {
		temp = temp->left;
	}
	return temp;
}

void inOrderTraverse(Node* head) {
	if(head == NULL) {
		return;
	}
	inOrderTraverse(head->left);
	cout<<head->data<<" ";
	inOrderTraverse(head->right);
}

void preOrderTraverse(Node *head) {
	if(head==NULL) {
		return;
	}
	cout<<head->data<<" ";
	preOrderTraverse(head->left);
	preOrderTraverse(head->right);
}

void postOrderTraverse(Node *head) {
	if(head==NULL) {
		return;
	}
	postOrderTraverse(head->left);
	postOrderTraverse(head->right);
	cout<<head->data<<" ";
}

void solve() {

	Node *head = NULL;
	head = insertNode(head, 30);
	head = insertNode(head, 10);
	head = insertNode(head, 20);
	head = insertNode(head, 40);
	head = insertNode(head, 50);
	debug(head->data);
	inOrderTraverse(head);
	cout<<endl;
	preOrderTraverse(head);
	cout<<endl;
	postOrderTraverse(head);
	cout<<endl;
	deleteNode(head, 30);
	inOrderTraverse(head);
	cout<<endl;
	preOrderTraverse(head);
	cout<<endl;
	postOrderTraverse(head);
	cout<<endl;
}

signed main() {
	setEnv();

	int t = 1;
	// cin>>t;
	while(t--) {
		solve();
	}

	return 0;
}