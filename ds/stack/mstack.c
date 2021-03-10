//Stack data structure using dynamic memory allocation

#include <stdio.h>
#include <stdlib.h>

struct Stack{
	int data;
	struct Stack *next;
};

struct Stack *top, *temp, *newstack;

void push(){
	printf("Enter data: ");
	int x;
	scanf("%d",&x);
	newstack = (struct Stack*)malloc(sizeof(struct Stack));
	newstack->data = x;
	newstack->next = NULL;
	/*if(top == NULL){
		top = newstack;
		top->next = NULL;
	}
	else{
		newstack->next = top;
		top = newstack;
	}*/
	newstack->next = top;
	top = newstack;
}

void pop(){
	if(top==NULL){
		printf("Stack underflow.\n");
	}
	else{
		printf("%d popped\n",top->data);
		temp = top;
		top = top->next;
		free(temp);
	}
}

void peek(){
	if(top==NULL){
		printf("Stack is empty\n");
	}
	else{
		printf("Top most element: %d\n",top->data);
	}
}

void display(){
	temp=top;
	if(temp==NULL){
		printf("Stack is empty.\n");
	}
	else{
		printf("Data in Stack:\n");
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}

int main(){
	top=NULL;
	int x;
	printf("\n----------STACK----------\n");
	printf("1 for push\n2 for pop\n3 for peek\n4 for display\n5 for exit\n");
	printf("-------------------------\n");
	printf("Enter your choice: ");
	while(scanf("%d",&x)!=5){
	if(x==1){
		push();
	}
	else if(x==2){
		pop();
	}
	else if(x==3){
		peek();
	}
	else if(x==4){
		display();
	}
	else{
		printf("exiting...\n");
		break;
	}
	printf("\n----------STACK----------\n");
	printf("1 for push\n2 for pop\n3 for peek\n4 for display\n5 for exit\n");
	printf("-------------------------\n");
	printf("Enter your choice: ");
	}
	return 0;
}