#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX_EDGES];
Edge mst[MAX_EDGES];
int parent[MAX_EDGES];
int rank[MAX_EDGES];
int n, m;

// Comparator for sorting edges by weight
int compare(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->w - edgeB->w;
}

// Find the root of the set of a node using path compression
int find(int node) {
    if (parent[node] != node) {
        parent[node] = find(parent[node]);
    }
    return parent[node];
}

// Union of two sets by rank
void unionSet(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);

    if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
    } else if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
    } else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

void kruskalMST() {
    qsort(edges, m, sizeof(Edge), compare); // Sort edges by weight

    // Initialize Union-Find
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int totalWeight = 0;
    int mstEdges = 0;

    printf("Edge Cost\n");
    for (int i = 0; i < m && mstEdges < n - 1; i++) {
        Edge currentEdge = edges[i];
        int uRoot = find(currentEdge.u);
        int vRoot = find(currentEdge.v);

        // If including this edge doesn't form a cycle, add it to the MST
        if (uRoot != vRoot) {
            unionSet(uRoot, vRoot);
            mst[mstEdges++] = currentEdge;
            totalWeight += currentEdge.w;
            printf("%d--%d %d\n", currentEdge.u, currentEdge.v, currentEdge.w);
        }
    }

    printf("Total Weight of the Spanning Tree: %d\n", totalWeight);
}

int main() {
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter the edges (u, v, w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskalMST();

    return 0;
}
