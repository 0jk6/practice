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

int main(){
  int n;
  cin >> n;
  while(n--){
    int x;
    cin >> x;
    insert(x);
  }
  print();
  return 0;
}