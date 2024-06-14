#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct vertex_s{
    int id;
    int count;
    int neighbor[MAX_VERTICES];
}Vertex;
typedef struct graph_s {
    Vertex vertices[MAX_VERTICES];
    int count;
} Graph;

void initGraph(Graph *g) {
    g->count = 0;
    for (int i=0; i<MAX_VERTICES; i++) {
        g->vertices[i].id=-1;
        g->vertices[i].count=0;
    }
}
void printGraph(Graph g) {
    for (int i=0; i<g.count; i++) {
        printf("%d: ", g.vertices[i].id);
        for (int j=0; j<g.vertices[i].count; j++) {
            printf("%d ", g.vertices[i].neighbor[j]);
        }
        printf("\n");
    }
    printf("\n%d\n", g.count);
}
int getIndex(Graph g, int id) {
    for (int i=0; i<g.count; i++) {
        if (g.vertices[i].id ==id) return i;
    }
    return -1;
}
void addNeighbor(Vertex *v, int idx, int idy) {
    v->id = idx;
    v->neighbor[v->count++]=idy;
}
void addEdge(Graph *g, int u, int v) {
    int u_index = getIndex(*g, u);
    int v_index = getIndex(*g, v);
    if (u_index==-1) addNeighbor(&g->vertices[g->count++], u, v);
    else             addNeighbor(&g->vertices[u_index], u, v);
    if (v_index==-1) addNeighbor(&g->vertices[g->count++], v, u);
    else             addNeighbor(&g->vertices[v_index], v, u);
}
int contains(int *path, int pathLength, int node) {
    for (int i = 0; i < pathLength; i++) {
        if (path[i] == node) {
            return 1;
        }
    }
    return 0;
}

void findAllPaths(Graph *g, int start, int end, int *path, int pathLength, int *allPaths[], int *allPathsCount) {
    int i=0;
    path[pathLength++] = start;
    if (start == end) {
        int *newPath = malloc((pathLength+1) * sizeof(int));
        for (i = 0; i < pathLength; i++) {
            newPath[i] = path[i];
        }
        newPath[i] = -1;
        allPaths[(*allPathsCount)++] = newPath;
        return;
    }
    int start_index = getIndex(*g, start);
    for (int i = 0; i < g->vertices[start_index].count; i++) {
        int node = g->vertices[start_index].neighbor[i];
        if (!contains(path, pathLength, node)) {
            findAllPaths(g, node, end, path, pathLength, allPaths, allPathsCount);
        }
     }
}
void getMaxPath(int *allPaths[], int allPathsCount, int **p_maxPath, int *maxLength) {
    int maxPoint = 0;
    *maxLength = 0;
    *p_maxPath = NULL;
    for (int i = 0; i < allPathsCount; i++) {
        int length = 0;
        int sum = 0;
        while (allPaths[i][length] != -1) {
            sum += allPaths[i][length];
            length++;
        }
        if (*maxLength < length || (*maxLength == length && maxPoint <= sum)) {
            *maxLength = length;
            maxPoint = sum;
            *p_maxPath = allPaths[i];
        }
    }
}
int main() {
    int n, m;
    int start_n, end_n;
    int path[MAX_VERTICES];
    int *allPaths[MAX_VERTICES];
    int allPathsCount = 0;
    int *maxPath;
    int maxLength;
    Graph my_graph;
    initGraph(&my_graph);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x1, x2;
        scanf("%d %d", &x1, &x2);
        addEdge(&my_graph, x1, x2);
    }
    scanf("%d %d", &start_n, &end_n);
    findAllPaths(&my_graph, start_n, end_n, path, 0, allPaths, &allPathsCount);
    getMaxPath(allPaths, allPathsCount, &maxPath, &maxLength);
    for (int i = 0; i < maxLength; i++) {
        if (i < maxLength - 1) {
            printf("%d ", maxPath[i]);
        } else {
            printf("%d", maxPath[i]);
        }
    }
    printf("\n");
    return 0;
}
