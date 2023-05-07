#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct ListNode{
    int data;
    struct ListNode *next;
    int weight;
};


void insertEdge(int a, int b,int weight, struct ListNode *adjList[]){

    if(adjList[a]==NULL){
        adjList[a] = (struct ListNode*)malloc(sizeof(struct ListNode));
        adjList[a]->data = b;
        adjList[a]->weight = weight;
        adjList[a]->next=NULL;
    }
    else if(adjList[a] != NULL){
        struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->data = b;
        temp->weight = weight;
        temp->next = adjList[a];
        adjList[a]=temp;
    }
}

void getAdjacencyListInput(struct ListNode *adjList[],int vertex){
    
    for(int i=0; i<vertex; i++){
        adjList[i] = NULL;
    }

    printf("Enter the number edges\n");
    int n;
    scanf("%d",&n);

    for(int i=0 ; i<n ; i++){
        int a,b,w;
        printf("Enter the edge vertices and its weight\n");
        scanf("%d%d%d",&a,&b,&w);

        insertEdge(a,b,w,adjList);
        insertEdge(b,a,w,adjList);
    }
    printf("\nAdjacency List created successfully !!!\n \n");
}


void printAdjList(struct ListNode *adjList[],int vertex){
    printf("The Adjacency List You Gave ! \n");
    for(int i =0 ; i<vertex; i++){
        if(adjList[i]==NULL){
            printf("%d -> NULL\n",i);
        }
        else{
            struct ListNode* temp = adjList[i];
            printf("%d : --(w:%d)-%d",i,adjList[i]->weight,adjList[i]->data);
            while(temp->next!=NULL){
                temp = temp->next;
                printf("--(w:%d)->%d ",temp->weight,temp->data);
            }
            
            printf("\n");  
        }
    }
}

void BFS(int start, struct ListNode *adjList[], int vertex) {
    bool visited[vertex];
    for(int i = 0; i < vertex; i++) {
        visited[i] = false;
    }

    int queue[vertex];
    int front = 0;
    int rear = 0;
    queue[rear] = start;
    visited[start] = true;

    while(front <= rear) {   // queue is not empty 
        int currentVertex = queue[front++];   //deQueue
        printf("%d ", currentVertex);

        struct ListNode* temp = adjList[currentVertex];   

        while(temp != NULL) {
            int adjVertex = temp->data;

            if(!visited[adjVertex]) {
                queue[++rear] = adjVertex;
                visited[adjVertex] = true;
            }

            temp = temp->next;
        }
    }
}

void DFS(struct ListNode* adjList[], int vertex, int start, bool visited[]){
    visited[start] = true;
    printf("%d ", start);
    struct ListNode* ptr = adjList[start];
    while (ptr != NULL) {
        int v = ptr->data;
        if (!visited[v]) {
            DFS(adjList, vertex, v, visited);
        }
        ptr = ptr->next;
    }
}

// Prims 

void primMST(struct ListNode *adjList[], int vertex, int start){
    int parent[vertex]; 
    int key[vertex]; 
    bool mstSet[vertex]; 

    int totalWeight = 0; 

    for(int i = 0; i < vertex; i++){
        key[i] = INT_MAX;
        mstSet[i] = false;
    }


    key[0] = start; 
    parent[0] = -1; 

    for(int i = 0; i < vertex-1; i++){
        int u, minKey = INT_MAX;

        for(int j = 0; j < vertex; j++){
            if(!mstSet[j] && key[j] < minKey){
                minKey = key[j];
                u = j;
            }
        }

        mstSet[u] = true; 

        struct ListNode* temp = adjList[u];
        while(temp != NULL){
            int v = temp->data;
            int weight = temp->weight;
            if(!mstSet[v] && weight < key[v]){
                parent[v] = u;
                key[v] = weight;
            }
            temp = temp->next;
        }
        totalWeight += key[u]; 
    }

    printf("Minimum Cost Spanning Tree:\n");
    for(int i = 1; i < vertex; i++){
        printf("%d - %d\n", parent[i], i);
    }
    printf("Total cost of MST: %d\n", totalWeight); 
}



void main(){
    int vertex;
    printf("Enter number of vertex\n");
    scanf("%d",&vertex);
    struct ListNode *adjList[vertex];

    getAdjacencyListInput(adjList,vertex);

    printAdjList(adjList,vertex);

    printf("BFS: ");

    BFS(0,adjList,vertex);

    bool visited[vertex];
    for(int i=0;i<vertex;i++){
        visited[i] = false;
    }
    printf("\nDFS: ");

    DFS(adjList,vertex,0,visited);
    // printf("%d",adjList[0]->data);
    // int start;
    // printf("Enter the start vertex ");
    // scanf("%d",&start);

    // primMST(adjList,vertex,start);
}
