#include <stdio.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int queue[MAX_NODES];
int front = -1, rear = -1;

void enqueue(int node) {
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = node;
}

int dequeue() {
    int node = queue[front];
    front++;
    return node;
}

void bfs(int start_node, int num_nodes) {
    visited[start_node] = 1;
    enqueue(start_node);

    while (front <= rear) {
        int current_node = dequeue();
        printf("%d ", current_node);

        for (int i = 0; i < num_nodes; i++) {
            if (graph[current_node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(i);
            }
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

    printf("Enter the starting node for BFS: ");
    scanf("%d", &start_node);

    printf("BFS Traversal: ");
    bfs(start_node, num_nodes);

    return 0;
}