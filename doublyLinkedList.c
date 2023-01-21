#include <stdio.h>
#include <stdlib.h>
int size;

struct node * createDoubleLinkedList(int data);
struct node * insertLast(struct node *first, int data);
void traverseLinkedList(struct node *first);
struct node* insertFront(struct node *first, int data);
struct node* insertAfter(struct node *first, int y ,int data);

void main(){
   struct node *first = createDoubleLinkedList(10);
   first = insertLast(first,20);
   first = insertLast(first,30);
   first = insertLast(first,40);
   first = insertFront(first,50);
   first = insertAfter(first,30,70);
   traverseLinkedList(first);
   
   
}

struct node{
   int data;
   struct node *next;
   struct node *prev;
};

struct node * createDoubleLinkedList(int data){
   struct node *first = NULL;
   struct node *new;

   new = (struct node*)malloc(sizeof(struct node));
   new->data=data;
   new->next=NULL;
   new->prev=NULL;
   first = new;
   size=1;
   return first;
}

struct node * insertLast(struct node *first, int data){
   if(first==NULL){
      first = createDoubleLinkedList(data);
      return first;
   }
   else{
      struct node *new = (struct node*)malloc(sizeof(struct node));
      new->data=data;
      new->next=NULL;
      struct node *temp=first;
      while(temp->next!=NULL){
      temp=temp->next;
      }
      new->prev=temp;
      temp->next=new;
      size++;
      return first;
   }
   
}

void traverseLinkedList(struct node *first){
   struct node *temp = first;
   //prev->ptr=first;
   printf("Size of Linked list = %d\n",size);
   printf("data = %d Address = %d Prev address = %d Next address = %d\n", first->data ,first ,first->prev ,first->next);
   while(temp->next!=NULL){
      temp=temp->next;
      printf("data = %d Address = %d Prev address = %d Next address = %d\n", temp->data ,temp ,temp->prev ,temp->next);
   }

}

struct node* insertFront(struct node *first, int data){

   if(first==NULL){
      first = createDoubleLinkedList(data);
      return first;
   }
   else{
      struct node *new = (struct node*)malloc(sizeof(struct node));
      new->prev=NULL;
      new->data=data;
      struct node *temp = first;
      temp->prev=new;
      first = new;
      new->next=temp;
      size++;
      return first; 
   }
  
}


struct node* insertAfter(struct node *first, int y ,int data){
   struct node *new = (struct node*)malloc(sizeof(struct node));
   struct node *temp = first;
   new->data=data;
   while(temp->data!=y){
      temp=temp->next;
   }
   new->next=temp->next;
   temp->next->prev=new;
   new->prev=temp;
   temp->next=new;
   
   size++;
   return first;

}
