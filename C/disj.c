#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int parent[MAX];

// Create disjoint sets (initially each element is its own parent)
void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    printf("Disjoint sets created.\n");
}

// Find the representative (root) of the set containing element x
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
}

// Union of two sets containing x and y
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        parent[rootY] = rootX; // Union
        printf("Union done: %d and %d are now in the same set.\n", x, y);
    } else {
        printf("%d and %d are already in the same set.\n", x, y);
    }
}

// Display all sets
void displaySets(int n) {
    printf("\nElement : Set Representative\n");
    for (int i = 0; i < n; i++) {
        printf("%d : %d\n", i, find(i));
    }
}

int main() {
    int n, choice, x, y;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    makeSet(n);

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Union\n");
        printf("2. Find\n");
        printf("3. Display Sets\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two elements to union: ");
                scanf("%d %d", &x, &y);
                if (x >= 0 && x < n && y >= 0 && y < n) {
                    unionSets(x, y);
                } else {
                    printf("Invalid elements!\n");
                }
                break;

            case 2:
                printf("Enter element to find set: ");
                scanf("%d", &x);
                if (x >= 0 && x < n) {
                    printf("Representative of element %d is %d\n", x, find(x));
                } else {
                    printf("Invalid element!\n");
                }
                break;

            case 3:
                displaySets(n);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
