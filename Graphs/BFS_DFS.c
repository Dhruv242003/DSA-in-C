#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size, front, rear, *arr;
};

int adj_matrix[100][100];
int visited[100];

int isEmpty(struct queue *q)
{
    if (q->rear = q->front)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = val;
        // printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct queue *q)
{
    int n = -1;
    if (isEmpty(q))
    {
        printf("Underfloww");
    }
    else
    {
        q->front++;
        n = q->arr[q->front];
    }
    return n;
}

void init_graph(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }
}

void print_graph(int n)
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

void add_edge(int u, int v)
{

    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1; // For an undirected graph, add an edge in both directions
}

void DFS(int i){
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if(adj_matrix[i][j]==1 && !visited[j]){
            DFS(j);
        }
    }
}

void bfs(struct queue *q,int start_node)
{
    
    q->arr = (int *)malloc(q->size * sizeof(int));
    printf("%d", start_node);
    visited[start_node] = start_node;
    enqueue(&q, start_node); // Enqueue i for exploration
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (adj_matrix[node][j] == 1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    struct queue q;
    q.size = 400;
    q.front = q.rear = 0;
    int n, e, u, v, start_node;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);

    init_graph(n);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &e);

    printf("Enter the edges of the graph: \n");
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    print_graph(n);

    printf("Enter the starting node for BFS and DFS traversals: ");
    scanf("%d", &start_node);
    bfs(&q,start_node);
    DFS(start_node);
    return 0;
}