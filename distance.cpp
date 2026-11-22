#include <stdio.h>
#include <limits.h>

#define V 6
#define INF 99999

// Function to find vertex with minimum distance
int minDistance(int dist[], int visited[]) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Dijkstra Algorithm
void dijkstra(int graph[V][V], int src, int dest) {
    int dist[V];
    int visited[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print result
    printf("\nShortest distance = %d km\n", dist[dest]);
    printf("Path: ");

    int path[V];
    int k = 0;
    for (int v = dest; v != -1; v = parent[v]) {
        path[k++] = v;
    }

    for (int i = k - 1; i >= 0; i--) {
        printf("%d ", path[i] + 1);
    }
    printf("\n");
}

int main() {
    // Cities:
    // 1 Addis Ababa
    // 2 Adama
    // 3 Bahir Dar
    // 4 Hawassa
    // 5 Mekelle
    // 6 Dire Dawa

    int graph[V][V] = {
        {0, 100, 565, 275, 0, 515},
        {100, 0, 0, 160, 0, 445},
        {565, 0, 0, 0, 385, 0},
        {275, 160, 0, 0, 0, 0},
        {0, 0, 385, 0, 0, 0},
        {515, 445, 0, 0, 0, 0}
    };

    int source, destination;

    printf("Cities:\n");
    printf("1 Addis Ababa\n2 Adama\n3 Bahir Dar\n4 Hawassa\n5 Mekelle\n6 Dire Dawa\n");

    printf("\nEnter source city number: ");
    scanf("%d", &source);

    printf("Enter destination city number: ");
    scanf("%d", &destination);

    dijkstra(graph, source - 1, destination - 1);

    return 0;
}