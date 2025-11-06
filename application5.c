#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX 20  // Maximum number of towns
int main() {
    int n; // Number of towns
    printf("Mini Road Map - Minimum Road Construction Cost (Prim's Algorithm)\n");
    printf("Enter number of towns: ");
    scanf("%d", &n);
    int cost[MAX][MAX]; // Adjacency matrix
    printf("Enter the cost adjacency matrix (0 if no direct road exists):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX; // Represent no connection as infinity
        }}
    int selected[MAX] = {0}; // Selected towns in MST
    int edgeCount = 0;
    int minCost = 0;
    selected[0] = 1; // Start with first town
    printf("\nRoads to construct (edges in MST):\n");
    printf("-----------------------------------\n");
    while (edgeCount < n - 1) {
        int min = INT_MAX;
        int a = -1, b = -1;
        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i; b = j;
                    }}}} }
        if (a != -1 && b != -1) {
            printf("Connect Town %d to Town %d → Cost = %d\n", a + 1, b + 1, min);
            minCost += min;
            selected[b] = 1;
            edgeCount++;
        }}
    printf("-----------------------------------\n");
    printf("Total Minimum Cost to connect all towns = %d\n", minCost);
    return 0;
}

