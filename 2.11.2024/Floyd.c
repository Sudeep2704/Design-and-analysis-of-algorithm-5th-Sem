#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX  // Representation of infinity

void printPath(int next[][100], int u, int v) {
    if (next[u][v] == -1) {
        printf("No path\n");
        return;
    }
    printf("%d", u + 1);
    while (u != v) {
        u = next[u][v];
        printf(" --> %d", u + 1);
    }
    printf("\n");
}

void floydWarshall(int n, int graph[][100]) {
    int dist[100][100], next[100][100];

    // Initialize distance and next matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 0 && i != j)
                dist[i][j] = INF;
            else
                dist[i][j] = graph[i][j];
            
            if (graph[i][j] != INF && i != j)
                next[i][j] = j;
            else
                next[i][j] = -1;
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    // Print the shortest path distance matrix
    printf("Shortest path distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    // User input for specific path query
    int u, v;
    printf("Enter the source and destination vertex: ");
    scanf("%d %d", &u, &v);
    u--; v--; // Converting to 0-based indexing

    printf("Shortest Path from vertex %d to vertex %d: ", u + 1, v + 1);
    printPath(next, u, v);
    if (dist[u][v] != INF) {
        printf("Path weight: %d\n", dist[u][v]);
    } else {
        printf("No path exists.\n");
    }
}

int main() {
    int n;
    FILE *file = fopen("inDiAdjMat2.dat", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[100][100];

    // Reading graph from file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }

    fclose(file);

    floydWarshall(n, graph);

    return 0;
}
