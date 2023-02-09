#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>
#include<math.h>

int size;
struct node *first;

struct node* createLinkedList(char data);
void traverseLinkedList();
struct node* InsertFront(char data);
struct node* deleteFirstNode();
struct node* createStack(char data);
char pop();
struct node* push(char data);
void traverseStack();
bool isOperator(char a);


char str[50];


struct node{
    char data;
    struct node *ptr;    
};

void main(){
    printf("Enter postfix expression : ");
    gets(str);

}


void postfixToPrefix(){
    char temp[50]="";
    char operator1,operator2;
    for(int i=0; i<strlen(str);i++){
        if(str[i]!='\0'){
            if(!isOperator(str[i])){
                push(str[i]);
            }
            else if(isOperator(str[i])){
                strcpy(operator1,pop());
                strcpy(operator2, pop());

                strcat(operator1, operator2);
                temp="+";
                strcat(temp,operator1);
            }
        }
    }
    struct node *temp = first;
    while(temp->ptr!=NULL){
        printf("%s",temp->data);
        temp=temp->ptr;
    }
}


bool isOperator(char a){
    if(a=='+'|| a=='*'|| a=='-'|| a=='/'|| a=='('|| a==')') return true;
    else return false;
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