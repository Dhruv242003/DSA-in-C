#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node* createLinkedList(int data);
struct node* InsertLast(struct node *first, int data);
void traverseLinkedList(struct node *first);
struct node* InsertFront(struct node *first, int data);
struct node* InsertAfter(struct node *first, int y , int data);
struct node* deleteLastNode(struct node *first);
struct node* deleteFirstNode(struct node *first);
struct node* deleteSpecificData(struct node *first, int y);
bool isEmpty(struct node *first);


int size;
void main(){
    struct node *first = createLinkedList(5);
    first = InsertFront(first,10);
    first = InsertFront(first,20);
    first = deleteFirstNode(first);
    first = InsertFront(first,40);
    first = InsertFront(first,50);
    first = InsertFront(first,30);
    first = deleteLastNode(first);
    first = InsertFront(first,80);
    first = InsertFront(first,5);
    first = InsertFront(first,90);
    first = deleteSpecificData(first,80);
    traverseLinkedList(first);
}


struct node{
    int data;
    struct node *ptr;    
};

struct node* createLinkedList(int data){
    struct node *first = NULL;
    struct node *new;
    //int size;

    new = (struct node*)malloc(sizeof(struct node));

    new -> data=data;
    new -> ptr=NULL;
    first = new;
    size = 1;
    return first;
}

struct node* InsertLast(struct node *first, int data){
    if(first==NULL){
        createLinkedList(data);
        return first;
    }
    else{
        struct node *new = (struct node*)malloc(sizeof(struct node));
        new->data=data;
        new->ptr=NULL;
        
        struct node *temp;
        temp=first;
        while(temp->ptr!=NULL){
            temp=temp->ptr;
        }
        temp->ptr=new;
    }
    size++;
    return first;
}

struct node* InsertFront(struct node *first, int data){
    if(first==NULL){
        createLinkedList(data);
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


struct node* InsertAfter(struct node *first, int y , int data){

    if(first==NULL){
        createLinkedList(data);
        return first;
    }
    else{
        struct node *new = (struct node*)malloc(sizeof(struct node));
        new->data=data;
        struct node *temp = first;
        while(temp->data != y){
            temp=temp->ptr;
        }
       
        if(temp->ptr==NULL){
            InsertLast(first,data);
            return first;
        }else{
            new->ptr=temp->ptr;
            temp->ptr=new;
        }
        size++;
    }
    return first;
}
void traverseLinkedList(struct node *first){
    struct node *temp = first;
    //prev->ptr=first;
    printf("Size of Linked list = %d\n",size);
    printf("data = %d Address = %d Next address = %d\n",first->data,first,first->ptr);
    while(temp->ptr!=NULL){
        temp=temp->ptr;
        printf("data = %d Address = %d Next address = %d\n",temp->data,temp,temp->ptr);
    }
}

bool isEmpty(struct node *first) {
   return first == NULL;
}

struct node* deleteLastNode(struct node *first){
    struct node *temp=first;
    struct node *prev=first;
    while(temp->ptr!=NULL){
        prev=temp;
        temp=temp->ptr;
    }
    prev->ptr=NULL;
    free(temp);
    size--;
    return first;
}

struct node* deleteFirstNode(struct node *first){
    struct node *temp=first;
    first=first->ptr;
    free(temp);
    size--;
    return first;
}

struct node* deleteSpecificData(struct node *first, int y){
    struct node *temp = first;
    struct node *prev = first;
    while(temp->data!=y){
        
        prev=temp;
        temp=temp->ptr;
        
    }
    if(temp==first){
        first=first->ptr;
    }
    prev->ptr = temp->ptr;
    free(temp);
    size--;
    return first;
}