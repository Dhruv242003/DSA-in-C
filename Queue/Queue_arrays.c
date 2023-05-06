#include <stdio.h>
#include <stdlib.h>

struct Queue* createQueue();
void enQueue(struct Queue *tempQueue,int data);
int deQueue(struct Queue *tempQueue);

struct Queue
{
    int top,end;
    int arr[50];
};

void main(){


    struct Queue *newQueue;
    newQueue = createQueue();


    printf("Enter number of elements you want to enter\n");
    int n;
    scanf("%d",&n);
    printf("Enter elements\n");
    for(int i =0; i<n; i++){
        int temp=0;
        scanf("%d",&temp);
        enQueue(newQueue,temp);
    }

    printf("Queue is :\n");
    while(newQueue->top!=newQueue->end+1){
        printf("%d ",deQueue(priorityQueue));
    }   
}
struct Queue * createQueue(){

    struct Queue *tempQueue;
    tempQueue = (struct Queue*)malloc(sizeof(struct Queue));
    tempQueue->top = -1;
    tempQueue->end = -1;

    return tempQueue;
    
}
void enQueue(struct Queue *tempQueue,int data){
    if(tempQueue->top==-1){
        tempQueue->top++;
    }
    tempQueue->end++;
    tempQueue->arr[tempQueue->end]=data;

}
int deQueue(struct Queue *tempQueue){
    if(tempQueue->end==-1) {
        printf("Queue is empty");
        return 0;
    }
    int temp = tempQueue->arr[tempQueue->top];
    tempQueue->top++;
    return temp;
}