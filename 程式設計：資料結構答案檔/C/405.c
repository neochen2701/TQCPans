#include <stdio.h>
#include <limits.h>
#include <float.h>

#define MAX_M 31
#define INF DBL_MAX

double adjMatrix[MAX_M][MAX_M];
double distance[MAX_M];
int visited[MAX_M];

int main() {
    int m, n, s, t;
    scanf("%d %d", &m, &n);
    scanf("%d %d", &s, &t);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            adjMatrix[i][j] = INF;
        }
    }

    for (int i = 0; i < n; i++) {
        int v1, v2;
        double w;
        scanf("%d %d %lf", &v1, &v2, &w);
        adjMatrix[v1][v2] = w;
        adjMatrix[v2][v1] = w;
    }

    for (int i = 1; i <= m; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }

    distance[s] = 0;

    for (int i = 1; i <= m; i++) {
        double minDistance = INF;
        int minIndex = -1;

        for (int j = 1; j <= m; j++) {
            if (!visited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                minIndex = j;
            }
        }

        if (minIndex == -1) break;

        visited[minIndex] = 1;

        for (int j = 1; j <= m; j++) {
            if (!visited[j] && adjMatrix[minIndex][j] != INF &&
                distance[minIndex] + adjMatrix[minIndex][j] < distance[j]) {
                distance[j] = distance[minIndex] + adjMatrix[minIndex][j];
            }
        }
    }

    printf("%.1f\n", distance[t]);
    return 0;
}
