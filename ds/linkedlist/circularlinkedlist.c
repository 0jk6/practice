#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *head, *temp, *newnode;

void create(int data){
	newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data=data;
	newnode->next=NULL;
	if(head==NULL){
		head=newnode;
		temp=newnode;
	}
	else{
		temp->next=newnode;
		temp=newnode;
	}
	temp->next=head;
}

void print(int n){
	temp=head;
	while(n--){
		printf("%d at %d\n",temp->data,temp->next);
		temp=temp->next;
	}
}

int main(){
	head=NULL;
	int n,x;
	scanf("%d",&n);
	int c=n;
	while(n--){
		scanf("%d",&x);
		create(x);
	}
	printf("Data in circular linked list: \n");
	print(c);
	return 0;
}