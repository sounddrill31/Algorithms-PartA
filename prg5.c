#include <stdio.h>
#define MAX 100
int adj[MAX][MAX], visited[MAX], n;
void dfs(int v) {
	printf("%d ", v);
	visited[v] = 1;
	for (int i = 0; i < n; i++) {
		if (adj[v][i] && !visited[i])
			dfs(i);
	}
}
void bfs(int start) {
	int queue[MAX], front = 0, rear = 0;
	for (int i = 0; i < n; i++) visited[i] = 0;
	queue[rear++] = start;
	visited[start] = 1;
	while (front < rear) {
		int v = queue[front++];
		printf("%d ", v);
		for (int i = 0; i < n; i++) {
			if (adj[v][i] && !visited[i]) {
				queue[rear++] = i;
				visited[i] = 1;
			}
		}
	}
}
int main() {
	int edges, u, v, start;
	printf("Enter number of vertices: ");
	scanf("%d", &n);
	printf("Enter number of edges: ");
	scanf("%d", &edges);
// Initialize adjacency matrix
	for (int i = 0; i < edges; i++) {
		printf("Enter edge (u v): ");
		scanf("%d %d", &u, &v);
		adj[u][v] = 1;
	}
	adj[v][u] = 1; // For undirected graph
	printf("Enter starting vertex: ");
	scanf("%d", &start);
	printf("DFS traversal: ");
	for (int i = 0; i < n; i++) visited[i] = 0;
	dfs(start);
	printf("\nBFS traversal: ");
	bfs(start);
	return 0;
}