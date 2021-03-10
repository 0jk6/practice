#include <iostream>

using namespace std;

struct Node{
	int data;
	Node *next;
	Node *prev;
};

Node *head;

void create(int data){
	Node *newnode = new Node;
	Node *temp;
	newnode->data = data;
	newnode->next = nullptr;
	newnode->prev = nullptr;
	if(head==nullptr){
		head=newnode;
		temp=newnode;
	}
	else{
		temp->next = newnode;
		newnode->prev = temp;
		temp = newnode;
	}
}

void print(){
	Node *temp = head;
	while(temp!=nullptr){
		cout << temp->data << " at " << temp->next << "\n";
		temp = temp->next;
	}
}

int main(){
	head=nullptr;
	int n;
	cin >> n;
	while(n--){
		int x;
		cin >> x;
		create(x);
	}

	cout << "Data in Doubly Linked List:\n";

	print();

	return 0;
}