#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

void readGraph(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int *numVertices, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }
    fscanf(file, "%d", numVertices); // First line contains number of vertices
    for (int i = 0; i < *numVertices; i++) {
        for (int j = 0; j < *numVertices; j++) {
            fscanf(file, "%d", &adjMatrix[i][j]);
        }
    }
    fclose(file);
}

int minKey(int key[], int mstSet[], int numVertices) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < numVertices; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices, int startVertex) {
    int parent[MAX_VERTICES];     // Stores the MST
    int key[MAX_VERTICES];        // Key values used to pick minimum weight edge
    int mstSet[MAX_VERTICES];     // Vertices included in MST
    int totalCost = 0;

    // Initialize keys as infinite and mstSet[] as false
    for (int i = 0; i < numVertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Starting vertex has key 0, so it is picked first
    key[startVertex] = 0;
    parent[startVertex] = -1; // Root of MST

    // MST construction
    for (int count = 0; count < numVertices - 1; count++) {
        int u = minKey(key, mstSet, numVertices);  // Pick min key vertex not yet included in MST
        mstSet[u] = 1;  // Add u to MST set

        // Update key and parent index of adjacent vertices of the picked vertex
        for (int v = 0; v < numVertices; v++) {
            if (adjMatrix[u][v] && mstSet[v] == 0 && adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adjMatrix[u][v];
            }
        }
    }

    // Print the cost adjacency matrix of MST and total cost
    int mstMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
    printf("Cost Adjacency Matrix of the Minimum Spanning Tree:\n");
    for (int i = 1; i < numVertices; i++) {
        mstMatrix[parent[i]][i] = adjMatrix[parent[i]][i];
        mstMatrix[i][parent[i]] = adjMatrix[i][parent[i]];
        totalCost += adjMatrix[i][parent[i]];
    }

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", mstMatrix[i][j]);
        }
        printf("\n");
    }

    printf("Total Weight of the Spanning Tree: %d\n", totalCost);
}

int main() {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    int startVertex;

    // Read graph from file
    readGraph(adjMatrix, &numVertices, "inUnAdjMat.dat");

    printf("Enter the Starting Vertex: ");
    scanf("%d", &startVertex);

    // Convert 1-based index to 0-based for internal use
    primMST(adjMatrix, numVertices, startVertex - 1);

    return 0;
}
