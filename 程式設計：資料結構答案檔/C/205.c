#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int area;
    int top;
    int left;
    int bottom;
    int right;
} Rectangle;

Rectangle largestRectangleArea(int *heights, int n, int row) {
    int *left = (int*)malloc(n * sizeof(int));
    int *right = (int*)malloc(n * sizeof(int));
    int *stk = (int*)malloc(n * sizeof(int)); // Stack to simulate std::stack
    int stkTop = -1; // Represents the top of the stack
    Rectangle maxRect = {0, row, 0, row, 0};

    for (int i = 0; i < n; ++i) {
        right[i] = n;
    }

    for (int i = 0; i < n; ++i) {
        while (stkTop != -1 && heights[stk[stkTop]] >= heights[i]) {
            right[stk[stkTop]] = i;
            stkTop--;
        }
        left[i] = (stkTop == -1) ? 0 : stk[stkTop] + 1;
        stk[++stkTop] = i;
    }

    for (int i = 0; i < n; ++i) {
        int area = heights[i] * (right[i] - left[i]);
        if (area > maxRect.area) {
            maxRect.area = area;
            maxRect.top = row - heights[i] + 1;
            maxRect.left = left[i];
            maxRect.bottom = row;
            maxRect.right = right[i] - 1;
        }
    }

    free(left);
    free(right);
    free(stk);

    return maxRect;
}

Rectangle findLargestRectangleArea(int **matrix, int n, int m) {
    int *heights = (int*)calloc(m, sizeof(int));
    Rectangle maxRect = {0, 0, 0, 0, 0};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            heights[j] = (matrix[i][j] == 1) ? heights[j] + 1 : 0;
        }
        Rectangle rect = largestRectangleArea(heights, m, i);
        if (rect.area > maxRect.area) {
            maxRect = rect;
        }
    }

    free(heights);
    return maxRect;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        matrix[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    Rectangle maxRect = findLargestRectangleArea(matrix, n, m);
    printf("%d\n", maxRect.area);
    printf("(%d, %d)\n", maxRect.top, maxRect.left);
    printf("(%d, %d)\n", maxRect.bottom, maxRect.right);

    for (int i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
