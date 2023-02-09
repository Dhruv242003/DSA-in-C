#include <stdio.h>
#include<stdlib.h>

int size;
struct node *first;

struct node* createLinkedList(int data);
void traverseLinkedList();
struct node* InsertFront(int data);
struct node* deleteFirstNode();
struct node* createStack(int data);
int pop();
struct node* push(int data);
void traverseStack();


struct node{
    int data;
    struct node *ptr;    
};

void main(){
    first = createStack(5);
    first = push(10);
    first = push(20);
    int x = pop();
    first = push(5);
    first = push(30);
    first = push(40);
    int y = pop();
    first = push(50);
    first = push(60);
    first = push(70);
    traverseStack();
    //printf("%d",y);
}


struct node* createStack(int data){
    struct node *first = createLinkedList(data);
    return first;
}


int pop(){
    struct node *temp=first;
    int popped = temp->data;
    first=first->ptr;
    size--;
    free(temp);
    return popped;
}

struct node* push(int data){
    first = InsertFront(data);
    return first;
}

void traverseStack(){
    traverseLinkedList();
    return;
}



struct node* createLinkedList(int data){
    struct node *first = NULL;
    struct node *new;
    //int size;

    new = (struct node*)malloc(sizeof(struct node));

    new -> data=data;
    new -> ptr=NULL;
    first=new;
    size = 1;
    return first;
}


struct node* InsertFront( int data){
    if(first==NULL){
        first = createLinkedList(data);
        return first;
    }
    else{
        struct node *new=(struct node*)malloc(sizeof(struct node));
        new->data=data;
        struct node *temp=first;
        new->ptr = temp;
        first = new;
        size++;
    }
    return first;
}

void traverseLinkedList(){
    struct node *temp = first;
    //prev->ptr=first;
    printf("Size of Linked list = %d\n",size);
    printf("data = %d Address = %d Next address = %d\n",first->data,first,first->ptr);
    while(temp->ptr!=NULL){
        temp=temp->ptr;
        printf("data = %d Address = %d Next address = %d\n",temp->data,temp,temp->ptr);
    }
}

struct node* deleteFirstNode(){
    struct node *temp=first;
    first=first->ptr;
    free(temp);
    size--;
    return first;
}