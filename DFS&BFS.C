#include <stdio.h>
#define MAX 10

int adj[MAX][MAX], visited[MAX], n;


void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}


void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;

    int visited_bfs[MAX] = {0};

    queue[rear++] = start;
    visited_bfs[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited_bfs[i] == 0) {
                queue[rear++] = i;
                visited_bfs[i] = 1;
            }
        }
    }
}

int main() {
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

   
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(start);

 
    printf("\nBFS Traversal: ");
    BFS(start);

    return 0;
}
