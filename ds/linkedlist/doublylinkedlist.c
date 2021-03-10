#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
};

struct Node *head, *newnode, *temp;

void create(int data){
  newnode = (struct Node*)malloc(sizeof(struct Node));
  newnode->data = data;
  newnode->next = NULL;
  newnode->prev = NULL;
  if(head==NULL){
    head=newnode;
    temp=newnode;
  }
  else{
    temp->next=newnode;
    newnode->prev=temp;
    temp=newnode;
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
    newnode->prev = temp;
    temp->next = newnode;

  }
}

void print(){
  temp = head;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
}


int main(){
  head = NULL;
  int n;
  printf("How many numbers you want to enter?\n");
  scanf("%d",&n);
  int c = n;
  while(n--){
    int x;
    scanf("%d",&x);
    create(x);
  }
  printf("Data in doubly linked list: \n");
  print();
  printf("\nDo you want to insert an element in between?\n");
  int m;
  printf("1 for YES and 0 for NO: ");
  scanf("%d",&m);

  if(m==1){
    int data;
    printf("Enter data: ");
    scanf("%d",&data);
    printf("Enter position after which you want to insert: ");
    int pos;
    scanf("%d",&pos);
    insert(data,pos,c);
    print();
  }
  else{
    printf("exiting...\n");
  }





  return 0;
}