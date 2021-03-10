//Last In First Out or First In Last Out
//push(x) - insertion 
//pop() - returns the top most element and deletes or pops top most element
//peek() or top() - returns top most element in the stack
//isEmpty() - true/false
//isFull() - true/false
//at the beginning top = -1
//can be implemented using static memory and dynamic memory
//while popping an element if the stack is empty then it is called as underflow condition
//while pushing an element if the stack is full then it is called as overflow condition
//used for reversing strings, undo in text editors
//used for balancing parenthesis
/*
	 top
 5|________|
 4|________|
 3|________|
 2|________|
 1|________|
 0|________|

*/
//implementation of stack using arrays
//Time complexity for all functions except display is O(1)
#include <stdio.h>

#define N 5
int stack[N];
int top = -1;

void push(){
	if(top==N-1){
		printf("Stack Overflow!\n");
	}
	else{
		printf("Enter data: ");
		int x;
		scanf("%d",&x);
		top++;
		stack[top]=x;
	}
}

void pop(){
	if(top==-1){
		printf("Stack Underflow!\n");
	}
	else{
		printf("%d popped\n",stack[top]);
		top--;
	}
}

void peek(){
	if(top==-1){
		printf("Stack is empty.\n");
	}
	else{
		printf("Top most element is: %d\n",stack[top]);
	}
}

void display(){
	printf("Data in stack:\n");
	for(int i=top; i>=0; i--){
		printf("%d\n",stack[i]);
	}
}

int main(){
	push();
	push();
	push();
	push();
	push();
	peek();
	pop();
	pop();
	display();

	return 0;
}


