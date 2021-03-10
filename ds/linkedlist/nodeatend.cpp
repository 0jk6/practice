#include <iostream>

using namespace std;

struct Node{
  int data;
  Node *next;
};

Node *head = nullptr;
Node *newnode, *temp;

void insert(int data){
  Node *newnode = new Node;
  newnode->data = data;
  newnode->next = nullptr;
  if(head==nullptr){
    head=newnode;
    temp=newnode;
  }
  else{
    temp->next=newnode;
    temp=newnode;
  }
}

void print(){
  temp = head;
  while(temp!=nullptr){
    cout << temp->data << "\n";
    temp = temp->next;
  }
}

void insertAt(int data, int pos, int n){
	Node *newnode = new Node;
	if(pos>n){
		cout << "Invalid position" << "\n";
	}
	else{
		cout << "Inserting Node after position " << n << "\n"; 
		temp = head;
		int i=1;
		while(i<pos){
			temp = temp->next;
			i++;
		}
		newnode->data = data;
		newnode->next = temp->next;
		temp->next = newnode;
	}
}

int main(){
  int n, x;
  cout << "How many elements do you want to enter?\n";
  cin >> n;
  int length = n;
  while(n--){
    cout << "Enter Data: ";
    cin >> x;
    insert(x);
  }
  cout << "Data in Linked list: \n";
  print();
  cout << "Do you want to insert any data in between?\n";
  cout << "1 for Yes and 0 for No: ";
  int c;
  cin >> c;
  if(c==1){
  	cout << "Enter data: ";
  	cin >> x;
  	cout << "Enter position after which you want to insert the data: ";
  	int p;
  	cin >> p;
  	insertAt(x,p,length);
  	cout << "-------------------------------------------" << "\n";
  	cout << "New data in linked list: \n";
  	print();
  }
  else{
  	cout << "exiting the program...\n";
  }
  

  return 0;
}