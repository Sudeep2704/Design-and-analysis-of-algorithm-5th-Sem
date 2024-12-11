#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 100

// Function to find the vertex with the minimum distance
int minDistance(int dist[], int sptSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

// Function to print the shortest path from source to a vertex
void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);

    printf("->%d", j + 1);
}

// Function to print the distance array and paths
void printSolution(int dist[], int parent[], int n, int src) {
    printf("Source Destination Cost Path\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> %d     %d      ", src + 1, i + 1, dist[i]);
        if (dist[i] == INT_MAX)
            printf("No Path\n");
        else if (i == src)
            printf("-\n");
        else {
            printf("%d", src + 1);
            printPath(parent, i);
            printf("\n");
        }
    }
}

// Function that implements Dijkstra's algorithm for a graph represented using an adjacency matrix
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int src) {
    int dist[MAX_VERTICES];   // The output array. dist[i] holds the shortest distance from src to i
    int sptSet[MAX_VERTICES]; // sptSet[i] is 1 if vertex i is included in the shortest path tree
    int parent[MAX_VERTICES]; // Array to store the shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        parent[i] = -1; // Initialize parent for path reconstruction
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++)
            // Update dist[v] if there is a direct edge, v is not in sptSet, and the total weight of the path from src to v through u is smaller than the current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
    }

    // Print the constructed distance array and the paths
    printSolution(dist, parent, n, src);
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int n, src;

    // Reading the adjacency matrix from file
    FILE *file = fopen("inDiAdjMat1.dat", "r");
    if (file == NULL) {
        printf("Error opening the file!\n");
        return -1;
    }

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Reading the graph as an adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }

    fclose(file);

    printf("Enter the source vertex (1-based index): ");
    scanf("%d", &src);
    src--; // Convert to 0-based index

    // Running Dijkstra's algorithm
    dijkstra(graph, n, src);

    return 0;
}
