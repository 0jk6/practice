#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *head, *temp, *newnode;

void create(int x){
	temp = head;
	newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = x;
	newnode->next = NULL;
	if(head==NULL){
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
	while(temp!=0){
		printf("%d",temp->data);
		temp = temp->next;
	}
}

void reverse(){
	struct Node *currentNode, *nextNode, *prevNode;
	prevNode = NULL;
	nextNode = head;
	currentNode = head;
	while(nextNode!=NULL){
		nextNode = nextNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
	}
}

int main(){

	return 0;
}