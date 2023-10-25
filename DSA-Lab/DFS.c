#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int stack[MAX_VERTICES];
int top = -1;
int vertices;

void push(int vertex) {
    stack[++top] = vertex;
}

int pop() {
    return stack[top--];
}

bool isStackEmpty() {
    return top == -1;
}

void init() {
    top = -1;
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
    }
}

void depthFirstSearch(int start) {
    push(start);
    visited[start] = true;

    while (!isStackEmpty()) {
        int current = pop();
        printf("%d ", current);
int i;
        for (i = 0; i < vertices; i++) {
            if (graph[current][i] && !visited[i]) {
                push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix:\n");
    int i;
	for ( i = 0; i < vertices; i++) {
        int j;
		for ( j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int start;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("DFS starting from vertex %d: ", start);
    init();
    depthFirstSearch(start);

    return 0;
}

