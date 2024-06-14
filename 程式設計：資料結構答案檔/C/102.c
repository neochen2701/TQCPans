#include <stdio.h>

int main() {
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);

    int matrix[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Original:\n");
    for (int i = 0; i < m; i++) {
        printf("[");
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
            if (j < n - 1) printf(" ");
        }
        printf("]\n");
    }

    printf("Transpose:\n");
    for (int i = 0; i < n; i++) {
        printf("[");
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[j][i]);
            if (j < m - 1) printf(" ");
        }
        printf("]\n");
    }

    return 0;
}