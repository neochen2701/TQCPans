#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int adj_array_of_graph[m+1][m+1];
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= m; j++)
            adj_array_of_graph[i][j] = 0;

    for(int i = 0; i < n; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        adj_array_of_graph[v1][v2] = 1;
        adj_array_of_graph[v2][v1] = 1;
    }

    int degree_of_vertex[m+1];
    for(int i = 0; i <= m; i++)
        degree_of_vertex[i] = 0;

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++)
            if(adj_array_of_graph[i][j] == 1)
                degree_of_vertex[i]++;

    int num_of_odd_degree_vertex = 0;
    for(int i = 1; i <= m; i++)
        if(degree_of_vertex[i] % 2 == 1)
            num_of_odd_degree_vertex++;

    if(num_of_odd_degree_vertex == 0 || num_of_odd_degree_vertex == 2)
        printf("YES\n");
    else
        printf("NO\n");

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j < m; j++)
            printf("%d ", adj_array_of_graph[i][j]);
        printf("%d\n", adj_array_of_graph[i][m]);
    }

    return 0;
}
