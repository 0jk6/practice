//insertion - enqueue()
//deletion - dequeue()
//front - peek()
//isFull()
//isEmpty()
//time complexity O(1)
#include <stdio.h>
#define N 10

int queue[N];
int front = -1, rear = -1;

void enqueue(){
	int x;
	printf("Enter data: ");
	scanf("%d",&x);
	if(rear==-1){
		rear++;
		front++;
		queue[front] = x;
	}
	else{
		front++;
		queue[front] = x;
	}
}

void isEmpty(){
	if(front>rear){
		printf("queue is empty.\n");
	}
}

void isFull(){
	if((front==rear) && front!=-1 ){
		printf("queue is full.\n");
	}
}

void dequeue(){
	printf("%d dequeued.\n",queue[rear]);
	rear++;
}

void display(){
	printf("Data in queue:\n");
	for(int i=front; i>=rear; i--){
		printf("%d ",queue[i]);
	}
}

int main(){
	enqueue();
	enqueue();
	enqueue();
	dequeue();
	enqueue();
	dequeue();
	enqueue();
	dequeue();
	enqueue();
	enqueue();
	display();
	return 0;
}