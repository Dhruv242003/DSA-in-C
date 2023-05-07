#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct ListNode{
    int data;
    struct ListNode *next;
    int weight;
};

struct Edge{
    int s, d, w;
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

void getAdjacencyListInput(struct ListNode *adjList[],int vertex,int edge){
    
    for(int i=0; i<vertex; i++){
        adjList[i] = NULL;
    }

    // printf("Enter the number edges\n");
    int n = edge;
    // scanf("%d",&n);

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

//###################### Kruskals ###############


int find(int parent[], int x){
    if(parent[x]==x) return x;
    return find(parent,parent[x]);
}

void Union(int parent[], int rank[], int x, int y){
    int xroot = find(parent,x);
    int yroot = find(parent,y);

    if(rank[xroot] < rank[yroot]){
        parent[xroot] = yroot;
    }
    else if(rank[xroot] > rank[yroot]){
        parent[yroot]=xroot;
    }
    else{
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void Kruskals(struct ListNode* adjList[], int vertex, int edge){
    struct Edge result[vertex];
    int i =0; 
    int e =0;  // final edge count

    struct Edge edges[edge];

    for(int v=0; v<vertex; v++){
        struct ListNode* temp = adjList[v];

        while(temp!=NULL){
            edges[i].s = v;
            edges[i].d = temp->data;
            edges[i].w = temp->weight;
            temp = temp->next;
            i++;
        }
    }

    // Now edges has every edge in random manner

    // we have to sort this array in asceding order according to the weights
    // ## Bubble sort
    for(int a =0; a<edge-1; a++){
        for(int b =0; b<edge-1-a; b++){
            if(edges[b].w > edges[b+1].w){
                struct Edge temp = edges[b];
                edges[b] = edges[b+1];
                edges[b+1] = temp;
            }
        }
    }

    int parent[vertex];
    int rank[vertex];

    // Initiallly each vertex is its own parent 

    for (int v =0 ; v<vertex; v++){
        parent[v]=v;     // parent[5]=[0,1,2,3,4];   for 5 vertex
        rank[v]=0;
    }

    i = 0;

    // Now we have the sorted edges array

    while(e<vertex-1 && i<edge){   // unitl there are (n-1) edges where n=no. of vertex
        struct Edge next_edge = edges[i++];

        // for this edge we will check its source and destination that it
        // has a parent or not, and what is that parent

        int x = find(parent, next_edge.s);
        int y = find(parent, next_edge.d);

        if(x!=y){
            result[e++] = next_edge;
            Union(parent,rank,x,y);
        }

    }
    printf("Following are the edges in the constructed MST\n");
    int minimumCost = 0;
    for(i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].s, result[i].d, result[i].w);
        minimumCost += result[i].w;
    }

    printf("Minimum cost spanning tree is: %d", minimumCost);

}


// ############# Dijkstras ############

void dijkstra(struct ListNode *adjList[], int vertex, int start){
    int dist[vertex];
    bool visited[vertex];

    for(int i=0;i<vertex;i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[start] = 0;

    for(int i=0;i<vertex-1;i++){
        int u = -1;
        for(int j=0;j<vertex;j++){
            if(!visited[j] && (u == -1 || dist[j] < dist[u])){
                u = j;
            }
        }

        visited[u] = true;

        struct ListNode* temp = adjList[u];
        while(temp != NULL){
            int v = temp->data;
            int weight = temp->weight;
            if(!visited[v] && dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
            }
            temp = temp->next;
        }
    }

    printf("Shortest distances from start vertex %d:\n", start);
    for(int i=0;i<vertex;i++){
        printf("Vertex %d: %d\n", i, dist[i]);
    }
    
}


void printPath(struct ListNode* adjList[], int start, int end) {
    if (start == end) {
        printf("%d ", start);
        return;
    }

    if (adjList[end]->parent == -1) {
        printf("No path exists\n");
        return;
    }

    printPath(adjList, start, adjList[end]->parent);
    printf("%d ", end);
}



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

    int edge;
    printf("Enter the number of edges\n");
    scanf("%d",&edge);
    getAdjacencyListInput(adjList,vertex,edge);

    printAdjList(adjList,vertex);

    printf("BFS: ");

    BFS(0,adjList,vertex);

    bool visited[vertex];
    for(int i=0;i<vertex;i++){
        visited[i] = false;
    }
    printf("\nDFS: ");

    DFS(adjList,vertex,0,visited);

    // Kruskals(adjList, vertex,edge);
    dijkstra(adjList,vertex,0);
    // printf("%d",adjList[0]->data);
    // int start;
    // printf("Enter the start vertex ");
    // scanf("%d",&start);

    // primMST(adjList,vertex,start);
}
