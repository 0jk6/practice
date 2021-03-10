#include <stdio.h>
#include <stdlib.h>

struct queue{
	int data;
	struct queue *next;
};

struct queue *head, *tail, *temp;

void enqueue(int data){
	struct queue *newnode = (struct queue*)malloc(sizeof(struct queue));
	newnode->data = data;
	newnode->next = NULL;
	if(head==NULL){
		head = newnode;
		tail = newnode;
	}
	else{
		tail->next = newnode;
		temp = tail;
		tail = newnode;
	}
}

void dequeue(){
	tail = temp;
	tail->next = NULL;
	free(temp->next);
}

void display(){
	struct queue *temp1 = head;
	while(temp1!=NULL){
		printf("%d ",temp1->data);
		temp1 = temp1->next;
	}
}

int front(){
	return head->data;
}

int isEmpty(){
	if(head==NULL)
		return 1;
	else
		return 0;
}

int main(){
	head = NULL;
	tail = NULL;
	temp = NULL;
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);
	dequeue();
	printf("front: %d\n",front());
	printf("isEmpty: %d\n",isEmpty());
	display(head);
	return 0;
}
