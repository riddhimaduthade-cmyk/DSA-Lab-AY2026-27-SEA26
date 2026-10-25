// Name: Riddhima Duthade
// Roll no: SEA26
// Graph Traversal

#include <stdio.h>

int buildings, paths;
int adj[20][20] = {0};
int visited[20];

// BFS Function
void BFS(int start)
{
    int queue[20], front = 0, rear = 0;
    int i, v;

    for(i = 0; i < buildings; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("\nBFS Traversal: ");

    while(front < rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for(i = 0; i < buildings; i++)
        {
            if(adj[v][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

// DFS Function
void DFS(int start)
{
    int i;

    visited[start] = 1;
    printf("%d ", start);

    for(i = 0; i < buildings; i++)
    {
        if(adj[start][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

int main()
{
    int i, j, u, v, start;

    printf("Enter number of buildings: ");
    scanf("%d", &buildings);

    if(buildings < 1 || buildings > 20)
    {
        printf("Invalid number of buildings!");
        return 0;
    }

    printf("Enter number of paths: ");
    scanf("%d", &paths);

    if(paths < 0 || paths > buildings * (buildings - 1) / 2)
    {
        printf("Invalid number of paths!");
        return 0;
    }

    // Input paths between buildings
    for(i = 0; i < paths; i++)
    {
        printf("Enter path (source destination): ");
        scanf("%d %d", &u, &v);

        if(u < 0 || u >= buildings ||
           v < 0 || v >= buildings || u == v)
        {
            printf("Invalid path!");
            return 0;
        }

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Display adjacency matrix
    printf("\nAdjacency Matrix:\n");

    for(i = 0; i < buildings; i++)
    {
        for(j = 0; j < buildings; j++)
            printf("%d ", adj[i][j]);

        printf("\n");
    }

    printf("Enter starting building (0 to %d): ",
           buildings - 1);
    scanf("%d", &start);

    if(start < 0 || start >= buildings)
    {
        printf("Invalid starting building!");
        return 0;
    }

    BFS(start);

    for(i = 0; i < buildings; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    DFS(start);

    printf("\n");
    return 0;
}