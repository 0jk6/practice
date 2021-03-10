#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node *head, *newnode, *temp, *temp1;

void createnode(int data){
  newnode = (struct Node*)malloc(sizeof(struct Node));
  newnode->data = data;
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

void deleteNode(int pos, int length){
  temp = head;
  temp1 = head;
  int i=1;
  if(pos>length){
    printf("Invalid position\n");
  }
  else if(pos==1){
    head=temp->next;
    free(temp);
  }
  else{
    while(i<pos){
      temp = temp->next;
      i++;
    }
    i=1;
    while(i<pos-1){
      temp1 = temp1->next;
      i++;
    }

    temp1->next = temp->next;
    free(temp);
  }
}

void insert(int data, int pos, int length){
  temp = head;
  int i = 1;
  if(pos>length){
    printf("Invalid position\n");
  }
  else{
    while(i<pos){
      temp = temp->next;
      i++;
    }
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = temp->next;
    temp->next = newnode;
  }
}

void printdata(){
  temp=head;
  printf("data in linked list: \n");
  while(temp!=NULL){
    printf("Data: %d\n",temp->data);
    temp = temp->next;
  }
}

int main(){
  head = NULL;
  printf("How many numbers you want to insert?\n");
  int n;
  int length;
  scanf("%d",&n);
  length = n;
  while(n--){
    int x;
    printf("Enter data: ");
    scanf("%d",&x);
    createnode(x);
  }

  insert(34,3,length);
  printdata();
  deleteNode(4,length);
  printf("----------------------------\n");
  printdata();

  return 0;
}