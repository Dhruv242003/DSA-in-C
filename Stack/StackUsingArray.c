#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct stack{
    int top;
    int st[30];
    int length;
}; 

struct stack push(struct stack s,int x);
struct stack pop(struct stack s);
bool isFull(struct stack s);
bool isEmpty(struct stack s);
void traverseStack(struct stack s);



void main(){
    struct stack s;
    s.top = -1;
    s.length = 0;

    s=push(s,10);
    s=push(s,20);
    s=pop(s);
    s=push(s,5);
    s=push(s,30);
    s=push(s,40);
    s=pop(s);
    s=push(s,50);
    s=push(s,60);
    s=push(s,70);
    traverseStack(s);
}



struct stack push(struct stack s,int x){
    if(s.top>=30){
        printf("Stack is full");
        return s;
    }
    s.top++;
    s.st[s.top] = x;
    s.length++;
    return s;
}

struct stack pop(struct stack s){
    if(s.top==-1){
        printf("Stack is empty");
        return s;
    }
    int x = s.st[s.top];
    s.top--;
    s.length--;
    return s;
}


bool isFull(struct stack s){
    if(s.top>=30) return true;
    else return false;
}

bool isEmpty(struct stack s){
    if(s.top==-1) return true;
    else return false;
}

void traverseStack(struct stack s){
    for(int i =s.length-1 ; i>=0; i--){
        printf("%d ",s.st[i]);
    }
    return;
}