#include <stdio.h>

int find_lower_area(int map[102][102], int x, int y, int w, int h) {
    if (map[x][y] > 0 || map[x][y] == -2 || map[x][y] == -1) {
        return 0;
    }
    map[x][y] = -1;
    return 1 + find_lower_area(map, x-1, y, w, h) + find_lower_area(map, x+1, y, w, h)
               + find_lower_area(map, x, y-1, w, h) + find_lower_area(map, x, y+1, w, h);
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int map[102][102];
    for (int i = 0; i < m+2; i++) {
        for (int j = 0; j < n+2; j++) {
            map[i][j] = -2;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int maxSize = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int size = find_lower_area(map, i, j, m, n);
            if (size > maxSize) {
                maxSize = size;
            }
        }
    }

    printf("%d\n", maxSize);
    return 0;
}
