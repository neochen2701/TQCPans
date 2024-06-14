#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 60

int graph[MAX_VERTICES][MAX_VERTICES];
int num_vertices = 0;

void readGraphFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("File could not be opened.\n");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    int row = 0;
    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, ",");
        int col = 0;
        while (token != NULL) {
            graph[row][col++] = atoi(token);
            token = strtok(NULL, ",");
        }
        if (row == 0) num_vertices = col;
        row++;
    }
    fclose(file);
}

int main() {
    readGraphFromFile("read.txt");

    int degrees[num_vertices];
    memset(degrees, 0, sizeof(degrees));
    int max_weight = 0, min_weight = 1000000;

    for (int i = 0; i < num_vertices; i++) {
        int weight_sum = 0;
        for (int j = 0; j < num_vertices; j++) {
            if (graph[i][j] > 0) {
                degrees[i]++;
                weight_sum += graph[i][j];
            }
        }
        if (weight_sum > max_weight) max_weight = weight_sum;
        if (weight_sum < min_weight) min_weight = weight_sum;
    }

    printf("Degree:");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d", degrees[i]);
        if (i < num_vertices - 1) printf(",");
    }
    printf("\n%d\n", max_weight - min_weight);

    return 0;
}
