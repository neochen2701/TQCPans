#include <stdio.h>
#include <string.h>

#define MAX_N 101

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main(void) {
    int n, v, threshold;
    scanf("%d %d %d", &n, &v, &threshold);

    int adjacencyList[MAX_N][MAX_N];
    int visited[MAX_N]; 
    memset(visited, 0, sizeof(visited));

    memset(adjacencyList, -1, sizeof(adjacencyList));

    for (int i = 0; i < n - 1; i++) {
        int v0, v1, w;
        scanf("%d %d %d", &v0, &v1, &w);
        adjacencyList[v0][v1] = w;
        adjacencyList[v1][v0] = w;
    }

    int queue[MAX_N], weightQueue[MAX_N], front = 0, rear = 0;
    queue[rear] = v;
    weightQueue[rear++] = 2147483647;
    visited[v] = 1;

    int ans = 0;

    while (front < rear) {
        int current = queue[front];
        int currentWeight = weightQueue[front++];
        
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && adjacencyList[current][i] != -1) {
                int pathWeight = min(currentWeight, adjacencyList[current][i]);
                if (pathWeight >= threshold) {
                    ans++;
                    queue[rear] = i;
                    weightQueue[rear++] = pathWeight;
                    visited[i] = 1;
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
