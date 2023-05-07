#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Edge {
    int src, dest, weight;
};

struct ListNode {
    int data;
    struct ListNode *next;
    int weight;
};

void insertEdge(int a, int b, int weight, struct ListNode *adjList[]) {
    if(adjList[a] == NULL) {
        adjList[a] = (struct ListNode*)malloc(sizeof(struct ListNode));
        adjList[a]->data = b;
        adjList[a]->weight = weight;
        adjList[a]->next = NULL;
    }
    else if(adjList[a] != NULL) {
        struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->data = b;
        temp->weight = weight;
        temp->next = adjList[a];
        adjList[a] = temp;
    }
}

void getAdjacencyListInput(struct ListNode *adjList[], int vertex) {
    for(int i = 0; i < vertex; i++) {
        adjList[i] = NULL;
    }

    printf("Enter the number edges\n");
    int n;
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++) {
        int a, b, w;
        printf("Enter the edge vertices and its weight\n");
        scanf("%d%d%d", &a, &b, &w);

        insertEdge(a, b, w, adjList);
        insertEdge(b, a, w, adjList);
    }
    printf("\nAdjacency List created successfully !!!\n \n");
}

void printAdjList(struct ListNode *adjList[], int vertex) {
    printf("The Adjacency List You Gave ! \n");
    for(int i = 0 ; i < vertex; i++) {
        if(adjList[i] == NULL) {
            printf("%d -> NULL\n", i);
        }
        else {
            struct ListNode* temp = adjList[i];
            printf("%d : --(w:%d)-%d", i, adjList[i]->weight, adjList[i]->data);
            while(temp->next != NULL) {
                temp = temp->next;
                printf("--(w:%d)->%d ", temp->weight, temp->data);
            }
            
            printf("\n");  
        }
    }
}

int find(int parent[], int i) {
    if(parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if(rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if(rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}



void Kruskal(struct ListNode* adjList[], int V) {
    struct Edge result[V];
    int e = 0;
    int i = 0;

    struct Edge* edges = (struct Edge*)malloc(sizeof(struct Edge)*V*V);

    for(int v = 0; v < V; v++) {
        struct ListNode* node = adjList[v];
        while(node != NULL) {
            edges[i].src = v;
            edges[i].dest = node->data;
            edges[i].weight = node->weight;
            node = node->next;
            i++;
        }
    }

    for(int a =0; a<i; a++){
        printf("%d - %d   w: %d\n",edges[a].src, edges[a].dest,edges[a].weight);
    }

    for (int a = 0; a < V*V - 1; a++) {
    for (int b = 0; b < V*V - a - 1; b++) {
        if (edges[b].weight > edges[b+1].weight) {
            struct Edge temp = edges[b];
            edges[b] = edges[b+1];
            edges[b+1] = temp;
        }
    }
}

    

    // qsort(edges, i, sizeof(edges[0]), compare);



    printf("\n\n");
    for(int a =0; a<i; a++){
        printf("%d - %d   w: %d\n",edges[a].src, edges[a].dest,edges[a].weight);
    }


    int parent[V];
    int rank[V];

    for(int v = 0; v < V; v++) {
        parent[v] = v;
        rank[v] = 0;
    }

    i = 0;

    while(e < V-1 && i < V*V) {
        struct Edge next_edge = edges[i++];

        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if(x != y) {
            result[e++] = next_edge;
            Union(parent, rank, x, y);
        }
    }

    printf("Following are the edges in the constructed MST\n");
    int minimumCost = 0;
    for(i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }

    printf("Minimum cost spanning tree is: %d", minimumCost);
}

int main() {
    int V;
    printf("Enter the number of vertices:\n");
    scanf("%d", &V);
    struct ListNode *adjList[V];
    getAdjacencyListInput(adjList, V);

    printAdjList(adjList, V);

    Kruskal(adjList, V);

    return 0;
}