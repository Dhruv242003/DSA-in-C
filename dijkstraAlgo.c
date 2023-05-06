#include <stdio.h>
#include <conio.h>
#define INFINITY 9999
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int startnode, int destination)
{

    int cost[MAX][MAX], distance[MAX], prev[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        distance[i] = cost[startnode][i];
        prev[i] = startnode;
        visited[i] = 0;
    }
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    while (count < n - 1)
    {
        mindistance = INFINITY;
        // nextnode gives the node at minimum distance
        for (i = 0; i < n; i++)
        {
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        }
        // check if a better path exists through nextnode
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    prev[i] = nextnode;
                }
            }
        }
        count++;
    }

    for (i = 0; i < n; i++)
        if (i != startnode)
        {
            printf("\nShortest Distance of node%d = %d ", i, distance[i]);
            printf("\nPath = %d", i);
            j = i;
            do
            {
                j = prev[j];
                printf("<-%d", j);
            } while (j != startnode);
        }
}

int main()
{
    int init[MAX][MAX], n, start, dest;
    printf("Enter no. of vertices: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            init[i][j] = -1;
            if(i==j){
                init[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (init[i][j] == -1 && i!=j)
            {
                int value;
                printf("Enter the distance from node %d to %d: ", i, j);
                scanf("%d", &value);
                init[i][j] = value;
                init[j][i] = value;
            }
        }
    }
    printf("\nEnter the source node: ");
    scanf("%d", &start);
    printf("\nEnter the destination node: ");
    scanf("%d", &dest);
    dijkstra(init, n, start, dest);
    return 0;
}