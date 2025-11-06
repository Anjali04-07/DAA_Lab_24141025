#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX 20 // Maximum number of locations
int minDistance(int dist[], bool visited[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < n; v++)
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}
void dijkstra(int graph[MAX][MAX], int src, int n) {
    int dist[MAX];     // Shortest distance from source
    bool visited[MAX]; // Visited vertices
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = true;
        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printf("\nShortest distances from location %d:\n", src + 1);
    printf("-----------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("To location %d = %d\n", i + 1, dist[i]);
}
int main() {
    int n;
    printf("Urban Planning - Shortest Path from Central Location\n");
    printf("Enter number of locations: ");
    scanf("%d", &n);
    int graph[MAX][MAX];
    printf("Enter adjacency matrix (0 if no direct road exists):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    int source;
    printf("Enter the source location (1 to %d): ", n);
    scanf("%d", &source);
    dijkstra(graph, source - 1, n);
    return 0;
}
