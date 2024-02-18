#include <stdio.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];

void dfs(int node, int num_nodes) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            dfs(i, num_nodes);
        }
    }
}

int main() {
    int num_nodes, num_edges;
    int start_node;

    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &num_nodes, &num_edges);

    printf("Enter the edges (node1 node2): \n");
    for (int i = 0; i < num_edges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        graph[node1][node2] = 1;
        graph[node2][node1] = 1; // For undirected graph
    }

    printf("Enter the starting node for DFS: ");
    scanf("%d", &start_node);

    printf("DFS Traversal: ");
    dfs(start_node, num_nodes);

    return 0;
}