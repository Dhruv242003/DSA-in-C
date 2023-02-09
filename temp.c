#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

int size;
struct node *first;

void infixToPostfix(char str[]);
bool isOperator(char a);
int priorityOf(char a);


struct node* createLinkedList(char data);
void traverseLinkedList();
struct node* InsertFront(char data);
struct node* deleteFirstNode();
struct node* createStack(char data);
char pop();
struct node* push(char data);
void traverseStack();


struct node{
    char data;
    struct node *ptr;    
};




void main(){
    first = createStack('a');
    first = push('b');
    first = push('c');
    char x = pop();
    traverseStack();

}

void infixToPostfix(char str[]){
    int i=0;
    while(str[i] != '\0'){
        if(isOperator(str[i])){
            if(first!=NULL){
                if(priorityOf(str[i]) < priorityOf(first->data)){
                    int x=pop();
                    printf("%d",x);
                }
                else{
                    push(str[i]);
                }
            }
        }
        else{
                printf("%c",str[i]);
            }
        i++;
    }   
}

bool isOperator(char a){
    if(a=='+'|| a=='*'|| a=='-'|| a=='/'|| a=='('|| a==')') return true;
    else return false;
}

int priorityOf(char a){
    if(a=='(') return 6;
    else if(a=='/') return 5;
    else if(a=='*') return 4;
    else if(a=='+') return 3;
    else if(a=='-') return 2;
    
}

struct node* createStack(char data){
    struct node *first = createLinkedList(data);
    return first;
}


char pop(){
    struct node *temp=first;
    char popped = temp->data;
    first=first->ptr;
    size--;
    free(temp);
    return popped;
}

struct node* push(char data){
    first = InsertFront(data);
    return first;
}

void traverseStack(){
    traverseLinkedList();
    return;
}



struct node* createLinkedList(char data){
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


struct node* InsertFront( char data){
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
    printf("data = %c Address = %d Next address = %d\n",first->data,first,first->ptr);
    while(temp->ptr!=NULL){
        temp=temp->ptr;
        printf("data = %c Address = %d Next address = %d\n",temp->data,temp,temp->ptr);
    }
}

struct node* deleteFirstNode(){
    struct node *temp=first;
    first=first->ptr;
    free(temp);
    size--;
    return first;
}