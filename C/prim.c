#include <stdio.h>
#define INF 9999  // Represents infinity
#define MAX 10    // Maximum number of vertices

void prim(int cost[MAX][MAX], int n) {
    int near[MAX], t[MAX][2];
    int i, j, k, l, mincost = 0, min;

    // Step 1: Find the smallest edge in the graph
    min = INF;
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
                k = i;
                l = j;
            }
        }
    }

    t[1][0] = k;
    t[1][1] = l;
    mincost = cost[k][l];

    // Step 2: Initialize near[]
    for (i = 1; i <= n; i++) {
        if (cost[i][l] < cost[i][k])
            near[i] = l;
        else
            near[i] = k;
    }
    near[k] = near[l] = 0; // Mark included vertices

    // Step 3: Repeat to find n-2 more edges
    for (i = 2; i <= n - 1; i++) {
        min = INF;
        int jmin = 0;

        // Find vertex j with smallest cost[j][near[j]]
        for (j = 1; j <= n; j++) {
            if (near[j] != 0 && cost[j][near[j]] < min) {
                min = cost[j][near[j]];
                jmin = j;
            }
        }

        // Add this edge to the tree
        t[i][0] = jmin;
        t[i][1] = near[jmin];
        mincost += cost[jmin][near[jmin]];
        near[jmin] = 0;

        // Update near[] array
        for (k = 1; k <= n; k++) {
            if (near[k] != 0 && cost[k][near[k]] > cost[k][jmin])
                near[k] = jmin;
        }
    }

    // Step 4: Display MST
    printf("\nEdges in the Minimum Spanning Tree:\n");
    for (i = 1; i <= n - 1; i++) {
        printf("(%d, %d)\n", t[i][0], t[i][1]);
    }

    printf("Minimum Cost = %d\n", mincost);
}

int main() {
    int cost[MAX][MAX];
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use %d for infinity):\n", INF);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    prim(cost, n);
    return 0;
}
