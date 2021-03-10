//balanced parenthesis
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
	char data;
	struct Stack *next;
};

struct Stack *top, *temp, *newstack;

void push(char x){
	newstack = (struct Stack*)malloc(sizeof(struct Stack));
	newstack->data = x;
	newstack->next = top;
	top = newstack;
}

void pop(){
	if(top==NULL){
		printf("Stack underflow.\n");
	}
	else{
		printf("%c popped\n",top->data);
		temp = top;
		top = top->next;
		free(temp);
	}
}

int main(){


	return 0;
}